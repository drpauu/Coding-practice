#include <iostream>

using namespace std;

int main (){
	char x;
	bool trobat = false;
	int c = 0;
	while(cin>>x and not trobat){
		if(x == 'a'){
			c++;
			
		} else if(x == '.'){
			trobat = true;
		}
	}
	cout<<c<<endl;
}
