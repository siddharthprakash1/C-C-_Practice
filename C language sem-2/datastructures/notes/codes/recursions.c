
#include<stdio.h>
int fact(int n)
{
    if(n==1){
        return 1;
    }
    return (n* fact(n-1));
}
int factTR(int n,int a){
    if(n==1){
        return a;
    }
    return(factTR(n-1,n*a));
}
int main (){
    int n=5;
    printf("%d",fact(n));
}