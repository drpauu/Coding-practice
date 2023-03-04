#include <iostream>

using namespace std;

int main (){
	int x, c, aux;
	while(cin>>x){
		c = 0;
		aux = x;
		while(aux > 0){
			c = c + aux%10;
			aux = aux/10;	
		}
		cout<<"La suma dels digits de "<<x<<" es "<<c<<"."endl;
	}
	
}
