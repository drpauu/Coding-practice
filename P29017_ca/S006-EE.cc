#include <iostream>
#include <stack>
using namespace std;

void escriu_de_cim_a_base(stack<int> &pila) {
  stack<int> aux;
  aux = pila;
  while (not aux.empty()) {
    cout << aux.top() << " ";
    aux.pop();
  }
  escriu_de_cim_a_base(aux);
  cout << endl;
}
void escriu_de_base_a_cim(stack<int> &pila) {
  stack<int> aux;
  stack<int> aux1;
  aux = pila;
  while (not aux.empty()) {
    int aux2;
    aux2 = aux.top();
    aux1.push(aux2);
    aux.pop();
  }
  escriu_de_cim_a_base(aux1);
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
