#include<stdio.h>
#include<stdlib.h>
typedef struct trie{
    struct trie *child[26];
    int endOfWord;
}TRIE;

int main(){
    TRIE *root=createNode();
    insertPattern(root,"apple");
    insertPattern(root,"app");
}

TRIE * createNode()
{
    TRIE *newnode=malloc(sizeof(TRIE));
    for(int i=0;i<26;i++){
        newnode->child[i]=NULL;
    }
    newnode->endOfWord=0;
    return newnode;    
}

void insertPattern(TRIE *root,char *pattern){
    TRIE * cur=root;
    while(*pattern){
        if(cur->child[*pattern-'a']==NULL)
        {
            cur->child[*pattern-'a']=createNode();
        }
        cur=cur->child[*pattern -'a'];
        pattern ++;
    }
    cur->endOfWord=1;
}

int search(TRIE *root, char *pattern){
    while(*pattern){
        if(root->child[(*pattern -'a')]==NULL){
            return 0;
        }
        root=root->child[*pattern-'a'];
        pattern ++;
    }
    return root->endOfWord;
}

TRIE* delete(TRIE *root,char *str,int level,int length){
    if(root==NULL){
        return root;
    }
    if(level==length){
        if(root->endofWord)
            root
    }
}