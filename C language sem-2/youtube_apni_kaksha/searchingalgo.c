 //linear search 
 /*
 #include<stdio.h>
 int linearsearch(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
 }
 int main (){
    int arr[]={1,2,3,4,2324,5,6,2,3,5,6,7};
     
    
    int size=sizeof(arr)/sizeof(int);
    int  element=2324;
    int searchIndex=linearsearch(arr,size,element);//recieves the value of i 
    printf("the elment %d was found at index %d\n",element,searchIndex );
    return 0;
 }*/

#include<stdio.h>
int binarysearch(int arr[],int size,int element){
    int low,mid,high;
    while(low<=high){
    mid=(low+high)/2;
    if(mid==element){
        return mid;
    }
    if(arr[mid]<arr){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    }
    return -1;}
int main ()
{
int arr[]={1,2,3,4,5,6,7,8,9,10,11,234,5456,121212112};
int size=sizeof(arr)/sizeof(int);
int element=11;
int searchindex=binarysearch(arr,size,element);
printf("the element %d was found at index %d \n",element,searchindex);
return 0;
}