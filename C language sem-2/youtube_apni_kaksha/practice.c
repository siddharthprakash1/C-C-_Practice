/*
#include<stdio.h>
void printhello();
int main ()

{
    printf("Fuction for printing HEllo ");
    printhello();
}
void printhello(){
    printf("HELLO");
}*/
/*
#include<stdio.h>
int square(int n);
int main()
{
    int n;
    printf("enter the number");
    scanf("%d",&n);
    printf("%d",square(n));
}
int square(int n){
    return n*n;
}*/

/*
#include<stdio.h>
int factorial(int n);
int main()
{
    int n;
    printf("enter the values");
    scanf("%d",&n);
    printf("%d",factorial(n));
    return 0;9+

}
int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}
*/

//#include<stdio.h>
//int main()
/*
{
    int age=22;
    int *ptr=&age;
    printf("%d\n",age);
    printf("%d",*ptr);n 
}*/
//print the value of i from its pointer
/*
{
    int i=5;
    int *ptr=&i;
    int **pptr=&ptr;
    printf("%d",*(&(*ptr)));

}*/

///////pointer and function 
//call by value

//calender in c:
/*
#include<stdio.h>
#include<conio.h>
#include<windows.h>

int getkey();
void display(int,int,int,int[]);
void calendar(int,int);

//-------------- GOTO function definition ----------------------
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//------------ Change color -------------------
void SetColor(int ForgC)
{
     WORD wColor;
                          //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                           //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                     //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
char *week[]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

int main()
{
    int nmonth,nyr,ch;
    enteryear:
    while(1)
    {
        printf("Enter year and month(number):" );
        scanf("%d%d",&nyr,&nmonth);
        if(nyr<1945)
        {
            //If year less than 1945
            printf("\n\t Please enter year above 1945\n");
            continue;
        }
        else
        {
            //If year greater than equal to 1945
            calendar(nyr,nmonth);
        }
        while(1)
        {
        gotoxy(20,20);printf("(*) Use LEFT, RIGHT, UP and DOWN arrow.");
        gotoxy(20,22);printf("(*) Press P to go to particular year and month.");
        gotoxy(20,24);printf("(*) Press ESC to Exit.");
        ch=getkey();
        switch(ch)
        {
        case 80: //-------- DOWN ARROW -----------
               //Increasing month
                if(nmonth==12)
                {
                    //Jump to next year if month is december
                     nmonth=1;
                     nyr++;
                }
                else
                {
                    nmonth++;
                }
                calendar(nyr,nmonth);
                break;
        case 77: //-------- RIGHT ARROW ----------
            //Increasing Year
                nyr++;
                calendar(nyr,nmonth);
                break;
        case 72: //------- UP ARROW -------------
            // Decreasing Month
                if(nmonth==1)
                {
                    // Jump to previous year if month is january
                    nyr--;
                    nmonth=12;
                }
                else
                    nmonth--;
                calendar(nyr,nmonth);
                break;
        case 75: //-------- LEFT ARROW ----------
            //Decreasing year
                if(nyr==1945)
                {
                    //If year is 1945 and we click left arrow than
                  gotoxy(15,2);printf("Year below 1945 not available");
                }
                else
                {
                    nyr--;
                    calendar(nyr,nmonth);
                }

                break;
        case 27: //--------- ESC KEY ------------
            //Exit program
                system("cls");
                gotoxy(50,14);printf("Exiting program.\n\n\n\n\n");
                exit(0);
        case 112://---------- p KEY ------------
            //Go to particular year and month
                system("cls");
                goto enteryear;
        }
        }
        break;

    }
    getch();
    return 0;
}


//============== DISPLAYING THE  CALENDAR ===================
void display(int nyr,int nmonth,int tdays,int days[])
{
    int i,j,pos;
    SetColor(12); //Color red
    gotoxy(56,6);printf("%s %d",month[nmonth-1],nyr); //Heading year and month dispalying
    for(i=0,pos=30;i<7;i++,pos+=10)
    {
         if(i==6)
            break;//SetColor(9); //Sunday color blue
         else
            break;SetColor(10);  //Others day color green
        gotoxy(pos,8);printf("%s",week[i]);
    }

    //SetColor(15); //setting the color white

   tdays++; //incrementing the tdays by 1
    if(tdays==0 || tdays==7)
        pos=91; //if tdays is 0 or 7, position is sunday
    if(tdays==1)
        pos=31; //if tdays is 1, position is monday
    if(tdays==2)
        pos=41;  //if tdays is 2, position is tuesday
    if(tdays==3)
        pos=51;  //if tdays is 3, position is wednesday
    if(tdays==4)
        pos=61;  //if tdays is 4, position is thursday
    if(tdays==5)
        pos=71;  //if tdays is 5, position is friday
    if(tdays==6)
        pos=81;  //if tdays is 6, position is saturday

    for(i=0,j=10,pos;i<days[nmonth-1];i++,pos+=10)
    {
        if(pos==91)
            break ;//SetColor(8); //Changing color to dark grey for sunday
        else
            break ;//SetColor(7); //Changing color to white for all days

        gotoxy(pos,j);printf("%d",i+1);
        if(pos==91)
        {
            pos=21; //Moving position to monday
            j++;  //Increasing j by 10 if position is sunday
        }
    }

    //SetColor(5); //Changing color to purple

    //Drawing horizontal line
    for(i=22;i<102;i++)
    {
        gotoxy(i,4);printf("%c",196);
        gotoxy(i,17);printf("%c",196);
    }

    //Drawing all the corner of the rectangle
    gotoxy(21,4);printf("%c",218);
    gotoxy(102,4);printf("%c",191);
    gotoxy(21,17);printf("%c",192);
    gotoxy(102,17);printf("%c",217);

    //Drawing vertical line
    for(i=5;i<17;i++)
    {
        gotoxy(21,i);printf("%c",179);
        gotoxy(102,i);printf("%c",179);
    }

    //SetColor(11); //Changing color to aqua

    //Drawing left and the right navigation symbol
    gotoxy(24,11);printf("%c",174);
    gotoxy(98,11);printf("%c",175);

}

//==============  ARROW KEY ===============
int getkey()
{
    int ch;
    ch=getch();
     if(ch==0)
    {
        printf("zero");
        ch=getch();

        return ch;
    }
    return ch;
}

//============ Calculating ====================
void calendar(int nyr,int nmonth)
{
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int tdays=0,k,myear;
    system("cls");
    myear=nyr-1; //Decreasing year by 1
            if(myear>=1945)
            {
                for(k=1945;k<=myear;k++)
                {
                    if(k%4==0) //If the year is a leap year than total no of days is 366
                        tdays=tdays+366;  //counting all the days till nyr - 1
                    else //If the year is a leap year than total no of days is 365
                        tdays=tdays+365;  //counting all the days till nyr - 1
                }
            }

            if(nyr%4==0)
                days[1]=29; //changing value in days array from 28 to 29 since leap year
            else
                days[1]=28; //changing value in days array from 29 to 28 since not a leap year

            for(k=0;k<(nmonth-1);k++)
            {

                tdays=tdays+days[k]; //Adding nmonth-1 days to tdays
            }

            tdays=tdays%7; //Finding the remainder of tdays so it can calculate the position to display
            display(nyr,nmonth,tdays,days); //Passing the value to display
}
*/
/*
#include<stdio.h>
int square(int m);
int main(){
    int m;
    printf("enter the number");
    scanf("%d",&m);
    printf("%d",square(m));
}
int square(int m){
    return m*m;
}*/
/*
#include<stdio.h>
int fact(int n);
int main ()
{
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    printf("the factorial of the number is:%d",fact(n));
    return 0;
}
int fact(int n){
    if(n==0)
        return 1;
    int x=fact(n-1);
    int fact(n)=n*x;
    



}*/
/*
#include <stdio.h>
#include <stdlib.h>
  
int main()
{

   FILE *fp1 = fopen("file1.txt", "r");
   FILE *fp2 = fopen("file2.txt", "r");
  
   FILE *fp3 = fopen("file3.txt", "w");
   char c;
  
   if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
   {
         puts("files are merged");
         exit(0);
   }
  

   while ((c = fgetc(fp1)) != EOF)
      fputc(c, fp3);
  
   while ((c = fgetc(fp2)) != EOF)
      fputc(c, fp3);
  
   printf("Merged file1.txt and file2.txt into file3.txt");
  
   fclose(fp1);
   fclose(fp2);
   fclose(fp3);
   return 0;
}*/
/*
#include<stdio.h>
int main (){
    int n;
    printf("enter the length of the cube:");
    scanf("%d",&n);
    FILE *fptr;
    fptr=fopen("hi.txt","w");
    fprintf(fptr,"%d",n*n*n);


}*/
/*
#include<stdio.h>
int main ()
{
    char arr[100];
    fgets(arr,100,stdin);
    puts(arr);
}*/
/*
#include<stdio.h>
#include<string.h>
int main (){
    char arr[100];
    fgets(arr,100,stdin);
    puts(arr);
    printf("%d",strlen(arr)-1);
    int sum=0;
    for(int i=0; arr[i] !='\0';i++){
        sum++;
    }
}
*/
/*
#include<stdio.h>
#include<string.h>
int main ()
{
    char arr1[100];
    char arr2[100];
    fgets(arr1,100,stdin);
    fgets(arr2,100,stdin);
    strcat(arr1,arr2);
    printf("%s",arr1);
    printf("%d",strcmp(arr1,arr2));
    strcpy(arr1,arr2);
    printf("%s",arr1);
    printf("%d,%d",strlen(arr1),strlen(arr2));
}*/
/*
#include<stdio.h>
int main ()
{
    char arr[100];
    scanf("%c",&arr[]);
}*/
/*
#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    char name[100];
    float cgpa;
};
int main () 
{
 struct student s1;
 s1.roll=523;
 s1.cgpa=9.32;
 strcpy(s1.name,"SIDDHARTH");
 printf("%d\n",s1.roll);
 scanf("%f\n",s1.cgpa);
 printf("%s",s1.name);
}*/
#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    float cgpa;
    char name[100];
};
int main ()
{
    struct student ece[100];//here ece[100]means there are students in ece 
    ece[0].roll=234;
    ece[0].cgpa=8.23;
    strcpy(ece[0].name, "Dia");
    printf("the name of the student is %s\nThe cgpa of the student is %f \nThe roll number of the student is %d",ece[0].name,ece[0].cgpa,ece[0].roll);
    return 0;
}