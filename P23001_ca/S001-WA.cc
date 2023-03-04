#include <iostream>
#include <string>

using namespace std;

int main (){
	string p, s;
	int c = 0;
	cin>>p;
	while(cin>>s){
		if(s == p){
			c++;
		} else c = 0;
	}
	cout<<c<<endl;
}
