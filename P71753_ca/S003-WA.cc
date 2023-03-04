#include <iostream>

using namespace std;

int main (){
	int x, y;
	while(cin>>x){
		int aux;
		for(int i = 0; i < x; i++){
			cin>>y;
			if(y > aux){
				aux = y;
			} 
		}
		cout<<aux<<endl;
	}
}
