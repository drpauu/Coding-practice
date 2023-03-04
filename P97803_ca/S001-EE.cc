#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  int piles;
  string llibre, ss;
  cin >> piles;
  vector<stack<string>> p;
  for (int i = 0; i < piles - 1; i++) {
    while (cin >> ss) {
      p[i].push(ss);
    }
  }
  int pila;
  string com;
  while (cin >> com) {
    if (com == "PRESTEC") {
      cin >> pila;
      pila = pila - 1;
      if (!p[pila].empty()) {
        p[pila].pop();
      }
    } else if (com == "RETORNA") {
      string rllibre;
      cin >> rllibre >> pila;
      pila = pila - 1;
      p[pila].push(rllibre);
    }
  }
  for (int i = 0; i < piles - 1; i++) {
    cout << "Pila " << i + 1 << ": ";
    while (!p[i].empty()) {
      cout << p[i].top() << " ";
      p[i].pop();
    }
    cout << endl;
  }
}
