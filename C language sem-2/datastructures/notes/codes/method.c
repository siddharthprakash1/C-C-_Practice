


//doubly linked list 
/*
#include<stdio.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* createnode(int no)
{
    struct node* newnode;

    // we can start the allocation 
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = no;

    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
};

static int cnt=0;  // declaring cnt as a global variable 

struct node* insert_beginning(int no,struct node* head)
{
    struct node* newnode; // declaring the pointer

    newnode = createnode(no);      
    // over here we are creating at new node // and returning address at new node

    newnode->next = head ; // new node points to head
    head->prev = newnode;  

    head = newnode;   
    // making the node (which is inserted at beginning ) as 1st node or head
    
    cnt++;


    return head;
};


struct node* insert_middle(int pos,int no,struct node* head)
{
    struct node* newnode , *t1; // temporary pointer t1 is created
    newnode = createnode(no);

    if(pos<1 || pos>cnt)
    {
        printf("Invalid position ");
    }

    else if(pos == 1)
    {
        head = insert_beginning(no,head);
    }

    else 
    {
        t1 = head;

        for(int i = 1; i<pos-1 ; i++)
        {
            t1=t1->next;
        }

        newnode->next=t1->next;
        newnode->prev=t1;
        // t1->next->prev=newnode;
        t1->next=newnode;
        t1->next->prev=newnode;
    }

    cnt++;   // incrementing the counter variable 

    return head; 
}

struct node* insert_end(int no,struct node* last)
{
    struct node* newnode; // declared and created new node
    newnode=createnode(no);

    last->next=newnode;
    newnode->prev=last;
    last=last->next;

    cnt++;

    return last;
}
struct node* delete_beginning(struct node *head)
{
    struct node* t1;

    t1=head;
    head=head->next;
    t1->next=NULL;
    head->prev=NULL;
    free(t1);

    cnt-- ;
    return head;
}

struct node* delete_middle(int pos, struct node* head)
{
    struct node *t1,*t2;
    if(pos<2 || pos>=cnt )
    {
        printf("invalid position");
    }

    else
    {
        t1=head;

        for(int i = 1;i<=pos-1 ; i++)
        {
            t1 = t1->next;
        }

        t2=t1->next;
        t1->next = t2->next;
        t2->next->prev = t1;
        t2->prev = NULL;
        t2->next = NULL;
        
        cnt-- ;

        free(t2);
    }
}

struct node* delete_end(struct node* last)
{
    struct node* t1;
    t1 = last;
    last = last->prev ; 
    last->next = NULL;
    t1->prev = NULL;

    free(t1);

    cnt--;

    return last;
} 

void display(struct node* head , struct node* last)
{
    if(head!=NULL)
    {
        struct node* t1;
        t1 = head;
        
        printf("%d<->\n",t1->data);
        
        while(t1!=last)
        {
            t1=t1->next;
            printf("%d<->\n",t1->data);
        }
        printf("NULL");
    }

    else
    {
        printf("List is empty");
    }
}

struct node* reverse(struct node* head)
{
    struct node *t1;
    
    // to check if there is only 1 node 
    // if there is only 1 node then we don't need to do anything 
    if (head->next!=NULL)    
    {
        t1 = head;
        
        while(t1->next!=NULL)
        {
            t1=t1->next;
        }
        
        head = t1;

        t1=swap(t1);

        while(t1->next!=NULL)
        {
            t1=t1->next;
            t1=swap(t1);
        }

        return head;
    }
}

struct node* swap(struct node* t)
{
    struct node* temp;

    temp=t->next;
    t->next=t->prev;
    t->prev=temp;
    
}*/
