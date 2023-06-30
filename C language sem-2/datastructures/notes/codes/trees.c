//ARRAY IMPLIMENTATION
/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 10 //since array is a static storage we have to define the max storage before hand

char tree[MAX];

void root(char);//adds the root 
void left(char,int);//adds left child
void right(char,int);//adds the right child
void print();//prints the data 

void root(char c){
    if (tree[0] !='\0'){
        printf("\nroot already exists\n");
    }
    else 
        tree[0]=c;
}
void left(char c,int parent){
    if(tree[parent]=='\0'){
        printf("\nparent does not exist\n");
    }
    else
        tree[2*(parent)+1]=c;
}
void right(char c,int parent){
    if(tree[parent]=='\0'){
        printf("\nthe parent doesnot exist\n");
    }
    else
    tree[(parent*2)+2]=c;
}
void print(){
    int i;
    for(i=0;i<MAX;i++){
        if(tree[i]=='\0'){
            printf("*");
        }
        printf("%c",tree[i]);
    } 
    printf("\n");
}
int main (){
    root('A'); 
    left('B',0);
    right('C',0);
    left('D',1); 
    right('E',1);
    left('G',2);
    right('H',2);
    print();
    return 0;
}

*/

//LINKED LIST IMPLIMENTATION
//here the code is not working so check it 
/*
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node * left ;
    int data;
    struct node * right;
};

struct node * creatTree();
int isFullBinaryTree(struct node*);
int isFullBinaryTree(struct node * root){
        if(root==NULL){
            return 1;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        if(root->left && root->right){
            int left=isFullBinaryTree(root->left);
            int right=isFullBinaryTree(root->right);
            return (left&&right);
        }
        return 0;
    }

int main(){
    struct node * root= creatTree();
    printf("%d\n",root->data);
    printf("%d\n",root->left->data);
    printf("%d\n",root->right->data);
    if(isFullBinaryTree(root))
        printf("the given Binary tree is not a full Binary tree.\n");
    else
        printf("the given binary tree is not a full binary tree");
    return 0;
}

struct node* creatTree()
{
    int input,data;
    printf("Do you wanna add a node?(0 for no and 1 for yes)");
    scanf("%d",&input);
    if(!input){
        return NULL;
    }
    else
    {
        struct node* newnode=malloc(sizeof(struct node));
        printf("enter the data");
        scanf("%d",&data);
        newnode->data=data;
        printf("Left child of tree %d\n",newnode->data);
        newnode->left=creatTree();
        printf("Right child of Tree %d \n",newnode->data);
        newnode->right=creatTree();
        return newnode;
    }
}
*/
 
//Deletion of a node in Binary Search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;
NODE* createnode(int data)
{
    NODE *nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
int isempty(NODE *t)
{
    return (t==NULL);
}

NODE* insertNode(NODE *root,int data)
{
    if(isempty(root))
        root=createnode(data);
    else if(data<=root->data)
        root->left=insertNode(root->left,data);
    else
        root->right=insertNode(root->right,data);
    return root;
}

void preorder(NODE *t)
{
    if(isempty(t))
        printf("Tree ie empty");
    else{
        printf("%d ",t->data); //v
        if(t->left!=NULL)
            preorder(t->left); //L
        if(t->right!=NULL)
            preorder(t->right);//R
    }

}
void inorder(NODE *t)
{
    if(isempty(t))
        printf("Tree ie empty");
    else{

        if(t->left!=NULL)
            inorder(t->left); //L
        printf("%d ",t->data); //v
        if(t->right!=NULL)
            inorder(t->right);//R
    }
}
void postorder(NODE *t)
{
    if(isempty(t))
        printf("Tree ie empty");
    else{

        if(t->left!=NULL)
            postorder(t->left); //L
        if(t->right!=NULL)
            postorder(t->right);//R
         printf("%d ",t->data); //v
    }
}
void searchNode(NODE **t,int data,NODE **parent)
{
    while((*t)->data!=data && *t!=NULL)
    {
        *parent=*t;
        if(data<=(*t)->data)
                *t=(*t)->left;
        else
            *t=(*t)->right;
    }
}
NODE* inordersuccessor(NODE* t)
{
    NODE *s=t;
    if(s->right!=NULL)
        s=s->right;
    while(s->left!=NULL)
        s=s->left;
    return s;
}
NODE* deleteNode(NODE *root,int data)
{
    NODE *t=root, *parent=NULL;
    if(data!=t->data)
        searchNode(&t,data,&parent);
    if(t==NULL)
    {
        printf("Data not found");
        return root;
    }
    //case 1:Leaf Node
    if(t->left==NULL && t->right==NULL)
    {
        if(parent==NULL)//root node
            root=NULL;
        else if(parent->left==t)//left child
            parent->left=NULL;
        else                    //right child
            parent->right=NULL;
        free(t);
    }
    //case 2:One child Node
    else if(t->left==NULL || t->right==NULL)
    {
        if(parent==NULL)//root
        {
            if(t->left!=NULL)//left child
            {
                root=root->left;
                t->left=NULL;//optional
            }
            else
            {
              root=root->right;
              t->right=NULL;//optional
            }
        }
        else
        {
            if(parent->left==t)//left child of parent
            {
                if(t->left!=NULL)
                    parent->left=t->left;
                else
                    parent->left=t->right;
            }
            else
            {
                if(t->left!=NULL)
                    parent->right=t->left;
                else
                    parent->right=t->right;
            }
        }
        free(t);
    }
    else //case 3:Two node condition
    {
        NODE *s;
        int val;
        s=inordersuccessor(t);
        val=s->data;
        root=deleteNode(root,s->data);
        t->data=val;
    }
return root;
}
int main()
{
    int n,d,ch;
    NODE *root=NULL;
    printf("\nEnter the no of nodes");
    scanf("%d",&n);
    printf("\nEnter the data");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d);
        root=insertNode(root,d);
    }
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    //Deletion
    do{
    printf("\nEnter the data to be deleted");
    scanf("%d",&d);
    root=deleteNode(root,d);
    printf("\n");
    preorder(root);
    printf("\nTo Continue press 1");
    scanf("%d",&ch);
    }while(ch);

}
