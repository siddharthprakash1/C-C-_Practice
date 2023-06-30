#include<stdio.h>
int main()
{
    int a[10], int n,key,low,high;
    printf("enter n ");
    scnaf("%d",&n);
    printf("enter the elements");
    for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
    //binairy search 
    printf("%d",bs(a,n,0,n-1));
    }
}

