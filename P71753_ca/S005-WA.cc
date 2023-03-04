#include <iostream>

using namespace std;

int main (){
	int x, y, c;
	while(cin>>x){
		int aux;
		for(int i = 0; i < x; i++){
			cin>>y;
			cin>>c;
			if(y > c){
				aux = y;
			}else aux = c;
		}
		cout<<aux<<endl;
	}
}
