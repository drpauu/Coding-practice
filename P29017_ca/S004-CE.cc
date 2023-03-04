#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

void escriu_de_cim_a_base(stack<int> &pila);
// Pre: True
// Post: escriu la pila de dal a baix

void escriu_de_base_a_cim(stack<ivnt> &pila);
// Pre: True
// Post: escriu la pila de baix a dalt

//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------

void escriu_de_cim_a_base(stack<int> &pila) {
  if (!pila.empty()) {
    cout << pila.top() << endl;
    pila.pop();
  } else {
    return;
  }
}

void escriu_de_base_a_cim(stack<ivnt> &pila) {
  stack<int> aux;
  if (!pila.empty()) {
    aux.push(pila.top());
    pila.pop();
  } else {
    escriu_de_cim_a_base(aux);
  }
}
