//wap to print hello using function 
/*
#include<stdio.h>
void printHello();
int main(){
    printHello();
    return 0;
}
void printHello() {
    printf("hello");
}*/
// wap to print hello and second to print goodbye:
/*
#include<stdio.h>
void hello();
void bye();
int main(){
    hello();
    bye();
    return 0;
}
void hello(){
    printf("hello\n");
}
void bye(){
    printf("Good bye");
}*/ 
//wap to enter namaste for indian and bonjour for french
/*
#include<stdio.h>
void indian();
void french();
int main(){
    char c;
    printf("enter i for indian and f for french:");
    scanf("%c",&c);
    if(c=='i'){
        indian();
    }
    else if(c=='f'){
        french();
    }
    else{
        printf("wrong input");
    }
}
void indian(){
    printf("NAMASTE");
}
void french(){
    printf("BONJOUR");
}*/

//here all the function are called from main function 
// the compiler 1st goes to main from there it goes to other functions
//wap a fn to store the sum of two numbers:
/*
#include<stdio.h>
int sum(int a, int b);
int main ()
{
    int a,b;
    printf("enter the 1st numbers: ");
    scanf("%d",&a);
    printf("enter the 2nd numbers: ");
    scanf("%d",&b);
    int p=sum(a,b);//here in the calling statement its argument or actual parameter
    printf("%d",p);
    return 0;
}
int sum(int a, int b){ //here int a and int b are parameter or formal parameter
    return a+b;
} */

//wap to make a table fn of a given number

/*
#include<stdio.h>
void printTable(int n);
int main()
{
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    printTable(n);//argument or actual parameter
}
void printTable(n){ //parameter/formal parameter
    for(int i=1;i<=10;i++){
        printf("%d X %d=%d\n",n,i,n*i);
    }
}
*/
// wap to calculate the bill with gst
/*#include<stdio.h>
void calc(float n);
int main(){
    float n;
    printf("enter the amount");
    scanf("%f",&n);
    calc(n);
    return 0;
}
void calc(float n){
    float p=n+n*0.18;
    printf("the price:%f",p);
}
*/
//wap to use library fn to calculate the square of a number given by user
/*#include<stdio.h>
#include<math.h>
int main()
{
    int n=4;
    printf("%f",pow(n, 2));//here u used %f since it stores in that value only 
    return 0;
}
*/
//wap to write the fn for area of circle square rectangle 
/*
#include<stdio.h>
float square(float length);
float rectangle(float length,float breadth);
float circle(float radius);
int main(){
    float length,breadth,radius;
    printf("enter the sq length");
    scanf("%f",&length);
    printf("enter the rectangle breadth");
    scanf("%f",&breadth);
    printf("enter the circle radius");
    scanf("%f",&radius);
    printf("%f",square(length));
    printf("%f",rectangle(length,breadth));
    printf("%f",circle(radius));

}
float square(float length){
    
    printf("area:%f\n",length*length);
}
float rectangle(float lenght,float breadth){
    printf("area:%f\n",lenght*breadth);
}
float circle(float radius){
    printf("area:%f\n",3.14*radius*radius);
}*/

//wap using recursion to print hello world 5 times
/*
#include<stdio.h>
void hi(int count);
int main(){

    hi(5);
    return 0;
}
void hi(int count){
    if(count ==0){
        return;
    }
    printf("HELLO WORLD\n");
    hi(count -1);
}
*/

//wap using recursion to print the sum of 1st n natural numbers
/*
#include<stdio.h>
int sum(int n);
int main()
{
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    printf("sum is:%d",sum(n));
    return 0;
}
int sum(int n){
    if(n==1){
        return 1;//base case 
    }
    return n+sum(n-1); 
}
*/
//wap to print factprial of n by recurssion
/*
#include<stdio.h>
int fact(int n);
int main(){
    int n;
    printf("enter the number");
    scanf("%d",&n);
    printf("factorial:%d",fact(n));
    return 0;
}
int fact(int n){
    if (n==0){
        return 1;
    }
    int p=n*fact(n-1);
    return p;
}*/

//wap to create a fn to chnge farhenite to celsius
/*
#include<stdio.h>
int conv(int c);
int main()
{
    int c;
    printf("enter the temp in celsius:");
    scanf("%d",&c);
    printf("temp in farhenite is :%d",conv(c)); 
}
int conv(int c){
    return (c*1.8)+32;
}*/
//wap to get the area function of square and circle:
/*
#include<stdio.h>
int square(int side);
int circle(int radius);
int main(){
    int side,radius;
    printf("enter the side of the sq:");
    scanf("%d",&side);
    printf("enter the radius of the circle:");
    scanf("%d",&radius);
    printf("area of the square is:%d\n",square(side));
    printf("area of the circle is:%d",circle(radius));
}
int square(int side){
    return side*side;
}
int circle(int radius){
    return 3*radius*radius;//if u wanna r8 3.14 change everything to float 
}
*/

//write a fibonacci sequence:
/*
#include<stdio.h>
int fib(int n);
int main(){
    int n;
    printf("enter the number");
    scanf("%d",&n);
    printf("the series is:%d",fib(n));
}
int fib(int n){
        if (n==0){
        return 0;
        }
        else if(n==1){
            return 1;
        }
        return fib(n-1)+fib(n-2);
}*/

//wap to find the sum of digits of a number:
/*
#include<stdio.h>
int sumofdigit(int n);
int main(){
    int n;
    printf("enter the number");
    scanf("%d",&n);
    printf("the sum is:%d",sumofdigit(n));
}
int sumofdigit(int n){
    if(n%10==0){
        return 0;
    }
    return (n%10+sumofdigit(n/10));


}*/

