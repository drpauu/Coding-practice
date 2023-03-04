#include <iostream>
#include <string>

using namespace std;

int main (){
	char x;
	int c = 0;
	bool trobat = true;
	while(cin>>x and trobat){
		if(x == '.'){
			trobat = false;
		}
		if(x == 'a'){
			c++;
		}
	}
	cout<<c<<endl;
}
