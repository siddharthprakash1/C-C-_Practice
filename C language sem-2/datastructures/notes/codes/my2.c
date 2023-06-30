#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define MAX 100

typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}


//search for user with id=key
struct node* search(int key, struct node *users)
{
    if(users==NULL || users->id==key)
    {
        return users;
    }   
    if(key<users->id)
        return(search(key,users->left));
    return(search(key,users->right));
}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    int n = -8;
    int x = user->numfren;
    node* temp;
    while(1)
    {
        temp = search(user->id,users);
        if(temp != NULL)
        {
            ++(user->id);
        }   
        else
        {
            break;
        }   
    }
    node *key;
    int i,j,k;
    for(i=0;i<x;i++)
    {
        if(search(user->friends[i],users) == NULL)
        {
            user->friends[i] = n;
            user->numfren--;
        }
        else
        {
            key = search(user->friends[i],users);
            key->friends[key->numfren] = user->id;
            ++(key->numfren);
        }
    }
    for(j=0;j<x;j++)
    {
        if(user->friends[j] == n)
        {
            
            for(k=j;k<x;k++)
                user->friends[k] = user->friends[k+1]; 
        }
    }
    int a = -1;
    if(user->numfren==0)
    {
        user->friends[user->numfren] = a;
    }
    return user;
}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
    user->id = id;
    if(root == NULL)
    {
        root = user;
        return root;
    }
    node* curr = root;
    node* pre = NULL;
    while(curr != NULL)
    {
        pre = curr;
        if(id < curr->id)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if(id < pre->id)
        pre->left = user;
    else
        pre->right = user;
    return root;
}

//prints friends list
void friends(int id, struct node *users) 
{
    int i;
    node* temp = search(id,users);
    if(temp == NULL)
        return;
    if(temp->numfren == 0)
        printf("-1\n");
    else
    {
        for(i=0;i<temp->numfren;i++)
        {
            printf("%d\n",temp->friends[i]);
        }
    }

}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) {
    struct node* temp = node;
    while(temp->left!=NULL)
        temp = temp->left;
    return temp;
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    node *u1=NULL;
    node *u2=NULL;
    int i,j,k;
    u1=search(key,users);
    if (u1==NULL)
        return u1;
    int a=-1,b=-9;
    for(i=0;i<u1->numfren;i++)
    {
        u2=search(u1->friends[i],users);
        if (u2!=NULL)
            for(j=0;j<u2->numfren;j++)
                if(u2->friends[j]==u1->id)
                    u2->friends[j]=b;  
    }
    for(i=0;i<u1->numfren;i++)
    {
        u2=search(u1->friends[i],users);
        if (u2!=NULL)
        {
            for(j=0;j<u2->numfren;j++)
                if(u2->friends[j]==b)
                {
                    for (k=j; k<u1->numfren; k++)
                        u2->friends[k]=u2->friends[k+1];
                    u2->numfren--;
                }
            if(u2->numfren == 0)  
                u2->friends[u2->numfren] = a;
        }
    }
    return u1;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root==NULL)
        return root;
    if(key<root->id)
        root->left = deleteNode(root->left,key);
    else if(key>root->id)
        root->right = deleteNode(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* min = minValueNode(root->right);
        root->id = min->id;
        strcpy(root->name,min->name);
        root->right = deleteNode(root->right,min->id);
    }
    return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    if(myusers==NULL)
        return;
    printInOrder(myusers->left);
    printf("%d %s\n",myusers->id,myusers->name);
    printInOrder(myusers->right);
}


int main(int argc, char **argv)
{
    node *users=NULL;   
    while(1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                scanf("%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:
           
                scanf("%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                break;

            case 3:
        
                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input! \n");
                break;
        }

    }
    return 0;
}