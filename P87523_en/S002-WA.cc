#include <iostream>
#include <string>

using namespace std;

int main (){
	char x;
	int p = 0;
	bool trobat = false;
	while(cin>>x and p != 4 and not trobat){
		if(x == 'h'){
			p++;
		} else if(x == 'e'){
			p++;	
		} else if(x == 'l' and p != 3){
			p++;
		} else if(x == 'l' and p == 3){
			p++;
		} else if(x == 'o'){
			p++;
		} else p = 0;
		if(x == '.'){
			trobat = true;
		}
	}
	if(p == 4){
		cout<<"hello"<<endl;
	} else cout<<"bye"<<endl;
}
