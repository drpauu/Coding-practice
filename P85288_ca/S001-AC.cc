#include<iostream>
using namespace std;

//tower of HANOI function implementation
void TOH(int n,char Sour, char Aux,char Des)
{ 
    if(n==1)
    {
        cout<<Sour<<" => "<<Des<<endl;
        return;
    }
    
    TOH(n-1,Sour,Des,Aux);
    cout<<Sour<<" => "<<Des<<endl;
    TOH(n-1,Aux,Sour,Des);
}

//main program
int main()
{ 
    int n;
       
    cin>>n;
    //calling the TOH 
    TOH(n,'A','B','C');
    
    return 0;
}