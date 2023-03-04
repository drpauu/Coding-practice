#include <iostream>

using namespace std;

int main (){
	char x;
	bool trobat = false;
	int c;
	while(cin>>x and not trobat){
		if(x == 'a'){
			trobat = true;
			c = 1;
			
		} else if(x == '.'){
			trobat = true;
			c = 0;
		}
	}
	if(c == 1) cout<<"si"<<endl;
	else cout<<"no"<<endl;
}
