/*
#include<stdio.h>
struct Sample{
    int a; 
    int *b;
};
int main()
{
    struct Sample s1;
    s1.a=100;
    s1.b=&(s1.a);
    printf("%d %d\n",s1.a,*(s1.b));
}*/
/*
#include<stdio.h>
int main()
{
    int a=0;
    int b=2;
    printf("%d",a&&b);
    printf("%d\n",a||b);
    printf("%d",a>b?a:b);
}*/
#include"headerDemo.h'
complex sum(complex *a,complex *b)
{
    complex sum;
    sum.re=a->re+b->re;
    sum.im=a->im+b->im;
    return complex;
}