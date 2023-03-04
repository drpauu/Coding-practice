#include <iostream>

using namespace std;

int main (){
	int x, y, aux = 0;
	while(cin>>x){
		for(int i = 0; i < x; i++){
			cin>>y;
			if(y > aux){
				aux = y;
			} 
		}
		cout<<aux<<endl;
	}
}
