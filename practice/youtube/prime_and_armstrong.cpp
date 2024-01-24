/*
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool flag=0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<"Non-Prime"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"prime"<<endl;
    }
}
*/
/*
#include<iostream>
using namespace std;
int main (){
     int n;
     cin>>n;
     int reverse=0;
     while(n>0){
        int lastdigit=n%10;
        reverse=reverse*10+lastdigit;
        n=n/10;
    }
    cout<<reverse<<endl;

}
*/
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    // Save the original value of n
    int f = 0;
    int og = n; 
    while (n > 0) {
        int lastdigit = n % 10;
        f += pow(lastdigit, 3);
        n = n / 10;
    }

    if (f == og) {
        cout << "Armstrong" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
