/*
Code for:
1)pop
2)push
3)print
4)peek
5)isEmpty
*/


//STACK IMPLEMENTATION USING ARRAYS

#include<stdio.h>
#include<stdlib.h>
#define Max 4
int stack_arr[Max];
int top =-1;

int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(top==Max-1){
        return 1;
    }
    else{
        return 0;
    }
}

int peek(){
    if(isEmpty()){
        printf("Stack underflow");
    }
    return stack_arr[top];
}
void push(int data){
    if(isFull()){ //isFull either return 0(not full) or 1(full)
        printf("Stack overflow");
        return ;
    }
    top=top+1;
    stack_arr[top]=data;
}
int pop()
{
    int value;
    if(top == -1){
        printf("stack underflow");
        //exit(1);
    }
    
    value=stack_arr[top];
    top=top-1;
    return value;  
}
void print(){
    int i;
    if(top == -1 ){
        printf("sTACK UNDERFLOW \n");
        return;   
    }
    for(i=top;i>=0;i--){
        printf("%d \t",stack_arr[i]);
    }
    printf("\n");
}
int main(){
    int choice,data;
    while(1){
        printf("\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.print the top element\n");
        printf("4.print all the elements of the stack\n");
        printf("5.Quit\n");
        printf("Please enter your choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to be pushed");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            data=pop();
            printf("Deleted element is %d\n",data);
            break;

        case 3:
            printf("the topmost element is %d",peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice");
            break;
        }
    }
    return 0;
}




//THIS IS THE CODE FOR LINKED LIST IMPLEMENTATION OF STACKS.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link ;
}*top=NULL;
int isEmpty(){
    if(top==NULL)
        return 1;
    else
        return 0;
}
void push(int data){
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(newNode));
    if(newNode==NULL){
        printf("Stack OverFlow");
        exit(1);
    }

    newNode->data=data;
    newNode->link=NULL;
    newNode->link=top;
    top=newNode;

}
void print(){
    struct node * temp;
    temp=top;
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    printf("the stack elements are :");
    while(temp){  //here this means while temp !=null
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int pop(){
    struct node * temp;
    int val;
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    } 
    temp=top;
    val= temp->data;
    top=top->link;
    free(temp);
    temp=NULL;
    return val;
}
 
int peek(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    return top->data;
printf("\n");
}
int main(){
    int choice,data;
    while(1){
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.print the top element\n");
        printf("4.print all the elements of the stack\n");
        printf("5.Quit\n");
        printf("Please enter your choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to be pushed");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            data=pop();
            printf("Deleted element is %d\n",data);
            break;

        case 3:
            printf("the topmost element is %d",peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice");
            break;
        }
    }
    return 0;
}
*/





//reversing of 2 stacks using 1 stack 

/*
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
*/





//Parenthesis expression using stacks

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 


int top=-1;
char stack[MAX];
char pop();
int isEmpty();
int isFull();
int match_char(char, char);
int check_balanced(char*);
void push(char);

void push(char c){
    if(isFull()){
        printf("stack overflow");
        exit(1);
    }
    top++;
    stack[top]=c;
}
char pop(){
    char c;
    if(isEmpty()){
        printf("stack Underflow");
        exit(1);
    }
    c=stack[top];
    top--;
    return c;
}
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull(){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int match_char(char a,char b){
    if(a=='[' &&b==']')
        return 1;
    if(a=='(' &&b==')')
        return 1;
    if(a=='{' &&b=='}')
        return 1;
    return 0;
}

int check_balanced(char*s){
    char temp;
    int i;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='['||s[i]=='('||s[i]=='{'){
            push(s[i]);
        }
        if(s[i]==']'||s[i]==')'||s[i]=='}'){
            if(isEmpty()){
                printf("R8 brackets are more than left");
                return 0 ; 
            }
            else{
                temp=pop();
                if(!match_char(temp,s[i])){
                    printf("mismatched brackets\n");
                    return 0;
                }
            }
        }
    }
    if(isEmpty()){
        printf("Brackets are well balanced.\n ");
        return 1;
    }
    else{
        printf("left brakcets are more than the right");
        return 0;
    }

}
int main(){
    char expr[MAX];
    int balanced;
    printf("ENTER THE EXPRESSION");
    gets(expr);
    balanced=check_balanced(expr);
    if(balanced==1){
        printf("valid");
    }
    else{
    printf("invalid ");
    }
    return 0;
}
*/