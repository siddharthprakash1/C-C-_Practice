#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
void print_data(struct node* head){
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        printf("%d \t",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void insert_beg(struct node** head, int data){
    struct node * temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    temp->link=*head;
    *head=temp;
    

}
void insert_end(struct node*head,int data){
    struct node* temp,*temp1;
    temp=head;
    temp1=(struct node*)malloc(sizeof(struct node));
    temp1->link=NULL;
    temp1->data=data;
    
    while(temp->link != NULL){
        temp=temp->link;
    }
    temp->link=temp1;
    
}
int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
     print_data(head);
     int data=3;
    insert_beg(&head,data);
    print_data(head);
    insert_end(head,data);
    print_data(head);

}