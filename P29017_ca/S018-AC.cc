#include <iostream>
#include <stack>
using namespace std;

void escriu_de_cim_a_base(stack<int> &pila) {
  stack<int> aux = pila;
  int x;
  while (!aux.empty()) {
    x = aux.top();
    aux.pop();
    if (aux.empty()) {
      cout << x;
    } else {
      cout << x << " ";
    }
  }
  cout << endl;
}
void escriu_de_base_a_cim(stack<int> &pila) {
  stack<int> aux = pila;
  stack<int> aux1;
  while (!aux.empty()) {
    aux1.push(aux.top());
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
