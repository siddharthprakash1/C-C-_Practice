/*
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
        
    }
    return true;
}
int main(){
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(isPrime(i)){
            cout<<i<<endl;
        }
    }
}
*/
//fibnoacci
/*
#include<iostream>
#include<cmath>
using namespace std;

void fib(int n){
    int t1=0;
    int t2=1;
    int nextTerm;
    for(int i=1;i<=n;i++){
        cout<<t1<<endl;
        nextTerm=t1+t2;
        t1=t2;
        t2=nextTerm;
    }
}
int main(){
    int n;
    cin>>n;
    fib(n);
}
*/
//factorial and permutatin ncr
/*
#include<iostream>
#include<cmath>
using namespace std;

int fact(int n){
    int factorial=1;
    for(int i=2;i<=n;i++){
        factorial=factorial*i;
    }
    return factorial;    
}

    

int main (){
    int n,r;
    cin>>n>>r;
    cout<<fact(n)<<endl;
    cout<<fact(n)/(fact(n-r)*fact(r))<<endl;
    
}
*/
//Pascal Triangle
/*
#include<iostream>
#include<cmath>
using namespace std;
int factorial(int n){
    int factorial=1;
    for(int i=2;i<=n;i++){
        factorial=factorial*i;
    }
    return factorial;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=i;j++){
            cout<<factorial(i)/(factorial(i-j)*factorial(j));
        }
        cout<<endl;
    }
}
*/
//finds the prime btw 2 numbers:
/*
#include<iostream>
#include<cmath>
using namespace std;
bool prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
            
        }
    }
    return true;
}
int main(){
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(prime(i)){
            cout<<i<<endl;
        }
    }
}
*/

#include<iostream>
#include<cmath>
using namespace std;
