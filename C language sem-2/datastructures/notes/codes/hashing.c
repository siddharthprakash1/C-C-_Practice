void initTable(NODE* ht[size]){
    for(int i=0;i<size;i++)
        ht[i]=NULL;
}

void destroyNodes(NODE* ht[size]){
    NODe *p,*q=NULL;
    for(int i=0;i<size;i++){
        p=ht[i];
        while(p!=NULL){
            q=p;
            p=p->next;
            free(q);
        }
        ht[i]=NULL; 
    }
}

void insert(NODE* ht[size],int rNo, char name[30]){
    int index = rNO%size;
    Node * newnode = malloc(sizeof(NODE));
    newnode->rNo=rNo
    strcpy(newnode->name,name);
    newnode->next=ht[index];//ht[index]=NULL 
    ht[index=newnode];
}

int search(NODE* ht[SIZE],int rNo,char name[30]){
    int index=rNO%size;
    NODE *p=ht[index];
    while(p!=NULL){
        if(p->rNo==rNO){
            strcpy(name,p->name);
            return 1;
        }
        p=p->next;
    } 
    return 0;
}

int delete (NODE * ht[size],int rNO){
    int index=rNo%size;
    node *p=ht[index];
    node *q=NULL;
    while(p!=NUll && p->rNo != rNo) {
        q=p;
        p=p->next;
    }
    if(p!=NULL){
        if(q==NULL)
            ht[index]=p->next;
        else
            q->next=p->next;
        free(p);
        return 1;
    }
}



//linear probing 

typedef struct node{
    int rNo;
    char name[20];
    int mark;//checks if the index is empty or not.
}