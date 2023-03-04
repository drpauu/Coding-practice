#include <iostream>

using namespace std;

int main (){
	int x, y;
	while(cin>>x){
		int aux, c = 1;
		for(int i = 0; i < x; i++){
			cin>>y;
			if(c == 1){
				aux = y;
			}else if(y > aux){
				aux = y;
			}
			c++;
		}
		cout<<aux<<endl;
	}
}
