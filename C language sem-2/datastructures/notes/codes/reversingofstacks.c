#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * link;
}; 
int isEmpty(struct node*top){
    if(top==NULL){
        return 1;
    }
    else
        return 0;
}
void  push(int data,struct node ** top){//top here is just a local pointer which can take any pointer (top1,top2)
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("stack overflow");
        exit(1);
    }
    newNode->data=data;
    newNode->link=NULL;
    newNode->link=*top;
    *top=newNode;
}
int pop(struct node ** top){
    struct node * temp;
    temp=*top;
    *top=(*top)->link;
    int val=temp->data;
    free(temp);
    temp=NULL;
    return val;
}
void print(struct node**top){
    struct node * temp;
    temp=*top;
    while(temp){
        printf("%d",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
int main (){
    struct node * top=NULL;
    struct node * top1=NULL;
    struct node * top2=NULL;
    int data;
    push(1,&top);
    push(2,&top);
    push(3,&top);
    print(&top);

    data=pop(&top);
    push(data,&top1);
    data=pop(&top);
    push(data,&top1);
    data=pop(&top);
    push(data,&top1);
    print(&top);
    print(&top1);
    
    
    data=pop(&top1);
    push(data,&top2);
    data=pop(&top1);
    push(data,&top2);
    data=pop(&top1);
    push(data,&top2);
    print(&top);
    print(&top1);
    print(&top2);
    
    data=pop(&top2);
    push(data,&top);
    data=pop(&top2);
    push(data,&top);
    data=pop(&top2);
    push(data,&top);
    
    print(&top); 
    return 0;
}
