#include <iostream>
#include <stack>
using namespace std;


void escriu_de_cim_a_base(stack<int>& pila){
	while(not pila.empty()){
		cout<<pila.top()<<endl;
		pila.pop();
	}
}
void escriu_de_base_a_cim(stack<int>& pila){
	stack<int> aux;
	while(not pila.empty()){
		aux.push(pila.top());
		pila.pop();
	}
	while(not aux.empty()){
		cout<<aux.top()<<endl;
		pila.push(aux.top());
		aux.pop();
	}
}


int main() {
  int n;
  while (cin >> n) {
    stack<int> pila;
    while (n--) {
      int x;
      cin >> x;
      pila.push(x);
    }

    stack<int> copia = pila;
    escriu_de_cim_a_base(pila);
    escriu_de_base_a_cim(copia);
  }
}
