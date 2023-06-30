/*# include<stdio.h>
#include<conio.h>
int main() {
    int a=2;
    printf("%d",a);
    return 0;
}*/

// output function
/*
#include<stdio.h>
int main()
{
    int age=22;
    float pi=3.14;
    char star='*';
    printf("age is %d \n",age);
    printf("pi value is %f \n",pi);
    printf("star is %c \n",star);
    return 0;
}
*/
/*
//input function
#include<stdio.h>
int main ()
{
    int a,star;
    float pi;

    printf("enter the 1st number  ");
    scanf("%d",& a);
    printf("enter the decimal value ");
    scanf("%f",& pi);
    printf("enter the second number ");
    scanf("%d",& star);
    int sum = a+star+pi;
//printf("sum is :%d",a+b+pi) also works u can remove extra varaible
    printf("the sum is: %d",sum);
    return 0;
}
*/
// wap to find the area of the square
/*#include<stdio.h>
int main ()
{
    float a,b;
    printf("enter the 1st side");
    scanf("%f",&a);
    printf("%f",a);
    printf("enter the 2nd side");
    scanf("%f",&b);
    printf("the area is: %f", a * b);
    return 0;
}*/
// wap to find the area of the circle
/*#include<stdio.h>
int main()
{
    float r;
    printf("enter the radius");
    scanf("%f", &r);
    printf("the area of the circle is:%f", (3.14*r*r));
    return 0;
}
*/
// using the math functions
/*
#include<stdio.h>
#include<math.h>
int main()
{
    int a=2,b=2;
    int power=pow(a,b);
    printf("%d",power);
    return 0;
}
*/

// using the math functions
/*
#include<stdio.h>
#include<math.h>
int main()
{
    printf("%d",13%12);
    return 0;
}
*/
// precedence
/*
#include<stdio.h>
#include<math.h>
int main()
{
    int a=5*2-2*3;
    int b=5*2/2*3;
    int c=5*(2/2)*3;
    int d=5+2/2*3;
    printf("\n %d",a);
    printf("\n %d",b);
    printf("\n %d",c);
    printf("\n %d",d);
    return 0;
}
*/
/*
#include <stdio.h>
#include <math.h>
int main()
{
    printf("\n %d", 4 == 4);
    printf("\n %d", 4 != 4);
    printf("\n %d", 4 >= 4);
    printf("\n %d", 4 <= 4);
    printf("\n %d", 4 == 4 && 5 == 5);
    printf("\n %d", !(4 == 4));
    return 0;
}
*/

    // wap to check if a number is divisble by 2:
    /*#include<stdio.h>
    #include<math.h>
    int main()
    {
        //even->1
        //odd->0
        int a;
        printf("ENTER THE NUMBER");
        scanf("%d",&a);
        printf("%d",a%2==0);
        return 0;

    }*/
    // wap to print 1(true) or 0(false) for following statements:
    /*#include<stdio.h>
    #include<math.h>
    int main()
    {
        int isSunday=1;
        int isSnowing=1;
        int isMonday=0;
        int isRaining=1;
        printf("%d",isSunday&&isSnowing);
        printf("%d",isMonday&&isRaining)
        return 0;
    }*/
    /*#include<stdio.h>
    #include<math.h>
    int main()
    {
        int x;
        printf("enter the number");
        scanf("%d",&x);
        printf("%d",x> 9&& x<100);
        return 0;
    }*/

    // if and else statments

    // wap to check age:
    /*
    #include<stdio.h>
    int main()
    {
        int age;
        printf("enter your age");
        scanf("%d",& age);
        if(age>=18)
        {
            printf("you are an adult");
        }
        else
        {
            printf("you are not an adult");
        }
        return 0;
    }
    */
    // wap to check odd and even
    /*#include<stdio.h>
    int main ()
    {
        int a;
        printf("ENTER THE NUMBER");
        scanf("%d",&a);
        if(a%2==0)
        {
            printf("it is a even number");
        }
        else
        {
            printf("its a odd number");
        }

    }*/
    // wap to check the age groups of the given input
    /*#include<stdio.h>
    int main()
    {
        int age;
        printf("Enter you age");
        scanf("%d",&age);
        if(age<=12)
     0   {
            printf("child");
        }
        else if (age<18){
            printf("teenager");
        }
        else{
            printf("adult");
        }

    }
    */
    // ternary operator
    // use only when single statement
    // form-COndition?dosomething if true: dosomething if false;

    // wap suing ternary operation for age:
    /*#include<stdio.h>
    int main()
    {
        int age;
        printf("Enter you age");
        scanf("%d",&age);
        age>=18 ? printf("adult\n") : printf("not adult\n");
    }
    */
    // Conditional operators
    // wap to find the days of week with numbers
    /*#include<stdio.h>
    int main()
    {
        int day;//1-mon,2-tu,3-wed.....
        printf("enter the day in number:");
        scanf("%d",&day);
        switch (day){
            case 1 :printf("monday");
                   break;
            case 2 :printf("tuesday");
                   break;
            case 3 :printf("wednsday");
                   break;
            case 4 :printf("thursday");
                   break;
            case 5 :printf("friday");
                   break;
            case 6 :printf("saturday");
                   break;
            case 7 :printf("sunday");
                   break;


        default: printf("not a valid day");
        }

    }
    */
    // if u remove the break statement after the cases then the which ever number u give from there it will go on till end
    // for example if u give it 3 then from wednsday it will print till sunday
    // also u can have nested cases

    // wap which gives days of weeks thru char
    /*
    #include<stdio.h>
    int main (){
        char day;
        printf("enter the first letters");
        scanf("%c",& day);
        switch (day)
        {
            case 'm' :printf("monday");
                   break;
            case 't' :printf("tuesday");
                   break;
            case 'w' :printf("wednsday");
                   break;
            case 'T' :printf("thursday");
                   break;
            case 'f' :printf("friday");
                   break;
            case 'S' :printf("saturday");
                   break;
            case 's' :printf("sunday");
                   break;

        default:printf("the entered char is not correct ");
            break;
        }
    }
    */

    // wap to print a +ve even number
    /*
    #include<stdio.h>
    int main ()
    {
        int a;
        printf("enter the number");
        scanf("%d",&a);
        if (a>0)
        {
            if (a%2==0){
                printf("its a even no.");
            }
            else
            {
                printf("its odd");
            }
        }
        else
        {
            printf("its a negative number");
        }
    }
    */
    // wap to check if a student pass or failed
    /*
    #include<stdio.h>
    int main()
    {
        int marks;
        printf("enter the student marks");
        scanf("%d",&marks);
        // if (marks<=30)
        // {
        //     printf("FAIL");
        // }
        // else if (marks>30 && marks<=100)
        // {
        //     printf("PASS");
        // }
        // else
        // {
        //     printf("you have entered the wrong number");
        // }
        marks<=30 ? printf("FAIL") : printf("PASS");
    */
    // wap to give grades to a student
    /*
    #include<stdio.h>
    int main ()
    {
        int marks;
        printf("enter the marks");
        scanf("%d",& marks);
        if (marks<30)
        {
            printf("C");
        }
        else if (marks>=30 && marks<70)
        {
            printf("B");
        }
        else if (marks>=70 && marks<90)
        {
            printf("A");
        }
        else if (90<=marks && marks<=100)
        {
            printf("A+");
        }


    }
    */
    // practice question find the output
/*
    #include<stdio.h>
    int main ()
    {
        int x=2;
        if(x=1){
            printf("one");
        }
        else{
            printf("not one");
        }
    }
*/
    // output is one
    // wap to check if a charecter is uppercase or not

    /*int main()
    {
        char ch;
        printf("enter the charecter");
        scanf("%c",&ch);
        if (ch>='A' && ch<='Z')
        {
            printf("its uppercase");
        }
        else{
            printf("its lowercase");
        }
    }
    */
    // loop control instructions
    /*
    #include<stdio.h>
    int main()
    {
        int i ;
        for (i=1;i<=100;i++){
            printf("hello mate \n");
        }
    }


    */
    // print 1-100 using for loop
    /*
    #include<stdio.h>
    int main()
    {
        int i ;
        for(i=1;i<=100;i++)
        {
            printf("%d\n",i);
        }
    }
    */
    // print 1-100 using while
    /*
    #include<stdio.h>
    int main()
    {
        int i;
        while(i<=100)
        {
            printf("%d\n",i);
            i++;
        }
        return 0;
    }*/
    // using do while loop
    /*
    #include<stdio.h>
    int main()
    {
        int i;
        i=1;
        do{
            printf("%d\n",i);
            i++;
        }
        while(i<=100);
        return 0;
    }*/

    /*
    #include<stdio.h>
    int main()
    {
        int n,i=0;
        printf("enter the number:");
        scanf("%d",&n);
        //while(i<=n){
            //printf("%d\n",i);
            //i++;
        //for(i;i<=n;i++){
            //printf("%d\n",i);
        //}

    }
    */

    // wap to print sum of 1st n natural numbers and print in reverse

    /*
    #include<stdio.h>
    int main()
    {
        int n;
        printf("enter the numner");
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+i;
        }
        printf("sum is :%d\n",sum);
        for(int j=n;j>=1;j--){
            printf("%d\n",j);
        }
        return 0;

    }*/

    // wapt to print no. from 1.00 to 5.00

    /*
    #include<stdio.h>
    int main()
    {
        for(float i=1.0;i<=5.0;i++)
        {
            printf("%f\n",i);
        }
    }*/

    // wap to print a to z alphabets
    /*
    #include<stdio.h>
    int main()
    {
        for(char c=65;c<=90;c++)//ascii values
        //for(char='a';char<='z';c++)
        {
            printf("%c\n",c);
        }
    }*/

    // using the while loops

    /*
    #include<stdio.h>
    int main()
    {
        int i=1;
        while(i<=50){
            printf("%d\n",i);
            i++;
        }
    }*/
    // using the do while loop

    /*
    #include<stdio.h>
    int main()
    {
        int i=1;
        do{
            printf("%d\n",i);
            i++;
        }while(i<=10);
    }
    */

    // print the sum of first n natural numbers and print them in reverse
    /*
    #include<stdio.h>
    int main()
    {
        int sum=0,i=1,n;
        printf("enter the number");
        scanf("%d",&n);
        //for(i;i<=n;i++){
            //sum=sum+i;
        //}
        //printf("%d\n",sum);
        //for(int j=n;j>=1;j--){
            //printf("%d\n",j);
        //}
        for(int i=1,j=n;i<=n && j>=1;i++,j--){
            sum=sum+i;
            printf("%d\n",j);
            //printf("%d\n",i);

        }
        printf("%d",sum);

    }
    */
    // wap to print the table of a given number
/*   
    #include<stdio.h>
    int main()
    {
        int n;
        printf("enter the number");
        scanf("%d",&n);
        for(int i=1;i<=10;i++){
            int p = n*i;
            //printf("%d",n," * ","%d",i," = ","%d",p,"\n");
            printf("%d X %d = %d \n", n,i,p);
        }

    }
*/


    // Break statements, break after 3
    /*
    #include<stdio.h>
    int main()
    {
        for(int i=1;i<=5;i++)
        {
            if(i==3){
                break;
            }
            printf("%d\n",i);


        }
        printf("have a break,have a kitkat");
    }
    */

    // keep taking input from user until a odd number is entered
    /*
    #include<stdio.h>
    int main()
    {
        int n;
        /*
        do{
            printf("enter the number");
            scanf("%d",&n);
        }while(n%2==0);
        */
    /*do{
        printf("enter the number:");
        scanf("%d",&n);
        printf("%d\n",n);
        if(n%2!=0){
            break;
        }
    }while(1);
 }
 */

    // wap to keep taking input untill a multiple of 7
    /*
    #include<stdio.h>
    int main()
    {
        int n;
        do{
            printf("enter the number");
            scanf("%d",&n);
            if(n%7==0){
                break;
            }
        }while(1);
    }*/

    // Continue statement:skips to next iteration
    // wap to remove 3 while printing from 1-5:
    /*
    #include<stdio.h>
    int main()
    {
        int n;
        for(int i=1;i<=5;i++){
            if(i==3){
                continue;
            }
            printf("%d",i);
        }
    }
    */
    // wap to print number from 1-10 without 6
    /*
    #include<stdio.h>
    int main()
    {
        int n;
        for(int i=1;i<=10;i++){
            if(i==6){
                continue;
            }
            printf("%d",i);

        }
    }*/
    // wap to print odd numbers from 5-50
    /*
    #include<stdio.h>
    int main()
    {
        for(int i=5;i<=50;i++){
            if (i%2!=0)
            {
                printf("%d\n",i);
            }

        }


    }*/
    // wap to print factorial of a number
    /*
    #include<stdio.h>
    int main()
    {
        int n,a=1;
        printf("enter the number");
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            if(n==0){
                printf("%d",1);
            }
            else if(n==1){
                printf("%d",1);
            }
            a=a*i;

        }
        printf("factorial:%d",a);

    }*/

    // wap to print the reverse table of number n
    /*
    #include<stdio.h>
    int main()
    {
        int n;
        printf("enter the number");
        scanf("%d",&n);
        for(int i=10;i>=1;i--){
            int p=n*i;
            printf("%d X %d = %d\n",n,i,p);
        }
    }*/
    
    #include<stdio.h>
    int main()
    {
        for(int i=1;i<=3;i++){
            for(int j=1;j<=i;j++){
                printf("*");
            }
            printf("\n");
        }
    }
    