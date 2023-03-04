#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

stack<string> inversa(stack<string> v) {
  stack<string> inv;
  while (!v.empty()) {
    inv.push(v.top());
    v.pop();
  }
  return inv;
}

int main() {
  string s;
  getline(cin, s);
  istringstream ss(s);
  int nc;
  ss >> nc;
  vector<stack<string>> p;
  for (int i = 0; i < nc; ++i) {
    stack<string> q;
    getline(cin, s);
    istringstream ss(s);
    string name;
    while (ss >> name) {
      q.push(name);
    }
    stack<string> qq = inversa(q);
    p.push_back(qq);
  }
  while (getline(cin, s)) {
    istringstream ss(s);
    string com;
    ss >> com;
    if (com == "PRESTEC") {
      int pila;
      ss >> pila;
      pila--;
      if (not p[pila].empty()) {
        p[pila].pop();
      }
    } else if (com == "RETORN") {
      string rllibre;
      int pila;
      ss >> rllibre;
      ss >> pila;
      pila--;
      p[pila].push(rllibre);
    }
  }
  for (int i = 0; i < nc; i++) {
    cout << "Pila " << i + 1 << ": ";
    while (!p[i].empty()) {
      string aux;
      aux = p[i].top();
      p[i].pop();
      if (!p[i].empty()) {
        cout << aux << " ";
      } else
        cout << aux;
    }
    cout << endl;
  }
}
