#include <iostream>
using namespace std;


bool es_capicua(int n){
	int aux, aux1;
	aux = n;
	aux1 = 0;
	while(aux > 0){
		aux1 = aux1*10 + aux%10;
		aux = aux/10;
	}
	if(aux1 == n){
		return true;
	} else {
		return false;
	}
}

int main() {
    int n;
    while (cin >> n) cout << (es_capicua(n) ? "true" : "false") << endl;
}

