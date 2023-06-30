/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 7
struct stack{
    int top;
    int arr[MAX];
};
typedef struct stack STACK;
STACK *s;
void init(STACK *s){
    s->top=-1;
}
int isEmpty(STACK *s){
    if(s->top==-1){
        printf("The stack is empty ");
        return 1;
    }
    return 0;
}
int isFull(STACK *s){
    if(s->top==MAX-1){
        printf("The stack is Full ");
        return 1;
    }
    return 0;
}
void push(STACK *s,int data){
    if (!isfull(s)){
        s->top++;
        s->arr[s->top]=data;
        printf("\n inserted %d",s->arr[s->top]);
    }
}
void pop(STACK *s){
    if(!isEmpty(s)){
        printf("\n deleted %d",s->arr[s->top]);
        (s->top)--;
    }
}
void peep(STACK *s){
    if(!isEmpty(s)){
        for(int i=s->top;i>=0;i--)
            printf("%d",s->arr[i]);
    }

    printf("\n the last element of stack: %d",s->arr[s->top]);
}
int main (){
    s=(STACK*)malloc(sizeof(STACK));
    init(s);
    for(int i=0; i<=MAX;i++)
    {
        push(s,i^3);
    }
    peep(s);
    display(s);
    for (int i=0; i<=MAX;i++){
        pop(s);
    }
    peep(s);
    display(s);
}


*/
//S
