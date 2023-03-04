#include <iostream>
#include <string>

using namespace std;

int main (){
	string p, s;
	int c = 1, aux = 1;
	cin>>p;
	while(cin>>s){
		if(s == p){
			c++;
		} else c = 0;
		
		
		if(c > aux){
			aux = c;
		}
	}
	cout<<aux<<endl;
}
