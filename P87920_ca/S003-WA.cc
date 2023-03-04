#include <iostream>
#include <vector>

using namespace std;

int main () {
	int n;
	while(cin>>n){
	vector<int> p(n);
		for(unsigned int i = 0; i < p.size(); i++){
		 	cin>>p[i];
		}
		bool trobat = false;
		int c = 0;
		for(unsigned int i = 0; i < p.size() and not trobat; i++){
			int aux = 0;
			if(aux == p[i]) trobat = true;
			aux = p[i + c] + aux; 
			c++;
		}
		if(trobat){
			cout<<"YES"<<endl;
		} else cout<<"NO"<<endl;
	}
}
