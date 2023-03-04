#include <iostream>

using namespace std;

int main (){
	int x, y;
	while(cin>>x){
		float aux = -10000000000000;
		for(int i = 0; i < x; i++){
			cin>>y;
			if(y > aux){
				aux = y;
			} 
		}
		cout<<aux<<endl;
	}
}
