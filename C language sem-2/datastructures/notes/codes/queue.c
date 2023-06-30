/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int);
int dequeue();
int peek();
void print();
int isFull();
int isEmpty();

int main(){
    while(1){
        int choice;
        int data;
        printf("\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.print the first element\n");
        printf("4.print all the elements of the queue\n");
        printf("5.Quit\n");
        printf("Please enter your choice");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("enter the element to be added");
                scanf("%d",&data);
                enqueue(data);
            case 2:
                data =dequeue();
                printf("deleted element is data: %d",data);
                break;
            case 3:
                printf("the first element of the queue is %d",peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong Choice\n");

        }

    }
}
void enqueue(int data)
{
    if(isFull())
    {
        printf("Queue Overflow");
        exit(1);
    }
    if(front == -1)
        front =0;
    rear++;
    queue[rear]=data;
}
int dequeue(){
    int data;
    if(isEmpty()){
        printf("Queue Underflow\n");
        exit(1);
    }
    data=queue[front];
    front++;
    return data;
}

int  isEmpty(){
    if(front==-1 || front==rear+1 ){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(rear==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

int peek()
{
    if(isEmpty()){
        printf("Queue Underflow.\n");
        exit(1);
    }
    return queue[front];
}

void print(){
    int i;
    if(isEmpty())
    {
        printf("Queue Underflow.\n");
        exit(1);
    }
    printf("Queue: \n");
    for(i=front;i<=rear;i++){
        printf("%d",queue[i]);
    }
    printf("\n");
}*/

//linked list implementation of queue
/*
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * link ;
}* front=NULL, *rear=NULL;

void enqueue(int);
int dequeue();
int peek();
void print();
int isFull();
int isEmpty();

void enqueue(int n){
    struct node * temp;
    temp = malloc(sizeof(struct node));
    temp->data=n;
    temp->link=NULL;
    if(temp==NULL){
        printf("No space");
        exit(1);
    }
    if(rear ==NULL){
        front = rear = temp;
    }
    else{
        rear->link=temp;
        rear=temp;
    }
    
}

void dequeue(){
    int data;
    struct node * temp;
    temp=front;
    data=temp->data;
    front=front->link;
    free(temp);
    temp=NULL;
}

int isEmpty(){
    if(front==NULL){
        return 1;
    }
    else    
        return 0;
}

void print(){
//print the data ofthe node pointed by temp
//update the temp pointer so as it points to the next node
//repeat step 1 and step 2 until temp becomes null
    
struct node* temp;
temp=front;
if(isEmpty())
{
    printf("Queue UNDERfLOW\n");
    exit(1);
}
printf("Queue: \n");
while(temp !=NULL){
    printf("%d",temp->data);
    temp=temp->link;
}
printf("\n");
}

*/

//circular queue
void enqueue(int data){
if(isFull()){
    printf("Ques OverFlow\n");
    exit(1);
}
if(front ==1)
    front=0;
if(rear==MAX-1)
    rear=0;
else
}