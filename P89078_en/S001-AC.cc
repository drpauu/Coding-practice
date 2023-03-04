#include <iostream>
using namespace std;

int main(){
    int n;
    int count = 1;
    bool trobat = false;
    while(cin>>n and not trobat){
        if(n%2 != 0){
            count++;
        }
        else{
            trobat = true;
        }
    }
    cout<<count<<endl;
}