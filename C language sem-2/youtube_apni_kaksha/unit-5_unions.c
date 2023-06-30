//UNIONS
/*
#include<stdio.h>
#include<stddef.h>//used to find offset 
union X{
    int i;
    int j;
    double k;
};
struct Y{
    int i;
    int j;
    double k;
};
union Z
{
    int a;
    int b[3];

};

int main()
{
    printf("sizeof X is %d\n",sizeof(union X));//sizeof X is 8
    printf("sizeof Y is %d\n",sizeof(struct  Y));//sizeof Y is 16
    printf("sizeof Z is %d\n",sizeof(union Z));//sizeof Z is 12
//offset (type,member)
    printf("offsetoff of i in UNION X %d\n",offsetof(union X,i));//0
    printf("the offset of j in UNION X %d\n",offsetof(union X,i));//0
    printf("the offsetoff of k in UNION X %d\n",offsetof(union X,k));//0
    printf("the offsetoff of i in STRUCT Y %d\n",offsetof(struct Y,i));//0
    printf("the offset of j in STRUCT  Y %d\n",offsetof(struct Y,j));//4
    printf("the offsetoff of k in STRUCT Y %d\n",offsetof(struct  Y,k));//8
    union X x1;
    x1.i=2;
    printf("%d",x1.i);//just like in structures
    return 0;
    //u can use type def for union like in structure
}*/

//BIT FIELDS
/*
#include<stdio.h>
struct date{
    //An unsigned Integer means the variable can hold only a positive value.
    //in a month there are 31 days that is (11111)in binary so we need only 5bits not 32 bits of storage
    unsigned int d:5;//2^5 - 1 =31 maximum number that can be stored here
    unsigned int m:4;//2^4-1=15 u need year in 1-12 so this much is enough       
    unsigned int y;
    //unsigned int a[10]:3;//array of bit field not allowed 
    //unsigned int *a:10;//pointer of bit field not allowed 

};
int main()
{
    printf("%d\n",sizeof(struct date));//12
    struct date d1={32,12,2020};
    printf("DATE IS %d\n",d1.d);
    printf("mnth IS %d\n",d1.m);
    printf("yr IS %d\n",d1.y);
    printf("%p\n",&d1.y);
   return 0;
}*/

//ENUM
/*
#include<stdio.h>
#include<limits.h> can max value of int ur pc can hold 
enum days {
    sun=1,mon,tue,wed,thurs,fri,sat
};//so here mon=2,tue=3......
enum eg{
    a=2,b=2 //here u cant use sun or mon .... it gives error 
}e;
enum eg2{
    c=INT_MAX//,d,c,e..u cant add these since u have already soted the largest value 
    //nocolon here or else statement terminates
};
int main (){
    enum days d;
    printf("%d\n",sizeof(d));
    for(int i=sun;i<=sat;i++){
        printf("%d\t",i);//here not name but valuesare printed 
    }
    printf("\n");
    for(int i=a;i<=b;i++){
        printf("%d",i);
    }
    printf("\n");
    //so here we see that 2 eunmeration cinstant can have same values
    printf("%d",c);
    return 0;
}
*/

//storage class
//lifetime ,scope of a variable.
//automatic,global,external,static,register

//automatic
/*
#include<stdio.h>
int main(){
    int i=100;//gets created when a fuction is made and destroyed after function is executed
    //in for loop the int i u use
    //local variable
    auto float j=3.3;
    printf("%d \n%f\n",i,j);
}
*/

//external-use keyword extern
//when u use this exter before a variable u r trying to inform the compiler that the variable is declared somewhere else.
/*
#include<stdio.h>
int main()
{
    extern int i;
    printf("%d",i);
}
int i=10;//the i can be defined anywhere and in any file

*/


//register-can be used with a pointer variable 
//in general anything stored at memory location , its accessing requires time,since u have to find out the value that is present 
//but anything stored in the register is easy to access since its a part of processor itsef 
//any variables which is used many times if kept in register makes the program run faster
/*
#include<stdio.h>
int main ()
{
    register int a=20;
    printf("%d",a);
}
*/
//register can have address or value

//GLOBAL 

//any variable declared outside any of thr fn 
//accessed and modified by any fn
//by default 0 will be assigned 
/*
#include<stdio.h>
int i=10;
int j;//will take 0 since nothing is defined for it 
int main(){
    printf("%d\n",i);//10
    i=20;
    printf("%d\n",i);//20
    printf("%d",j);//0
}
*/

//static 
//preserve the values even after they go out of the scope 
//they preserve the previous values in the previous scope and they are not intialized again in a new scope:
//these variables gets initialized only once 
//2 types gloabal and local static
/*
#include<stdio.h>
int f1()
{
    static int count =0;
    //scope of count is in this fn  but lifetime for the entire program
    //int count =0;//here u get 1 and 1
    count++;
    return count;
}
int main ()
{
    printf("%d\n",f1());
    printf("%d\n",f1());//here we used static that is why the value had become 2 since it preserved the value form the last scope
    return 0;
}
*/
//scope of local static variable 
/*
#include<stdio.h>
void f1();
int main (){
    f1();
    f1();
    f1();
}
void main()
{
    static int a=10;
    ++a;
    printf("%d",a);
    //scope of the local static variable stays in this fuction 
    //but lifetime is through out the program 
}
*/
/*
#include<stdio.h>
void f1();
static int i=40;//gloabal static variable 
//these remain restricted to the scope of the file where it is has been defined  
//so here scope is entire program liftime is for this file only 
int k=10;
main (){

}
*/
//qualifiers 
//keywords that are applied to the data types
//can be used to alter and modify the size or sign 
//3types : size,sign,type
/*size:helps in altering the size 
short int <= int <=long int*/
/*
#include<stdio.h>
int main()
{
    short int i=10;
    int j=1000;
    long int k=100000;
    printf("%d\n%d\n%ld\n",i,j,k);
    printf("%d\n%d\n%ld\n",sizeof(i),sizeof(j),sizeof(k));
}
*/

//SIGN QAULIFIER
/*2types 
signed(+ve/-ve) and usigned(+ve)
*/
/*
#include<stdio.h>
int main()
{
    unsigned int a=10;
    unsigned int b=20;//if u give negative value u get garbage value 
    int c=100;
    signed int d=-20;
    printf("%u\n%u\n%d\n%d",a,b,c,d);
}*/

//TYPE QUALIFIER 
/*
2 types :const , volatile.
const:the values cannot be changed(literals) 
volatile/variable:the 
*/
/*
#include<stdio.h>
int main ()
{
    const int i=5;
    printf("%d\n",i);
    //i=10; gives u an error since its now a constant
 }
*/
/*
#include<stdio.h>
int main(){
    int i=10;
    int j=5;
    const int *ptr=&i;//here the pointer is a constant
    printf("%d\n",*ptr);
    //*ptr=100; gives u an error coz u can access the constant but cant change it  
}

*/
/*
#include<stdio.h>
int main(){
    const int i=5;//here variable is a constant so it can be changed by suing pointers 
    int *p=&i;
    printf("%d\n",*p);
    *p=6;
    printf("%d",*p);

}*/

/*VOLATILE:
-optimization 

*/
/*
#include<stdio.h>
int main()
{
    volatile int a=10;
    return 0;
}
*/

//PREPROCESSOR DIRECTIVES 
/*
#include<stdio.h>
#define PI 3.14
#define SQR(x) x*x
#define STR "GYM"
#define CUBE(x) SQR(x)*(x)
int main()
{
    //PI=3.14; cannot do reassignment 
    #define PI 12345.6789//u get an warning thats it 
    printf("%f\n",PI);//12345.678900
    printf("%d\n",SQR(2+3));//11
    printf("%s\n",STR);//GYM 
    printf("%d",CUBE(3));//27
    //printf("%d",);
    return 0;
}


*/

/*
#include<stdio.h>
#define max 10
int main ()
{
    #ifdef max
        printf("max is defined and the value is %d",max);
    #else
        printf("max is not defined\n");
    #endif
    printf("out of scope of conditional compilation \n");
    return 0;
}*/


/*
Program to demonstrate #pragma

#pragma pack (n)
Specifies the packing alignment for structure, union members. Sets the alignment of all aggregate members to a specified byte boundary.
If the byte boundary number is smaller than the natural alignment of a member, padding bytes are removed, thereby reducing the
overall structure or union size.

*/
/*
#include<stdio.h>
#pragma pack(1)//n 1,2,4,6,...2^n
struct eg{
    char a;
    int b;
};
int main (){
    //printf("SIZE: %lu bytes",sizeof(struct eg));//8 bytes since padding 
    printf("SIZE: %lu bytes",sizeof(struct eg));//gives 5bytes:
    return 0;
}*/

//find the sum of all the number in the command lines
/*
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char*argv[])
{
    printf("%d",argc);//argc contIns no.of arguments passed in the command lines 
    int sum =0;
    if (argc>1){
    for(int i=0;i<argc;i++)
    {
        sum=sum+atoi(argv[i]);
    }
    printf("%d",sum);
    }
    else{
        printf("no arguments");
    }
    return 0;
}*/
//portable program development - used to develop programs that can run on any os 
/*
#include<stdio.h>
int main()
{
    #ifdef __MINGW32__
        printf("WINDOWS !!!\n");
        char c,d;
        printf("Enter 2 char:");
        scanf("%c",&c);//here scanf has the value u entered and buffer tooo
        fflush(stdin);//here the extra buffer is flushed out from here 
        scanf("%c",&d);//coz of this the second scanf wont work 
        printf("% c and %c is entered",c,d);
    #endif
    #ifdef __unix__
        printf("UNIX !!!\n");
        char c,d;
        printf("Enter 2 char:");
        scanf("%c",&c);//here scanf has the value u entered and buffer tooo
        __fpurge(stdin);//here the extra buffer is flushed out from here 
        scanf("%c",&d);//coz of this the second scanf wont work 
        printf("% c and %c is entered",c,d);
    #endif



}
 */
//VARIABLE LENGTH ARGUMENTS 
//implementing the function sum to add all the values passed to it 
/*
#include<stdio.h>
#include<stdarg.h>
double sum(int n,...);

int main()
{
    printf("hi");
    double res1=sum(4,1.5,1.5,1.5,1.5);//4 gives how many numbers u can put in 
    double res2=sum(2,1.5,1.5);
    printf("res1=%lf and res 2=%lf\n",res1,res2);
    return 0;
}
double sum(int n,...)
{
    double s=0;//double variable to store the sum 
    va_list va;//creating a variable va
    va_start(va,n);//va_start : starts the process -n is the no.of arguments
    for(int i=0;i<n;i++){
        s=s+va_arg(va,double);//in va_arg(it takes variable , the typr of variable )
    }
    va_end(va);//ends the process
    return 0;
}*/
#include<stdio.h>
int main(){
    int sum;
    int i,j;
    for(i=0,j=0;i<100;i++,j++){
        sum=i*j;
    }
    printf("%d",sum);


}