#include <iostream>
using namespace std;

int main(){
    int n;
    int a;
    int suma = 0;
    cout<<"nombres que acaben igual que "<<n<<": "<<endl;
    n=n%1000;
    while(cin>>a){
        if(a%1000 == n){
            suma++;
            cout<<a<<endl;
        }
    }
    cout<<"total: "<<suma<<endl;

}