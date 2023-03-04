#include <iostream>

using namespace std;

int main (){
	int x, y, aux = 0;
	while(cin>>x){
		aux = 0;
		for(int i = 0; i < x; i++){
			cin>>y;
			if(y > aux){
				aux = y;
			} 
		}
		cout<<aux<<endl;
	}
}
