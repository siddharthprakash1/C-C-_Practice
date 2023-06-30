/*
a charecter arrray terminated by a '\o'(null charecter) null charecter
denotes string termination 
*/
/*#include<stdio.h>
int main()
{
    char name[]={'s','i','d','\0'};
    //char F[]={'s','i','d','','i','s','','i','n','','g','y','m','\0'};
    char P[]="name is sid";
    printf("%s\n",name);
    //printf("%s",F);
    printf("%s",P);
}*/

/*
#include<stdio.h>
int main()
{
    char firstname[]="Siddharth";
    char lastname[]="Prakash";
    for(int i=0;i<sizeof(firstname);i++){ //for(int i=0;i!='\0';i++)
        printf("%c",firstname[i]);
    }
    for(int i=0;i<sizeof(lastname);i++){  //for(int i=0;i!='\0';i++)
        printf("%c",lastname[i]);
    }
}*/
//ASK the user to enter their name and print it 
/*
#include<stdio.h>
int main(){
    char firstname[50];
    char lastname[50];
    printf("enter the 1st name:");
    scanf("%s",firstname);
    printf("enter the lastname:");
    scanf("%s",lastname);
    printf("%s\n",firstname);
    printf("%s",lastname);
}*/
//STRING FUNCTION 
/*
#include<stdio.h>
int main(){
    char str[100];
    gets(str);//this is old and dangerous since it can be hacked 
    puts(str);
    return 0;
}
*/
/*
#include<stdio.h>
int main(){
    char str[100];
    fgets(str,100,stdin);//here we use fgets since its much safer 
    puts(str);
}
*/
//make a program that inputs user's name and prints its length
/*
#include<stdio.h>
int main()
{
    char name[100];
    printf("enter the name ");
    fgets(name,100,stdin);
    puts(name);
    int sum=0;
    for(int i=0;name[i]!='\0';i++){//here in this for loop if u change name[i]=h then it counts no.of h in the string u passed ......Like this u can have diffrent questions
        sum++;
    }
    printf("the length of string is %d",sum);
}*/
//standard library functions
//previous Question shortcut
/*
#include<stdio.h>
#include<string.h>
int main(){
    char name[100];
    fgets(name,100,stdin);
    puts(name);
    int c=strlen(name);
    printf("%d",c-1);
}*/
//2nd fn(strcpy)
/*
#include<stdio.h>
#include<string.h>
int main()
{
    char newstr[]="Siddharth";
    printf("%s\n",newstr);
    char oldstr[]="NETWORKING";
    strcpy(newstr,oldstr);
    printf("%s",newstr);
}*/
//3rd fn
//strcat(firstStr,secondstr);it concatenates (without any space untill manually given) the 1st string with the second string
/*
#include<stdio.h>
#include<string.h>
int main()
{
    char firststr[]="Siddharth";
    char secondstr[]="NETWORKING";
    strcat(firststr,secondstr);
    printf("%s",firststr);//so here they concatenates
}*/
//4th fn
//strcmp(firstSTR,secSTR); Compares 2 strings & returns a value 
/*
#include<stdio.h>
#include<string.h>
int main()
{
    char firststr[]="Siddharth";
    char secondstr[]="NETWORKING";
     
}*/
//take a input from the user using %c
/*9
#include<stdio.h>
//void printstring(char arr[]);
int main(){
      char str[100];
      char ch;
      int i=0;
      while(ch!='\n'){
        scanf("%c",&ch);
        str[i]=ch;
        i++;
        }
        str[i]='\0';
        puts(str);
}
*/

//find the salted password entered by user if the salt is "123"&added at the end 
/*
#include<stdio.h>
#include<string.h>
void salting(char pass[]);
int main()
{
    char pass[100];
    scanf("%s",pass);
    salting(pass);
}
void salting(char pass[]){
    char salt[]="123";
    char newpass[200];
    strcpy(newpass,pass);
    strcat(newpass,salt);
    puts(newpass);
}
*/

//same answer without using function
/*
#include<stdio.h>
#include<string.h>
int main()
{
    char pass[100];
    scanf("%s",&pass);
    char c[]="123";
    char newpass[200];
    strcpy(newpass,pass);
    strcat(newpass,c);
    puts(newpass);
}
*/

//waf named slice which takes a string and returns a sliced string from index n to m 
/*
#include<stdio.h>
#include<string.h>
void slice(char str[],int m,int n);
int main()
{
   
    char str[]="helloworld";
    slice(str,2,4);
    //int m,n;
    //fgets(str,100,stdin);
    //printf("enter the index:");
    //scanf("%d%d",m,n);
    //slice(str,m,n);
}
void slice(char str[],int m,int n){
    //for(int i=m;i<=n;i++){
        //printf("%c",str[i]);
    //
    char newstr[100];
    for(int i=m,j=0;i<=n;i++,j++){
        newstr[j]=str[i];
        }
    puts(newstr);
    }

*/
//waf to count the number of vowels in a string
/*
#include<stdio.h>
#include<string.h>
int count(char str[]);
int main()
{
    char str[]="helloworld";
    printf("no.of vowels in the above string is %d",count(str));
}
int count(char str[]){
    int count=0;
    for(int i=0;str[i] != '\0'; i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            count++;
        }
    }
    return count;
}
*/

//wap to check if a given charecter is present in a string or not
/*
#include<stdio.h>
void check(char [],char []);
int main(){
    char str[]="sid sdi dsi dis isd ids";
    char ch[]="i";
    check(str, ch);
}
void check(char str[],char ch[]){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==ch[0]){
            printf("True\n");
    }
}//u cannot use return function to in void to return , only in int it is allowed 
}
*/
//=======================================================================
//..........STRUCTURES......................

//example:
/*
#include<stdio.h>
#include<string.h>
//here u make a user defined data type 
struct student
{
    int srn;
    float cgpa;
    char name[100];
};
int main()
{
    struct student s1;//here we are making a variable s1 of struct data type to 
    s1.srn=523;
    s1.cgpa=9.2;
    //s1.name= //here this is wrong since the strings u define as an array cannot be changed that string u can copy,compare....But its value cant be changed 
    //if it was charecter pointer then we could have changed it 
    strcpy(s1.name,"SIDDHARTH");
    printf("student name is %s\n",s1.name);//Note here u cant write only s1 u have to write s1.name 
    printf("student name is %d\n",s1.srn);
    printf("student name is %f\n",s1.cgpa);
}*/
//wap to store and print data of 3 students 
/*
#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    float cgpa;
    char name[100];
};
int main(){
    struct student s1,s2,s3;
    s1.cgpa=10;
    s2.cgpa=9;
    s3.cgpa=9.32;
    s1.roll=123;
    s2.roll=523;
    s3.roll=234;
    strcpy(s2.name,"SIDDHARTH");
    strcpy(s1.name,"CB");
    strcpy(s2.name,"john");
    printf("the student name is %s\nthe roll number is %d\nthe cgpas obtainded is %f",s1.name,s1.roll,s1.cgpa);
    printf("\nthe student name is %s\nthe roll number is %d\nthe cgpas obtainded is %f",s2.name,s2.roll,s2.cgpa);
    printf("\nthe student name is %s\nthe roll number is %d\nthe cgpas obtainded is %f",s3 .name,s3.roll,s3.cgpa);
    return 0;
}*/

//ARRAY of STRUCTURES
/* 
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



//direct intialization of structure
 /*
 #include<stdio.h>
#include<string.h>
struct student{
    int roll;
    float cgpa;
    char name[100];
};
int main(){
    struct student s1={523,9.43,"sid"};
    struct student s2={389,9.12,"nik"};
    printf("roll no.of of %s is %d",s1.name,s1.roll);
    return 0;
}
*/
//pointer in structure and arrow operator 

/*
#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    float cgpa;
    char name[100];
};
int main(){
    struct student s1={523,9,"sid"};
    struct student s2={335,9.34,"nik"};
    struct student *ptr1=&s2;
    struct student *ptr=&s1;//here the pointer points at the student s1's data 
    //printf("the roll number of %s is %d",(*ptr).name);//*(ptr) gives an error 
    printf("the roll number of %s is %d and cgpa is %f",ptr->name,ptr->roll,ptr->cgpa);
    printf("the name%s , the roll number %d and the cgpa is %f",ptr1->name,ptr1->roll,ptr1->cgpa);
    return 0;  
}
*/
//Arrow Operator
/*
here insted of using (*ptr).roll or (*ptr).name we can use arrow operator
that is ptr->roll and ptr->name sicne (*ptr).roll or (*ptr).name is comlex
*/
//passing Structure to Functions 
/*
#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    float cgpa;
    char name[100];
};
void printinfo(struct student s1);
int main()
{
    struct student s1={523,93.2,"sid"};
    printinfo(s1);
    return 0;
}
void printinfo(struct student s1){
    printf("the name%s , the roll number %d and the cgpa is %f",s1.name,s1.roll,s1.cgpa);
} */
//typedef Keyword 
//used to create alias for data types creates aa nick name 
/*
#include<stdio.h>
#include<string.h>
typedef struct  student{
    int roll ;
    float cgpa;
    char name[100];
}stu;
int main (){
    stu s1; //doubt why not struct stu s1={523,93.2,"sid"}
    s1.cgpa=9.6;
    //s1.name="sid"; //cant use this error
    strcpy(s1.name,"Sid");
    s1.roll=523;
    printf("the student name is %s",s1.name);
}*/

//take input of the address of 5 people
/*
#include<stdio.h>
#include<string.h>
struct address{
    int housenumber;
    char block[100];
    char city[100];
    char state[100];
};
void printinfo(struct address s1);
int main(){
    struct address s1;
    printinfo(s1);
    struct address s2;
    printinfo(s2);
    struct address s3;
    printinfo(s3);
    struct address s4;
    printinfo(s4);
    struct address s5;
    printinfo(s5);
}
void printinfo(struct address s1){
    printf("\nenter the house number:");
    scanf("%d",&s1.housenumber);
    printf("enter the block:");
    scanf("%s",&s1.block);
    printf("enter the city:");
    scanf("%s",&s1.city);
    printf("enter the state:");
    scanf("%s",&s1.state);
    printf("the address is:\n%d-%s\n%s %s",s1.housenumber,s1.block,s1.city,s1.state);
}
*/
//now using arrays in c
/*
#include<stdio.h>
#include<string.h>
struct address{
    int housenumber;
    int block;
    char city[100];
    char state[100];
};
void printadd(struct address add);
int main(){
    struct address p[5];
    printf("make the entery for person1");
    printf("\nenter the house number:");
    scanf("%d",&p[0].housenumber);
    printf("enter the block:");
    scanf("%s",&p[0].block);
    printf("enter the city:");
    scanf("%s",&p[0].city);
    printf("enter the state:");
    scanf("%s",&p[0].state);
    
    printf("make the entery for person2");
    printf("\nenter the house number:");
    scanf("%d",&p[1].housenumber);
    printf("enter the block:");
    scanf("%s",&p[1].block);
    printf("enter the city:");
    scanf("%s",&p[1].city);
    printf("enter the state:");
    scanf("%s",&p[1].state);

    printf("make the entery for person3");
    printf("\nenter the house number:");
    scanf("%d",&p[2].housenumber);
    printf("enter the block:");
    scanf("%s",&p[2].block);
    printf("enter the city:");
    scanf("%s",&p[2].city);
    printf("enter the state:");
    scanf("%s",&p[2].state);

    printf("make the entery for person4");
    printf("\nenter the house number:");
    scanf("%d",&p[3].housenumber);
    printf("enter the block:");
    scanf("%s",&p[3].block);
    printf("enter the city:");
    scanf("%s",&p[3].city);
    printf("enter the state:");
    scanf("%s",&p[3].state);

    printf("make the entery for person5");
    printf("\nenter the house number:");
    scanf("%d",&p[4].housenumber);
    printf("enter the block:");
    scanf("%s",&p[4].block);
    printf("enter the city:");
    scanf("%s",&p[4].city);
    printf("enter the state:");
    scanf("%s",&p[4].state);
    printadd(p[0]);
    printadd(p[1]);
    printadd(p[2]);
    printadd(p[3]);
    printadd(p[4]);
}
void printadd(struct address add){
      printf("the address is:\n%d-%d\n%s %s",add.housenumber,add.block,add.city,add.state);
}
*/

//create a structue to store vectors and make a function to return sum of 2 vectors
/*
#include<stdio.h>
#include<string.h>
struct vector{
    int x;
    int y;
};
void sum(struct vector v1,struct vector v2);
int main(){
    struct vector v1;
    struct vector v2;
    printf("enter the x coordiantes of of 1st vector");
    scanf("%d",&v1.x);
    printf("enter the y coordiantes of of 1st vector");
    scanf("%d",&v1.y);
    printf("enter the x coordiantes of of 2nd vector");
    scanf("%d",&v2.x);
    printf("enter the y coordiantes of of 2nd vector");
    scanf("%d",&v2.y);
    sum(v1,v2);
}
void sum(struct vector v1,struct vector v2){
    printf("the vector sum is:\n%di+%dj",v1.x+v2.x,v1.y+v2.y);
}

*/

//use structure to store complex number and use arrow operator
/*
#include<stdio.h>
#include<string.h>
struct complexnumber
{
    int r;
    int c;
};
int main()
{
    struct complexnumber cn1;
    struct complexnumber *ptr=&cn1;
    printf("enter the real part");
    scanf("%d",&ptr->r);
    printf("enter the imaginary part");
    scanf("%d",&ptr->c);
    printf("the entered complex number is %d+%di",ptr->r,ptr->c);
}*/

//make a structure to store the bank account information of a customer of a bamk also make a allias for it 
/*
#include<stdio.h>
#include<string.h>
typedef struct statebankofIndia{
    int accountnumber;
    char name[100];//dont forget this 
}sbi;
int main()
{
    sbi p1;
    printf("ENTER THE ACCOUNT NUMBER=");
    scanf("%d",&p1.accountnumber);
    printf("enter the name=");
    scanf("%s",&p1.name);
    printf("the bank info of p1 is\nname=%s\naccountnumber=%d",p1.name,p1.accountnumber);   
}*/
//make a structure for ur college like student,attendence, cgpa, teachers , branches


//=========================================
/*
#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    char name[100];
    int  cgpa;
};
int main(){
    //struct student s1;
    //struct student *s3;
    //printf("%d \n%d",sizeof(s1),sizeof(s3));//108 4
    struct student s1={523,"sid",9.32};
    struct student s2={523,"sid",9.32};
    //if(s1==s2)//here u get error since to compare two structure here we have to take individual terms 
    if(s1.roll==s2.roll && (!(strcmp(s1.name,s2.name))) && s1.cgpa==s2.cgpa)
        printf("equal");
    else
        printf("not equal");
    //here we used ! since on comparing we would gotten zero in strcmp and is zero comes it makes the whole and zero so we have reverse it 

}*/

//copying s1 in s2 
/*
#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    char name[100];
    int  cgpa;
};
int main(){
    struct student s1={523,"sid",9.32};
    struct student s2=s1;
    printf("%d %s %d",s2.roll,s2.name,s2.cgpa);
}
*/
//nested structures 
/*
#include<stdio.h>
struct dob{
    int dd;
    int mm;
    int yy;
};
struct student{
    int roll;
    char name[100];
    int  cgpa;
    struct dob d1;
};
int main()
{
    struct student s1={523,"SIDDHARTH",9,{11,9,2003}};
    printf("%d the birthday date is ",s1.d1.dd);
}*/
//u can also doo nesting like this 
/*
#include<stdio.h>
struct student{
    int roll;
    char name[100];
    int  cgpa;
    struct dob{
    int dd;
    int mm;
    int yy;
    }d1;
};
int main()
{
    struct student s1={523,"SIDDHARTH",9,{11,9,2003}};
    printf("%d the birthday date is ",s1.d1.dd);
}*/

//DYNAMIC MEMORY ALLOCATION
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    ptr=(int *)malloc(5*sizeof(int));//hereptr=(int *)malloc(500000000000000000*sizeof(int)) if u give large number like this then the memory u ask exceeds the memory of the comp so u get null 
    ptr[0]=1;//here u can use same notation as that of array 
    //in array memory is fixed but here its not 
    //memory is allocated at run time not compile time 
    ptr[1]=2;
    ptr[2]=2;
    ptr[3]=3;
    ptr[4]=4;
    ptr[5]=5;
    ptr[6]=6;
    ptr[7]=7;
    for(int i=0;i<8;i++){
        printf("%d\n",ptr[i]);
    }
    return 0;
}
*/

//wap to allocate memory to store 5 prices(*FLOAT)
/*
#include<stdio.h>
#include<stdlib.h>
int main(){
    float *ptr;
    ptr=(float *) calloc(5,sizeof(float));
    for(int i=0;i<5;i++){
        printf("%f\n",ptr[i]);
    }
    
}
*/
//another way 
/*
#include<stdio.h>
#include<stdlib.h>
int main (){
    float *ptr;
    ptr=(float *)malloc(5*sizeof(float));
    for(int i=0;i<=4;i++){
        printf("enter the price");
        scanf("%f",&ptr[i]);
    }
    for(int i=0;i<=4;i++){
        printf("the price entered is:\n%f\n",ptr[i]);
    }
}
*/
//calloc 
/*
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    ptr=(int *)calloc(5,sizeof(int));
    for(int i=0;i<=4;i++)
    {
        printf("%d\n",ptr[i]);
    }
}
*/

//wap to allocate memory of size n where n is entered by the user 
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    int n;
    printf("enter the size of memory you need:");
    scanf("%d",&n);
    ptr=(int *)calloc(n,sizeof(int));//can also use a malloc here.
    //just to check print it 
    for(int i=0;i<n;i++){
        printf("%d\n",ptr[i]);
    }    

}


*/
//free pointer 
//free the memory allocated with calloc:
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    int n;
    scanf("%d",&n);
    ptr=(int *)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        printf("%d",&ptr[i]);
    }
    free(ptr);//here u have freed the pointer so it can be reused 
    ptr=(int *)calloc(2, sizeof(int));
    return 0;
}
*/


//allocate memory for 5 numbersthen dtnmically increast to 8
/*
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    ptr=(int *)calloc(5,sizeof(int));
    for(int i=0;i<=3;i++){
        printf("enter 4 values:");
        scanf("%d",&ptr[i]);
    }
    for(int i=0;i<=3;i++){
        printf("%d",ptr[i]);
    }
    printf("\n");
    ptr=realloc(ptr,8);
    printf("enter the numbers(8)");
    for(int i=0;i<=7;i++){
        scanf("%d\n",&ptr[i]);
    }
    for(int i=0;i<=7;i++){
        printf("%d\n",ptr[i]);
    }    
}
*/
//Allocate  memory to store first 5 odd numbers then reallocate it to store first 6 even numbers

//=============================================================================================
//FILE INPUT OUTPUT
/*
#include<stdio.h>
int main(){
    FILE *fptr;
    fptr=fopen("hi.txt","r");
    //if u wanna check if a file exist or not 
    if(fptr=NULL){
        printf("the file doesnot exist");
    }
    else{
        fclose(fptr);
    }
    return 0;

}
*/

//reading from a file
/*
#include<stdio.h>
int main(){
    FILE *fptr;
    fptr=fopen("hi.txt","r");
    char ch;
    fscanf(fptr,"%c",&ch);//here u can readin int  %d 
    printf("%c",ch);
    
    fclose(fptr);
    return 0;
}
*/
/*
#include<stdio.h>
int main(){
    FILE *fptr;
    fptr=fopen("hi.txt","w");
    char ch='m';
    fprintf(fptr,"%c",ch);
}
*/
//use of fputc and fgetc
/*
#include<stdio.h>
int main()
{
    FILE *fptr;
    fptr=fopen("hi.txt","r");
    printf("%c",fgetc(fptr));
}
*/

/*
#include<stdio.h>
int main ()
{
    FILE *fptr;
    fptr=fopen("hi.txt","w");
    fputc('G',fptr);
    fputc('Y',fptr);
    fputc('M',fptr);
}
*/

//use of EOF
/*
#include<stdio.h>
int main(){
    FILE *fptr;
    fptr=fopen("hi.txt","r");
    char ch;
    ch=fgetc(fptr);
    while(ch != EOF){
        printf("%c",ch);
        ch=fgetc(fptr);
    }
    printf("\n");
    fclose(fptr);
    return 0;
}*/
//enter 5 number from a file 
//doubt
//make a program to input student information from a user and enter it to a file 
/*
#include<string.h>
#include<stdio.h>
struct student{
    int roll;
    char name[100];
};
int main(){
    struct student  s1={123,"SIDDHARTH"};
    printf("%d\n",s1.roll);
    printf("%s",s1.name);
    FILE *fptr;
    fptr=fopen("demo.txt","w");
    fprintf(fptr,"%s\t",s1.name);
    fprintf(fptr,"%d",s1.roll);
    fclose(fptr);

}
*/

//wap to enter odd number in a file
/*
#include<stdio.h>
int main (){
    FILE *fptr;
    fptr=fopen("demo.txt","w");
    int n;
    printf("enter the number");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(i%2!=0){
            fprintf(fptr,"%d\n",i);
        }
    }
}*/
//wap to tkae number form a file and print thier sum 
/*
#include<stdio.h>
int main (){
    FILE *fptr;
    fptr=fopen("demo.txt","r");
    int n;
    fscanf(fptr,"%d",&n);
    int m;
    fscanf(fptr,"%d",&m);
    fclose(fptr);
    fptr=fopen("demo.txt","w");
    fprintf(fptr,"%d",n+m);
}*/
/*
#include<stdio.h>
int main(){
    printf("enter the number of elements u want to read form the ");
}*/
/*
#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fptr;
    fptr=fopen("datasetrvise.csv","r");
    char line[200];
    while(fgets(line,sizeof(line),fptr)!=NULL){
        char *token;
        token=strtok(line,",");
        while(token!=NULL){
            printf("  %s",token);
            token=strtok(NULL,",");
        }
        printf("/n");
    }

}/
*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main (){
    FILE *fptr;
    int n;
    printf("enter:");
    scanf("%d",&n);
    fptr=fopen("hi.txt","w");
    int a=n*n*n;
    fprintf(fptr,"%d",a);

}*/
/*
#include<stdio.h>
#include<errno.h>
#include<string.h>
int main(){
    FILE *fp=fopen("dem.txt","r");
    char ch=fgetc(fp);
    fputc(ch,stdout);
    printf("the error id is %d \nand the error is %s\n",errno,strerror(errno));
    perror("MESSAGE");
    errno=2;
    perror("BAD CODE");
    errno=2000;
    perror("BAD CODE");
    printf("file read sucessfully");
}

*/







//===================================================

//SEARCHING ALGO IN C 
/*
binary search
#include<stdio.h>
#include<stdlib.h>
int  my_search(int arr[],int low,int high,int s);
int main()
{
    int n;
    int s;
    int arr[100];
    FILE *fptr;
    fptr=fopen("hi.txt","r");
    printf("enter the numbrer of elements u want to read from the file ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        fscanf(fptr,"%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("%d\n",sizeof(arr));
    printf("Enter the element you want to search for ");
    scanf("%d",&s);
    //int pos =my_search(arr);
    int pos=my_search(arr,0,n,s);
    if(pos==-1)
        printf("unsuccesfull");
    else 
        printf("element availabel in the positon%d",pos);

    fclose(fptr);
}
int  my_search(int arr[],int low,int high,int s ){
    int pos=-1;
    int found=0;
    while(low<=high &&found==0){
        int mid =(low+high)/2;
        if(arr[mid]==s){
            pos =mid;
            found=1;
        }
        else if(arr[mid]<s)
            low=mid+1;
        else if(arr[mid]>s)
            high=mid-1;
    }
    return pos;
}*/
//==================================================================================
//selection sort
/*
#include<stdio.h>
void disp(int a[],int n);
void read(int a[],int n);
void swap(int *x,int *y);
void sort(int a[],int n);
int main(){
    int n;
    printf("enter the number of values");
    scanf("%d",&n);
    int a[50];
    read(a,n);
    printf("before sorting\n");
    disp(a,n);
    sort(a,n);
    printf("after sorting\n");
    disp(a,n);
    return 0;
}
void read(int a[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void disp(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void swap(int *x,int *y){
    int x1=*x;
    *x=*y;
    *y=x1;
     
}
void sort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        temp=i;
        for(j=i+1;j<n;j++)
        {
            if(a[temp]>a[j])
            {
                temp=j;
            }
        }
        if(temp!=i)
        {
        swap(&a[i],&a[j]);
        }
    }
}

*/
//=====================================================================================
//CALLBACK 
/*
#include<stdio.h>
void display()
{
    printf("this is the diplay fn\n");
}
int main()
{
    printf("this is the main function\n");
    display();
    int *p;//integer pointer 
    //funciton pointer 
    //1.return type
    //number and type of its parameter 
    void (*fn)();
    fn=display;
    fn();//invoke the display function 
    return 0;
}*/
//calculator
/*
#include<stdio.h>
int calculator(int(*op)(int,int,int),int a,int b ,int c);
{
//op is the operation u r performing(add,mul..)
    return op(a,b,c);
}
*/