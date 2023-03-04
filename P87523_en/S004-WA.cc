#include <iostream>
#include <string>

using namespace std;

int main (){
	char x;
	int p = 0;
	bool trobat = false;
	while(cin>>x and not trobat){
		if(x == 'h' and p == 0){
			p = 1;
		} else if(x == 'e' and p == 1){
			p = 2;	
		} else if(x == 'l' and p == 2){
			p = 3;
		} else if(x == 'l' and p == 3){
			p = 4;
		} else if(x == 'o' and p == 4){
			p = 5;
			trobat = true;
		} else p = 0;
		if(x == '.'){
			trobat = true;
		}
	}
	if(p == 5){
		cout<<"hello"<<endl;
	} else cout<<"bye"<<endl;
}
