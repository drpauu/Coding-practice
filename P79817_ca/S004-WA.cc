#include <iostream>

using namespace std;

int main (){
	int x, c, aux;
	while(cin>>x and cin>>c){
			if(x == 0){
			aux = 0;
			} else if(c == 0){
				aux = 1;
			}			
			else{
			aux = x;
			c = c-1;
			for(int i = 0; i < c; i++){
				aux = aux*x;
			}
			}
		cout<<aux<<endl;
	}
	
}
