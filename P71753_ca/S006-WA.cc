#include <iostream>

using namespace std;

int main (){
	int x, y, c = 1;
	while(cin>>x){
		int aux;
		for(int i = 0; i < x; i++){
			cin>>y;
			if(c == 1){
				aux = y;
				c++;
			}else if(y > aux){
				aux = y;
			}
		}
		cout<<aux<<endl;
	}
}
