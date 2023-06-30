//examples of pointers
/*
#include<stdio.h>
int main(){
    int age=22;
    int *ptr=&age;
    //int _age=*ptr;

    //printf("%d\n", _age);
    printf("%u\n",ptr);
    //printf("%p\n",& _age);
    printf("%u\n",&age);

    return 0;
}*/

/*
#include<stdio.h>
int main()
{
    int age=18;
    int *ptr=&age;
    int x=*ptr;
    printf("%d\n",*ptr);//value of the pointer variable 
    printf("%d\n",*(&age));//value at addres age
    printf("%d\n",*(&ptr));//has the address of ptr

}*/

//find the output
/* 
#include<stdio.h>
int main()
{
    int *ptr;
    int x;
    ptr =&x;//ptr stores the address of x
    *ptr=0;//so we have stored 0 at ptr so 0 is stored in the x too since same address
    //we store the ptr value in x
    printf("x=%d\n",x);// so x=0
    printf("*ptr=%d\n",*ptr);//and its 0
    *ptr +=5;// here ptr becomes 5
    //also x becomes 5 since they have same address
    printf("x = %d\n",x);
    printf("*ptr=%d\n",*ptr);
    (*ptr)++;// here ptr is 6
    printf("x = %d\n",x);
    printf("*ptr=%d\n",*ptr);
}*/

//pointer to pointer a variable that stores the memory of address of another pointer
// printt the value of 'i' from its pointer to pointer
/*
#include<stdio.h>
int main()
{
    int i=5;
    int *ptr=&i;
    int **pptr=&ptr;
    printf("%d\n",**(pptr));//here (*ptr)-gives the address of value sotred at the pointer
    //*pptr-gives the address of value stored at ptr
    //**pptr-gives the value of address stored at ptr

}*/
//function call are of 2 types call by type and call by refrence
/*
#include<stdio.h>
void square(int n);
void _square(int *n);//we r giving a variables address here
int main(){
    int n;
    printf("enter the values");
    scanf("%d",&n);
    square(n);//here the output is 16
    printf("the number was:%d\n",n);//output is 4
    _square(&n);//here the output is 16 and notice we gave the input as the address of n and not n
    printf("the number was:%d\n",n);//here the output is 16 because we changed the value at the address using pointer
}// we are passing address of variable as argument in call by refrence of pointer function call

//call by value
void square(int n){
    n=n*n;
    printf("square=%d",n);
}
//call by refrence
void _square(int *n){
    *n=(*n) * (*n);// 4*4 is stored at the address
    printf("the square is=%d",*n);
}*/

//swap 2 numbers a and b:
/*
#include<stdio.h>
void swap(int a,int b);
void _swap(int *a,int *b);
int main()
{
    int x=1,y=2;
    swap(x,y);
    printf("x=%d & y=%d\n",x,y);//here we see that x and y are same in the main fn
    // the output here is:
    //a=2 b=1
    //x=1 & y=2
    //to actually swap it u have to call by refrence:
    _swap(&x,&y);
    printf("x=%d & y=%d\n",x,y);

}

//call by value:
void swap(int a,int b){
    int t=a;
    a=b;
    b=t;
    printf("a=%d b=%d\n",a,b);

}
//call by refernce:
void _swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b= t;
    //printf("a=%d b=%d\n",a,b);
}*/

//will the address output be the same??
/*
#include<stdio.h>
void printAddress(int n);
int main()
{
    int n=4;
    printf("%p\n",&n);
    printAddress(n);
    return 0;
}

void printAddress(int n){
    printf("%p\n",&n);
}
//here u see diffrent address being print since this is function by call so here a copy of the variable is made whose value is same but stored at a diffrent place
*/

//wap to make a fn to find sum,product nd average of 2 numbers,Print the averge in the main function 
/*
#include<stdio.h>
void doWork(int a, int b, int *sum, int *prod,int *avg);
int main(){
    int a=3,b=5;
    int sum,prod,avg;
    doWork(a,b,&sum,&prod,&avg);
    printf("sum=%d,prod=%d,avg=%d\n",sum,prod,avg);
    return 0;
}
void doWork(int a,int b,int*sum,int*prod,int*avg){
    *sum=a+b;
    *prod=a*b;
    *avg=(a+b)/2;
}
*/ 
//////////////////////////////////////////////////////////////
//-*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*__**__*_*_*_*_*
/*
ARRAYS
*/
//how to take multiple inputs and print them 
/*
#include<stdio.h>
int main()
{
    int marks[4];
    for(int i=1;i<=4;i++){
    scanf("%d",&marks[i]);
    }
    for(int i=1;i<=4;i++){
    printf("%d\t",marks[i]);
    }

}

*/

//wap to enter price of 3 items and print their final cost with gst 
/*
#include<stdio.h>
int main ()
{
    float a[4];
    for(int i=0;i<=2;i++){
        scanf("%f",&a[i]);
    }
    for(int i=0;i<=2;i++){
        printf("%f\n",a[i]*1.18);//here u use %f not d 
    }
}
*/
/*
pointer arethmatic
 when u do ptr++ the pointer increase its value by 4
 if ptr-- then decreases by 4
 4 coz its integer
 */
//wap to get 10 inputs
/*
#include<stdio.h>
int main(){
    int arr[10];
    for(int i=0;i<=9;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<=9;i++){
        printf("%d\t",arr[i]);
    }
}*/
//POINTER ARETHMATIC
/*
#include<stdio.h>
int main(){
    int age=22;
    int *ptr=&age;
    printf("%u\n",ptr);//6422296
    ptr++;
    printf("%u",ptr);//6422300
    return 0;
}*/
//you can use it to compare two pointers
//you can use it to subtract one pointer from another 
//for comparimg example
/*
#include<stdio.h>
int main(){
    int age=22;
    int _age=23;
    int *ptr=&age;
    int *_ptr=&_age;
    printf("diffrence=%u\n",ptr-_ptr);//%u since usigned specifier
    _ptr=&age;//here we change the address which it holds to address of age 
    printf("compare=%u",ptr==_ptr);//%u since usigned specifier
}
*/
//so here we r using pointer to print the value of the number stored in the array
/*
#include<stdio.h>
int main(){
    int aadhar[5];
    //input
    int *ptr=&aadhar[0];
    for(int i=0;i<=4;i++){
        printf("index-%d\n",i);
        scanf("%d",&aadhar[i]);
    }
    //output
        for(int i=0;i<=4;i++){
        printf("%d index-%d\n",i,aadhar[i]);
    }
    return 0;
}*/
//ARRAY AS A FUNCTIONAL ARGUMENT
/*
#include<stdio.h>
void printnumber(int arr[],int n);//void printnumber(int *arr,int n) this is also K 
int main(){
    int arr[]={1,2,3,4,5,6,7};
    printnumber(arr,7);
}
void printnumber(int arr[],int n){
    for(int i=0;i<=6;i++){
    printf("%d\t",arr[i]);
    }
}
*/
//Multidimensional Array
//to store marks of 2students in 3 subjects 
/*#include<stdio.h>
int main(){
    // 2students X 3subjects
    int marks[2][3];//_ _ _  |  _ _ _ 2 diffrent arrays are made 
    //for(int i=0;i<=2;i++){
        //for(int j=0;j<=1;j++){
            //printf("");
            //scanf("%d",marks[i][j]);
            
        //}
    //}
    //for(int i=0;i<=1;i++){
    //for(int j=0;j<=2;j++){
        //printf("%d",marks[i][j]);
    //}
    //}
    marks[0][0]=90;
    marks[0][1]=93;
    marks[0][2]=97;
    marks[1][0]=93;
    marks[1][1]=94;
    marks[1][2]=99;
    printf("%d",marks[0][0]);//prints the marks of the 1st student's marks in 1st subject    
} */

//USER WILL DESIGN THE 2D-ARRAY
/*
#include<stdio.h>
int main (){
    int a[100][100],r,c;
    printf("enter the number of rows & column u want");
    scanf("%d %d",&r,&c);
    printf("enter the %d elements\n",r*c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}*/
//POINTERS IN 2D ARRAY
/*
#include<stdio.h>
int main()
{
int a[4][3]={{1,3,4},{68,8,8},{4,6,8},{22,44,56}};
    printf("%d\n",a[2][1]);
    //printf("%d\n",*a);
    printf("%d\n",*(a+1));
    printf("\n%d\n",*(*(a+2)+1));
    printf("%d",*(*a+1));
    return 0;
}
*/
//doubt
//continued 
/*
#include<stdio.h>
int main()
{
int a[4][3]={{1,3,4},{68,8,8},{4,6,8},{22,44,56}};
    printf("%d\n",a[2][1]);
    //int *p=a;//it gives warnin but its fine 
    //printf("%d",p[1][0]);this shows an error since p is pointing to wherever a is pointing but since it doesnot have any information about the column size here only a has so its a error. 
    //printf("%d",p[4]);//prints the number at the 5th postion (it starts from zero).Whatever n in p[n] is there the value at the corresponding position gets printed 
    //but if u dont want the warning then 
    int (*p)[3]=a;//means the 4th element 
    printf("%d\n",p[2][1]);//4ht element is printed here
    printf("%d %d\n",sizeof(p),sizeof(*p));//4 and 12 since p is pointer which is 4bit and *p is pointing to the array so size of array is printed which is 12 since there are 3 elements 
    return 0;
}*/

//Display and read using fuctions 
/*
#include<stdio.h>
void read(int[][100],int ,int );
void display(int[][100],int,int);
int main()
{
    int a[100][100],r,c;
    printf("enter the number of rows and column");
    scanf("%d %d",&r,&c);
    printf("enter %d elements\n",r*c);
    rea
    d(a,r,c);
    display(a,r,c);
}
void read(int a[][100],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){ 
            scanf("%d",&a[i][j]);
        }
    }
}
void display(int a[][100],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}*/
