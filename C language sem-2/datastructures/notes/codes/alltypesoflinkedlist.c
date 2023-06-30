/*
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *address;
};

struct node *head;

void front_insert(int x){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->address = head;
	head = temp;
	printf("Inserted %d at the front\n", x);
}

void rear_insert(int x){
	struct node* newnode  = (struct node*)malloc(sizeof(struct node));
	struct node* temp;
	temp = head;
	newnode->data = x;
	newnode-> address  = NULL;
	while(temp->address!=NULL)
		temp = temp->address;
	temp->address = newnode;
	printf("Inserted %d at the rear\n", x);
}

void insert_here(int x, int  pos){
	int c = 0, i = 0;
	struct node* temp;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while(temp->address != NULL){
		temp = temp->address;
		c++;
	}
	if(pos==0)
		front_insert(x);
	else if(pos==c)
		rear_insert(x);
	else if(pos>c)
		printf("higher than limit\n");
	else{
		temp = head;
		while(i!=pos){
			temp = temp->address;
            i++;
		}
		struct node* temp1 = temp->address; 
		newnode->data = x;
		temp->address = newnode;
		newnode->address = temp1;
		printf("Inserted %d at %d\n",x,pos);
	}
}

void pop(){
	struct node* temp =  head;
	struct node* temp1 = head;
	temp = temp->address;
	while(temp->address!=NULL){
		temp = temp->address;
	    temp1 = temp1->address;
	}
	int a = temp->data;
	free(temp);
	temp1->address = NULL;
	printf("popped %d\n", a);
}

int get_size(){
	int count=0;
	struct node* new  = head;
	while(new!=NULL){
		new = new->address;
		count++;
	}
	return count;
}

void display(){
	struct node* temp;
	temp = head;
	while (temp!= NULL){
		printf("%d\n", temp->data);
		temp = temp->address;
	}
}

void reverse(){
    printf("______REVERSED_______\n");
	struct node* next = NULL;
	struct node* prev = NULL;
	struct node* current = head;
	while(current!=NULL){
	    next = current->address; printf("%d   ", next->data);
	    current->address  = prev;
	    prev = current; printf("%d   ", prev->data);
	    current = next; printf("%d\n", current->data);
	}
	head = prev;
}

void sort(){
	struct node *current= head;
	struct node *next;
	int temp;
	int size = get_size();
	int k = size;
	for ( int i = 1; i < size; i++, k-- ) {
      current = head;
      next = head->address;
		
      for (int j = 1 ; j < size ; j++ ) {   

         if ( current->data > next->data ) {
            temp = current->data;
            current->data = next->data;
            next->data = temp;
         }
			
         current = current->address;
         next = next->address;
      }
   }   
}

void main(){
	head = NULL;
	front_insert(1);
	front_insert(2);
	front_insert(5);
	rear_insert(3);
	rear_insert(6);
	insert_here(4,2);
	display();
	reverse();
	display();
	printf("----\n");
	sort();
	display();

}*/
/*

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    
}*head = NULL;
struct node *t1 , *t2;

void create();
void insert();
void delete1();
void display();

void create()
{
    if (head == NULL)
    {
        int no;
        printf("enter the 1st element");
        scanf("%d",&no);

        head = (struct node*)malloc(sizeof(struct node));
        head -> data = no;
        head -> next = NULL;
    }

    else 
    {
        printf("list already exists ");
    }
}

void insert()
{
    // switch case for where to insert 

    int ch;
    printf("enter your choice: \n 1.Insert at beginning \n 2. Insert at end \n 3. Insert at middle \n");
    scanf("%d\n",&ch);

    //for reading the data 
    int no;
    printf("enter the data to be stored \n");
    scanf("%d\n",&no);

    switch(ch)
    {
        case 1: // inserting at beginning
        {
            // when ever u are inserting . 1st we need to check whether list is empy or not 

            // 1st we will create a  node and then point to the head of node 
            // and we repoint the head pointer to the new 1st node 

            // allocating memory for new node 
            t1 = (struct node*)malloc(sizeof(struct node));

            // giving data to the 1st node 
            t1 -> data = no;
            t1 -> next = head;

            // repointing the head 
            head = t1 ; 
            break;
        }

        case 2: // inserting at end 
        {
            t1 = (struct node*)malloc(sizeof(struct node)); 

            t1->data = no;
            t1->next = NULL;

            t2 = head;

            // so we only have info abt the head so we will traverse till the end 
            // and reach the last node . And then add node at end.

            while(t2->next != NULL)
            {
                t2 = t2->next ; 
            }
            t2->next = t1;
            break;
        }

        case 3: // inserting in middle 
        {
            // to get the position from the user 

            int pos;
            printf("enter the position to be entered \n");
            scanf("%d\n",&pos);

            t1 = (struct node*)malloc(sizeof(struct node)); 

            t1 -> data = no;
            
            if(pos==1) // insertion at middle -- pos = 1 means inserting at the beginning 
            {
                t1->next  = head;
                head = t1;
            }
            else
            {
                for(int i = 1; i<pos-1 ; i++)  
                {
                   // this is use to check the if we have reached the end or not 
                   // in case user types a no greater the length of the list then 
                  // then that element needs to be inserted at the end 

                    if(t2 ->next!=NULL)    
                    {                      
                        t2 = t2->next;     
                    } 
                    else
                    {
                        printf("inserted at end since reached of the list is inseted ");
                        break ; 
                    }
                }
                t1 -> next = t2->next;
                t2->next = t1;           
                break;
            }
        }
    }
}

void delete1()
{
    // 1st we need to check whether the list is empty // hence deletion not possible 

    // one node condition i.e length of string is 1 then in that case we will just point head to null 
    // for checking if there is only one node in that case we will check if next of of node is null or not

    if(head == NULL) 
    {
        printf("Deletion not possible");
    } 

    else if (head -> next == NULL)
    {
        t1 - head;
        head = NULL;
        free(t1);      // before deleting we will free thta memory 
    }
    else
    {
        printf("enter the choice 1. Delete at beginning \n2 .Delete at the end\n3. Delete in the middle ");

        int ch;
        scanf("%d \n",&ch);

        switch(ch)
        {
            case 1:
            {
                t1 = head; // temporary pointer is pointing to the 1st node i.e head

                head = head ->next ; 
                // over here we are deleting at the beggining so we are making the 2nd node as the 1st node 
                // hence head is t1(i.e 1st node) -> next 

                t1 -> next = NULL ;   
            // even if don't give this line of code there is no prob in execution 
            // but over here t1 will point at garabage value 
            // so its a good practice is to 1st delink and and then free the memory 

            // now we are breaking the link between the previous 1st node(i.e t1) and 
            // new head(or previous 2nd node )

                free(t1);
                // now we will free memeory space of t1 or previous 1st node or initial 1st node
            }

            case 2:
            {
                t1 = head;

                while(t1->next->next != NULL)  // t1->next->next for obtaining the 2nd last element 
                {
                    t1 = t1 ->next;
                }

                t2 = t1 -> next;      // t2 - last element and t1 - 2nd last element 
                t1 -> next = NULL ;     // making 2nd last element the last element 
                free(t2);              // deleting the last element 
 
                break;

            }

            case 3:
            {
                printf("enter the position to be deleted \n");

                int pos,flag = 1;   // we can use flag as anything other than zero 
                scanf("%d \n",&pos);

                if(pos == 1) // for deleting code at beginning 
                {
                    head = head -> next;
                    t1 -> next = NULL ;
                    free(t1);
                }

                else
                {
                    for(int i = 1 ; i< pos-1 ; i++)
                    {
                        if(t1->next!= NULL) // to check if its not beyond the no of elements in the list 
                        {
                            t1 = t1->next;
                        }

//in case the no of elements in the list is 5 and the user enters the 7th element to be deleted then in that
// case ; after executing the above if loop then reaching the end the pointer(i.e t1) will point to null
// but still the for loop will execute as pos = 7 ; so after t1 becoming null the next for loop will enter 
// the else loop as t1 has become null ; now the flag value is changed so the it will break the loop   
                        else  
                        {
                            flag = 0; 
                            break;
                            // return 
// we can use return instead of flag thing as the type is void delete1() so if we return it will move out the 
// program as deletion is not possible as there are only 5 elements not 7(i.e pos = position given by user)
                        } 
                    }
// if position given by user is less than or equal to the no of elements in the list then it won't enter the 
// else loop and hence the flag value won't change 

// therefore the below code will work // where deletion takes place.
                    if(flag)
                    {
                        t2 = t1 -> next;     // t2 = node to be deleted ; t1 = node previous to t1 
                        t1 -> next = t2 -> next;  // hence t1 will point to node next to t2 
                        t2 -> next = NULL ;     // t2 will become null 

                        free(t2);   // freeing the memory 


                    }
                }
                break ;
            }
        }
    }

}
void display(){
	if(head==NULL){
		printf("List is empty");
	}
	else{
		t1=head;
		printf("%d->",t1->data);
		while(t1->next!=NULL){
			t1=t1->next;
			printf("%d->",t1->data);
		}
		printf("NULL");
	}
}
int main()
{
	int ch;
	printf("enter your choice\n1.create\n2.insert\n3.delte\4.display");	
	scanf("%d",&ch);
	switch (ch)
	{
	case 1:
		create();
		display();
		break;
	case 2:
		insert();
		display();
		break;
	case 3:
		delete1();
		display();
		break;
	case 4:
		display();
		break;
	}
}*/
//dlly linked list
/*
#include<stdio.h>
#include<stdlib.h>

#include"method.c"

int main()
{

    struct node *head=NULL,*last=NULL;  

    int no;
    int pos;
    int ch;
    int cnt;

    printf("Enter your choice \n1. Creation \n 2. Insertion at beginning \n3. Insertion at middle \n4. Insertion at the end \n5. Deletion at beginning \n6. Deletion at middle \n7. Deletion at the end \n8. Display \n9. Reverse the list");

    scanf("%d",&ch);

    switch (ch)
    {
        case 1:  // create 
        {
            if(head==NULL)  
            {
                // newnode = (struct node*)malloc(sizeof(struct node)); 
                // above code is not efficient 

                printf("enter the 1st element\n");
                scanf("%d",&no);
                head = createnode(no); 
                cnt++;
                // data is passed i.e is no is passed to func
                // returning address to head i.e func. createnode() return address to head  
            }
            else
            {
                printf("list already exists");
            }

            display(head,last);
            
            break;

        }

        case 2: // insert at beginning 
        {
            if(head == NULL)
            {
                printf("enter the 1st element\n");
                scanf("%d",&no);
                head = createnode(no);
            }
            else
            {
                printf("enter the element to be inserted \n");
                scanf("%d",&no);
                head = insert_beginning(no,head);
            }

            display(head,last);

            break;
           
        }

        case 3: // insert -  middle 
        {
            if(head == NULL)
            {
                printf("enter the 1st element\n");
                scanf("%d",&no);
                head = createnode(no);
            }

            else 
            {
                printf("enter the element to be inserted \n");
                scanf("%d",&no);
                printf("enter the position of the element\n");
                scanf("%d",&pos);
                head = insert_middle(pos,no,head);
            }  

            display(head,last);

            break;    
            
        }

        case 4: // insert - end 
        {
            if(head == NULL)
            {
                printf("enter the 1st element\n");
                scanf("%d",&no);
                head = createnode(no);
            }

            else 
            {
                insert_end(no,last);
            }

            display(head,last);

            break;
        }

        case 5: // delete - start 
        {
            if(head == NULL)
            {
                printf("List doesn't exist\n");
            }

            else if(head->next == NULL)
            {
                head = NULL;
                last = NULL;        
            }

            else
            {
                head = delete_beginning(head);
            }

            display(head,last);

            break;
        }

        case 6: // delete - middle 
        {
            if(head == NULL)
            {
                printf("List doesn't exist\n");
            }

            else if(head->next == NULL)
            {
                head = NULL;
                last = NULL;        
            }

            else
            {
                delete_middle(pos,head);
            }

            display(head,last);

            break;
            
        }

        case 7: //delete - end 
        {
            if(head == NULL)
            {
                printf("List doesn't exist\n");
            }

            else if(head->next == NULL)
            {
                head = NULL;
                last = NULL;        
            }

            else
            {
                last = delete_end(last);
            }

            display(head,last);

            break;
            
        }

        case 8:  // display 
        {
            display(head,last);

            break; 
        }

        case 9:  // reverse list 
        {
            last = head;
            head = reverse(head);

            display(head,last);

            break;       
        }
    
    default:
        break;
    }



}*/
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
void inserting_end(struct node*newnode,struct node * head,int data);

void inserting_end(struct node*newnode,struct node* head,int data){
   struct node *ptr;
   ptr=head;
   while(ptr->next!=head){
    ptr=ptr->next;
   }
   ptr->next=newnode;
   newnode->next=head;
   

}
int main ()
{
    struct node * head;
    struct node* last;
    head=NULL;
    last=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    last=(struct node*)malloc(sizeof(struct node));
    head->data=30;
    head->next=NULL;
    last->next=head;
    struct node* newnode;
    newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    inserting_end(newnode,head,40);
}




















