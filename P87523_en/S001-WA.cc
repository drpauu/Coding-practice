#include <iostream>
#include <string>

using namespace std;
int main() {
    char letra;
    string palabra;
    bool flag =false;
    bool fresp = false;
    while(not flag){
        cin>>letra;
        if(letra=='h'){
            palabra='h';
        }
        if(letra=='e'){
            palabra += 'e';
            if(palabra != "he")palabra="";
        }
        if(letra=='l'){
            palabra += 'l';
            if(palabra != "hel" and palabra != "hell")palabra="";
        }
        if(letra=='o'){
            palabra += 'o';
            if(palabra != "hello")palabra="";else{
                cout<<"hello"<<endl;
                palabra="";
                fresp=true;
            } 
        }
        if(letra=='.') flag=true;
    }
    if(not fresp) cout<<"bye"<<endl;
}