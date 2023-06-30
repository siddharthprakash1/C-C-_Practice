/*
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
int main (){
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    printf("%d",head->data);

    
}*///creating the node

//creating a linked list
/*
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
int main (){
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    struct node *current=NULL;
    current=(struct node *)malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;
    //here to add the 3rd linked list u can do it like what u did before;
    //struct node *w=NULL;
    //w->data=12;
    //w->link=NULL;
    //current->link=w;
    //but in this process there is wastage of memory;
    struct node *current=NULL;
    current=(struct node*)malloc(sizeof(struct node*));
    current->data=3;
    current->link=NULL;
    head->link->link=current;
}*/


//========================================
//traversing a node 

/*

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void count_of_nodes(struct node *head){
    int count=0;
    if(head==NULL){
        printf("linked list is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr= ptr->link;
    }
    printf("%d\n",count);
}
void print_data(struct node *head){
     struct node * ptr1;
     ptr1=head;
     if(head==NULL){
        printf("the linked list is empty");  
     }
     while(ptr1!=NULL){
        printf("%d\n",ptr1->data);
        ptr1=ptr1->link;
     }
}
void add_at_end(struct node* head, int data ){
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link !=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
} //here the above code is correct but there is time complexity of 
int main(){
    struct node *head=head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    
    struct node *current=current=(struct node *)malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;
    
    current=(struct node*)malloc(sizeof(struct node*));
    current->data=90;
    current->link=NULL;
    head->link->link=current;


    count_of_nodes(head);
    print_data(head);
    add_at_end(head, 67);
    print_data(head);
}
*/

//========================================
//reduced time complexity:(for adding the node from end)
/*
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* add_at_end(struct node *ptr,int data){  //NOTE here the return type is a pointer not void
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    ptr->link=temp;//so here the ptr address changes from head to 
    return temp;
    //so every time we use this fn we are updating the value of ptr to the new location since we are returnin temp to ptr
}
int main(){
    struct node * head=(struct node*)malloc(sizeof(struct node*));
    head->data=45;
    head->link=NULL;
    //here u created a first node where head is  pointing to the 1st node
    struct node *ptr=head;
    ptr= add_at_end(ptr,98);//ptr contains the address of the last node of the list since we did return temp 
    //so every time we use this fn we are updating the value of ptr to the new location 
    ptr=add_at_end(ptr,11);
    ptr=add_at_end(ptr,9);
    ptr=add_at_end(ptr,2003);
    ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }

}
*/
//==============================================================================

//(pass by  value)adding node at the beginning method-1

/*
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node*add_at_beginning(struct node* head, int d){
    struct node *ptr= (struct node*)malloc(sizeof(struct node));
    ptr->data=d;
    ptr->link=NULL;
    
    ptr->link= head;
    head=ptr;
    return head;//here u return head since u have to update the changes of head in main fn, since the changes in head is local to this fn only 
} 
int main(){
struct node * head=(struct node*)malloc(sizeof(struct node*));
   head->data=45;
   head->link=NULL;
struct node* ptr=(struct node*)malloc(sizeof(struct node*));
    ptr->data=21;
    ptr->link=NULL;
    
    head->link=ptr;
    int data=3;
    head=add_at_beginning(head ,data);//here u r not passing head u r passing the copy of content of head thats why u have to update it everytime
    //here in head we r not passing the head , we r just passing the address of the 1st node
    //add_at_beginning(head ,data)- the head pointer here is 
    //this is pass by value not pass by refrence 
    ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
}
*/
//========================================
//(pass by refrence) insert node at beginnig

/* 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void add_at_beg(struct node**head, int d){
    struct node*ptr=malloc(sizeof(struct node));
    ptr->data=d;
    ptr->link=NULL;
    
    ptr->link=*head;
    *head=ptr;
}
int main ()
{
    struct node* head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node* ptr=malloc(sizeof(struct node));
    ptr->data=98;
    ptr->link=NULL;
    head->link=ptr;
    int data=3;
    add_at_beg(&head,data);
    ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
}*/

//========================================
//inserting the element when the position is given:

/*
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * link;
};
void add_at_beg(struct node**head,int data){
    struct node*ptr=malloc(sizeof(struct node*));
    ptr->data=data;
    ptr->link=NULL;

    ptr->link=*head;
    *head=ptr;

}
void add_at_end(struct node* head, int data){
    struct node* ptr,*temp;
    ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;

}
void add_at_pos(struct node* head, int data,int pos){
    struct node * ptr=head;
    struct node* ptr2=malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->link=NULL;
    
        pos--;
        while(pos!=1){
            ptr=ptr->link;
            pos--;
        }
        ptr2->link=ptr->link;
        ptr->link=ptr2;

}

void print_data(struct node *head){
     struct node * ptr1;
     ptr1=head;
     if(head==NULL){
        printf("the linked list is empty");  
     }
     while(ptr1!=NULL){
        printf("%d\t",ptr1->data);
        ptr1=ptr1->link;
     }
     printf("\n");
}

int main()
{
    struct node * head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    add_at_end(head,98);
    add_at_end(head,3);
    print_data(head);
    int data=3, position=3;
    add_at_pos(head,34,2);
    print_data(head);
}


*/
//========================================
//delete the 1st node:


/*
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * link;
};
void add_at_beg(struct node **head,int data){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    ptr->link=*head;
    *head=ptr;
}
void print_data(struct node * head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
struct node * del_first(struct node*head){
    if(head==NULL){
        printf("the list is empty");
    }
    else{
    struct node * temp=head;
    head=temp->link;
    free(temp);
    temp=NULL;
    }
    return head;
}
int main (){
    struct node * head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    add_at_beg(&head,98);
    print_data(head);
    add_at_beg(&head,43);
    print_data(head);
    head=del_first(head);
    print_data(head);

}*/

//========================================

//deleting the last node of the list 

/*
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
void add_data_end(struct node * head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    
    while(head->link!=NULL){
        head=head->link;
    }
    head->link=ptr;
}
void print_data(struct node * head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

void  del_data_end(struct node * head){
    if (head==NULL){
        printf("list is empty");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
    struct node * temp=head;
    struct node * temp2=head;
    while(temp->link!=NULL){
        temp2=temp;
        temp=temp->link;
    }
    temp2->link=NULL;
    free(temp);
    temp=NULL;
    }
}



int main(){
    struct node * head=malloc(sizeof(struct node));
    head->data=34;
    head->link=NULL;
    add_data_end(head,3);
    print_data(head);
    add_data_end(head,78);
    print_data(head);
    add_data_end(head,45);
    print_data(head);
    del_data_end(head);
    print_data(head);
    return 0;
}

*/
/*
using a single variable 

void  del_data_end(struct node * head){
    if (head==NULL){
        printf("list is empty");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
    struct node * temp=head;
    while (temp->link->link!=NULL)
    {
        temp=temp->link;
    }
    free(temp->link);
    temp->link=NULL;
    }
}

*/

//========================================

//deleting the node at a certain position
/*
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void add_data_end(struct node * head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    
    while(head->link!=NULL){
        head=head->link;
    }
    head->link=ptr;
}
void print_data(struct node * head){
    struct node * ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");

}
void del_at_any_pos(struct node * head, int pos){
    struct node* previous;
    struct node* current;
    previous=head;
    current=previous->link;
    int position=2;
    while(position!=pos){
        previous=previous->link;
        current=current->link;
        position++;
    }
    previous->link=current->link;
    free(current);
    current=NULL;

}
struct node * reverse(struct node *head){
    struct node * prev=NULL;
    struct node * next=NULL;
    while(head!=NULL){
    next=head->link;
    head->link=prev;
    prev=head;
    head=next;
    }
    head=prev;

}
int main(){
    struct node* head=malloc(sizeof(struct node));
    head->link=NULL;
    head->data=23;
    add_data_end(head,45);
    add_data_end(head,46);
    add_data_end(head,47);
    add_data_end(head,49);
    add_data_end(head,48);
    print_data(head);
    del_at_any_pos(head,3);
    print_data(head);
    head=reverse(head);
    print_data(head);
}

*/

//DOUBLY LINKED LIST 

/*
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node * next ;
};
int main(){
    struct node * head=malloc(sizeof(struct node));
    head->next=NULL;
    head->prev=NULL;
    head->data=30;

}
*/


/*
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node * next ;
};
struct node * addToEmpty(struct node * head, int data)
{
    struct node * temp = malloc(sizeof(struct node ));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void print_data(struct node *head){
    struct node * ptr=head;
    while(ptr!=NULL){
        printf("%d \t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node * insertion_btw(struct node * head, int data,int position ){
      struct node * temp=head;
      struct node * temp2= NULL;
      struct node * new=NULL;
      new=addToEmpty(new,data);
      int pos= position;

      while(pos>2){
        temp=temp->next;
        pos--;
      }

      temp2=temp->next;
      new->prev=temp;
      new->next=temp2;
      temp->next=new;
      temp2->prev=new;
      
      return head;
}
struct node * add_at_beg(struct node * head, int data )
{
    struct node * temp=malloc(sizeof(struct node ));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;

    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
int main()
{
    struct node * head=NULL;
    head= addToEmpty(head,45);
    head= add_at_beg(head,78);
    head= add_at_beg(head,23);
    head= add_at_beg(head,21);
    head= add_at_beg(head,31);
    head= insertion_btw(head,8,4);
    print_data(head);
    return 0 ;
}

*/
/*
#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node * next ;
    struct node * prev;
    int data ;
};
struct node * add_at_beg(struct node * head, int data )
{
    struct node * temp=malloc(sizeof(struct node ));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;

    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

struct node * add_to_Empty(struct node * head, int data){
    struct node * temp = malloc(sizeof(struct node ));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    head=temp;
    return head;
}
void print_data(struct node *head){
    struct node * ptr=head;
    while(ptr!=NULL){
        printf("%d \t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node * add_at_end(struct node * head ,int data ){
    struct node * temp, * tp;
    temp=malloc(sizeof(struct node));
    temp->next=NULL;
    temp->prev=NULL;
    temp->data=data;
    tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}
int main(){
    struct node * head=NULL;
    head=add_to_Empty(head,23);
    head=add_at_beg(head,34);
    print_data(head);
    head=add_at_end(head,89);
    print_data(head);
}
*/


//CIRCULAR SINGLY LINKED LIST 
/*
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node *addToEmpty(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;

}
struct node* addAtBeg(struct node * tail, int data){
    struct node* newP=malloc(sizeof(struct node*));
    newP->data=data;
    newP->next=NULL;
    newP->next=tail->next;
    tail->next=newP;
    return tail;
}
void print(struct node*tail)
{
    struct node* p=tail->next;
    do{
        printf("%d\t",p->data);
        p=p->next;
    }while(p!=tail->next);
    printf("\n");
}

struct node* addAtEnd(struct node* tail, int data){
    struct node* newP1=malloc(sizeof(struct node));
    newP1->data=data;
    newP1->next=NULL;
    
    newP1->next=tail->next;
    tail->next=newP1;
    tail=tail->next;

    return tail;
}

struct node* addAtPos(struct node * tail, int data,int pos)
{
    struct node * p= tail->next;
    struct node* newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=NULL;

    while(pos>1){
        pos--;
        p=p->next;
    }
    newP->next=p->next;
    p->next=newP;
    if(p==tail){
        tail=tail->next;
    }
    return tail;
}

struct node * createList(struct node* tail){
    int i,n,data;
    printf("Enter the number of nodes you want:");
    scanf("%d",&n);
    if(n==0){
        return tail;
    }    
    printf("Enter the element 1:");
    scanf("%d",&data);
    for(i=1;i<n;i++){
        printf("\nEnter the element %d:",i+1);
        scanf("%d",&data);
        tail=addAtEnd(tail,data);
    }
    return tail;
}

struct node* Delthe1stNode(struct node* tail){
    if(tail==NULL){
        return tail;
    }
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    struct node* temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    return tail;
}

struct node* delLast(struct node * tail){
    struct node*temp=tail->next;
    while(temp->next!= tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
}
struct node* delNodeAtPos(struct node* tail,int pos){
    struct node*temp=tail->next;
    while(pos>2){
        pos--;
        temp=temp->next;
    }
    struct node* temp2;
    temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    temp2=NULL;
    return tail;
}
int  search(struct node* tail, int element){
    int index=0;
    struct node * temp=tail->next;
    if(tail==NULL){
        return -2;
    }
    do{
        if(temp->data == element){
            return index;
        }
        temp=temp->next;
        index++;
    }while(temp!=tail->next);
    return -1;//if the number doesnot exist then 
}


int main(){
    
    struct node* tail;
    int element;
    tail=addToEmpty(34);
    tail=addAtBeg(tail,23);
    tail=addAtBeg(tail,25);
    tail=addAtEnd(tail,67);
    tail=addAtPos(tail,19,3);
    print(tail);
    //tail=createList(tail);
    tail=Delthe1stNode(tail);
    print(tail);
    tail=delLast(tail);
    print(tail);
    tail=addAtEnd(tail,69);
    tail=addAtEnd(tail,20);
    tail=delNodeAtPos(tail,3);
    print(tail);
    printf("Enter the element: ");
    scanf("%d",&element);
    int index= search(tail,element);
    if(index==-1)
        printf("element not found");
    else if(index==-2){
        printf("Linkedlist is empty");
    }
    else
        printf("Element %d is at index at %d",element,index);

    return 0;
}
*/
//Circlular Doubly linked list

/*
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node * prev;
    int data;
    struct node * next;
};
struct node* addToEmpty(int data){
    struct node * temp=malloc(sizeof(struct node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct node* addAtBeg(struct node* tail, int data){
    struct node * newp=addToEmpty(data);
    if(tail==NULL){
        return newp;
    }
    else{
        struct node * temp=tail->next;
        newp->prev=tail;
        newp->next=temp;
        temp->prev=newp;
        tail->next=newp;
        return tail;
    }
}
struct node * AddAtEnd(struct node * tail, int data){
    struct node * newp= addToEmpty(data);
    if (tail==NULL){
        return newp;
    }
    else{
        struct node * temp= tail->next;
        newp->next=temp;
        newp->prev=tail;
        tail->next=newp;
        temp->prev=newp;
        tail=newp;
        return tail;
    }
}
struct node * addAtPos(struct node * tail, int data, int pos){
    struct node * newp= addToEmpty(data);
    if (tail==NULL){
        return newp;
    }
    else{
        struct node * temp=tail->next;
        while(pos>1){
            temp=temp->next;
            pos--;
        } 
        newp->next=temp->next;
        newp->prev=temp;
        temp->next->prev=newp;
        temp->next=newp;
        if(temp==tail){
            tail=tail->next;
        }
        return tail;
    }
}

struct node * DeleteAtBeg(struct node * tail){
    if(tail==NULL){
        return tail;
    }
    struct node * temp= tail->next;
    if (temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    tail->next=temp->next;
    temp->next->prev=tail;
    free(temp);
    return tail;
}

struct node * delAtEnd(struct node * tail){
    struct node * temp;
    if (tail==NULL){
        return tail;
    }
    if(temp==tail){
        free(tail);
        tail=NULL;
        return temp;
    }
    temp=tail->prev;
    temp->next=tail->next;
    tail->next->prev=temp;
    free(temp);
    tail=temp; 
    return tail;
}
struct node* delAtpos(struct node* tail, int pos){
    struct node * temp=tail->next;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    struct node* temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    if (temp==tail)
        tail==temp2;
    return tail;
}
void print(struct node *tail){
    if(tail==NULL){
        printf("NO ELEMENT");
    }
    else {
        struct node * temp= tail->next;
        do{
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp != tail->next);
        }
        printf("\n");
}
int main(){
    struct node * tail=NULL;
    tail=addToEmpty(45);
    tail=addAtBeg(tail,23);
    print(tail);
    tail=AddAtEnd(tail,99);
    print(tail);
    tail=AddAtEnd(tail,27);
    tail=addAtPos(tail,69,1);
    print(tail);
    //tail=DeleteAtBeg(tail);
    //print(tail);
    //tail=delAtEnd(tail);
    //print(tail);
    //tail=AddAtEnd(tail,11);
    //tail=AddAtEnd(tail,9);
    //print(tail);
    tail=delAtpos(tail,2);
    print(tail);
    return 0;
}
*/

//inserting in an sorted singly linked list
/*
struct node * temp=head;
int key=newP->data;//the pointer to be inserted
if(head==NULL || key< head->data){
    newp->link=head;
    head=newp;
}
else{
while(temp->link!=NULL && temp->data<key){
    temp=temp->link;
}
newp->link=temp->link;
temp->link=newp;
}

//##ascending order here 
*/

//POLYNOMIAL
/*
#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node* link;
    float coeff;
    int expo;
};
struct node* insert(struct node * head, float co , int ex){
    struct node * temp;
    struct node * newp=malloc(sizeof(struct node ));
    newp->coeff=co;
    newp->expo=ex;
    newp->link=NULL;

    if(head==NULL || ex>head->expo){
        newp->link=head;
        head=newp;
    }//this case is when the node gets inserted 1st

    else
    {
        temp=head;
        while(temp->link != NULL && temp->expo>ex){
            temp=temp->link;
        }
        newp->link=temp->link;
        temp->link=newp;
    }
    return head;
}

struct node * create(struct node * head){
    int n, i ;
    float coeff;
    int expo;
    printf("enter the number of terms:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("enter the coeffecient for the term: %d", i+1);
    scanf("%f",&coeff);
    printf("enter the exponent for the term: %d",i+1);
    scanf("%d",&expo);
    head= insert(head, coeff, expo);
    }
    return head;
}



void print(struct node * head){
    if(head==NULL){
        printf("no polynomial");
    }
    else{
        struct node * temp=head;
        while(temp!=NULL){
            printf("(%.1fx^%d)",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }
    }
}

void polyAdd(struct node* head1, struct node* head2){
    struct node * ptr1=head1;
    struct node * ptr2=head2;
    struct node * head3=NULL;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->expo == ptr2->expo){
            head3= insert(head3, ptr1->coeff + ptr2->coeff,ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if (ptr1->expo > ptr2->expo){
            head3=insert(head3, ptr1->coeff,ptr1->expo);
            ptr1=ptr1->link;
        }
        else if (ptr1->expo < ptr2->expo){
            head3=insert(head3, ptr2->coeff,ptr2->expo);
            ptr2=ptr2->link;
        }
    }
    while(ptr1 != NULL){
        head3=insert(head3,ptr1->coeff,ptr1->expo);
        ptr1= ptr1->link;
    }
    while(ptr2 != NULL){
        head3=insert(head3,ptr2->coeff,ptr2->expo);
        ptr2= ptr2->link;
    }
    printf("added polynomial is:");
    print(head3);
}

int main(){
    struct node * head1= NULL;
    struct node * head2=NULL;
    printf("Enter the polynomial\n");
    head1= create(head1);
    print(head1);
    printf("Enter the polynomial\n");
    head2=create(head2);
    print(head2);
    polyAdd(head1,head2);
    return 0 ;
}
*/



