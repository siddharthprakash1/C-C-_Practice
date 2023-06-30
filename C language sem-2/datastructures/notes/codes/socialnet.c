#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
    struct node *t = users;
    if(t!=NULL)
    {
        while(t!=NULL)
        {
            if(t->id==key)
            {
                return t;
            }
            else if(t->id>key)
            {
                t=t->left;
            }
            else if(t->id<key)
            {
                t=t->right;
            }
        }
    }
    return t;
}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    user->left = NULL;
    user->right = NULL;
    if(users==NULL)
    {
        user->numfren = 0;
        user->friends[0] = -1;
    }
    else
    {
        struct node *t = search(user->id,users);
        if(t!=NULL)
        {
            while(1)
            {
                user->id++;
                struct node *temp = search(user->id,users);
                if(temp==NULL)
                {
                    break;
                }
            }
        }
    }
    for(int i=0;i<user->numfren;i++)
    {
        int val = user->friends[i];
        struct node *t = search(val,users);
        if(t==NULL)
        {
            user->friends[i] = -1; 
        }
        else
        {
            t->friends[t->numfren] = user->id;//check
            t->numfren+=1;
        }
    }
    int c=0;
    while(c<user->numfren)
    {
        if(user->friends[c]==-1)
        {
            for(int i=c;i<user->numfren;i++)
            {
                user->friends[i] = user->friends[i+1];
            }
            user->numfren--;
        }
        else
        {
            c++;
        }
    }
    return user;
}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
   if(root==NULL)
   {
    root = user;
   }
   else if(id < root->id)
   {
        root->left = insertUser(root->left,id,user);  
   }
   else if(id > root->id)
   {
        root->right = insertUser(root->right,id,user);  
   }
   return root;
}

//prints friends list
void friends(int id, struct node *users) 
{
   struct node *t= search(id,users);
   if(t->numfren == 0)
   {
        printf("%d\n",(-1));
   }
   else
   {
        for(int i=0;i<t->numfren;i++)
        {
            printf("%d\n",t->friends[i]);
        }
   }
}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) 
{
    struct node *val;
    val = node->right;
    while(val->left!=NULL)
    {
        val = val->left;
    }
    return val;
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    struct node *t1 = search(key,users);
    if(t1!=NULL)
    {
        for(int i=0;i<t1->numfren;i++)
        {
            int copy = t1->friends[i];
            struct node *t2 = search(copy,users);
            for(int j=0;j<t2->numfren;j++)
            {
                if(t2->friends[j]==key)
                {
                    for(int k=j;k<t2->numfren;k++)
                    {
                        t2->friends[k] = t2->friends[k+1];
                    }
                    t2->numfren=t2->numfren-1;
                }
            }
            if(t2->numfren==0)
            {
                t2->friends[0]==-1;
            }
        }
    }
}

void search_parent(struct node **t,int key,struct node **parent)
{
    while((*t)!=NULL && (*t)->id!=key)
    {
        *parent = *t;
        if(key<(*t)->id)
        {
            *t = (*t)->left;
        }
        else
        {
            *t = (*t)->right;
        }
    }
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) 
{
    if(root==NULL)
    {
        return root;
    }
    struct node *t = root;
    struct node *parent = NULL;
    search_parent(&t,key,&parent);
    if(t->left==NULL && t->right==NULL)
    {
        if(parent==NULL)
        {
            root = NULL;
        }
        else if(parent->left==t)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        free(t);
    }
    else if(t->left==NULL || t->right == NULL)
    {
        if(parent==NULL)
        {
            if(t->left!=NULL)
            {
                root = root->left;
            }
            else 
            {
                root = root->right;
            }
        }
        else if(parent->left == t)
        {
            if(t->left != NULL)
            {
                parent->left = t->left;
            }
            else
            {
                parent->left = t->right;
            }
        }
        else if(parent->right == t)
        {
            if(t->left != NULL)
            {
                parent->right = t->left;
            }
            else
            {
                parent->right = t->right;
            }
        }
        free(t);
    }
    else
    {
        struct node *temp = minValueNode(t);
        int id_copy = temp->id;
        int numfren_copy = temp->numfren;
        char name_copy[MAX];
        strcpy(name_copy,temp->name);
        int friends_copy[MAX];
        for(int i=0;i<temp->numfren;i++)
        {
            t->friends[i] = friends_copy[i];
        }
        root = deleteNode(root,temp->id);
        t->id = id_copy;
        t->numfren = numfren_copy;
        strcpy(t->name, name_copy);
        for(int i=0;i<numfren_copy;i++)
        {
            t->friends[i] = friends_copy[i];
        }
    }
    return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    if(myusers==NULL)
    {
        return;
    }
    else
    {
        if(myusers->left!=NULL)
        {
            printInOrder(myusers->left);
        }
        printf("%d %s\n",myusers->id,myusers->name);
        if(myusers->right!=NULL)
        {
            printInOrder(myusers->right);
        }
    }
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