#include<iostream>
using namespace std;

int main (){
    /*
    int a;
    a=12;
    cout<<"size of int "<<a<<endl;

    float b;
    cout<<"size of float "<<b<<endl;

    char c;
    cout<<"size of char "<<c<<endl;

    int d;
    cout<<"size of int"<<d<<endl;

    cout<<"Hello World\n";

    int amnt1;
    cout<<"1:";
    cin>>amnt1;

    int amnt2;
    cout<<"2:";
    cin>>amnt2;

    int sum=amnt1+amnt2;
    cout<<sum;

    for (int i=0; i<10; i++){

        cout<<"Wassup ";
    }
    */
    int i=10;
    while(i>0){
    i--;
    cout<<i;
    }
    i=10;
    do{
        i--;
        cout<<i;
    }while(i>0);
    return 0;  
}