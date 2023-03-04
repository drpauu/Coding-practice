#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriu;

Matriu gira_matriu(const Matriu &m) {
  Matriu m2;
  for (int j = 0; j < m[0].size(); ++j) {
    Fila c;
    for (int i = m.size() - 1; i >= 0; --i) {
      c.push_back(m[i][j]);
    }
    m2.push_back(c);
  }
  return m2;
}

void llegir_matriu(Matriu &m) {
  for (int i = 0; i < m.size(); ++i)
    for (int j = 0; j < m[0].size(); ++j)
      cin >> m[i][j];
}

void escriure_matriu(const Matriu &m) {
  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m[0].size(); ++j) {
      if (j == 0)
        cout << m[i][j];
      else
        cout << " " << m[i][j];
    }
    cout << endl;
  }
}

int main() {
  int x, y, k;
  while (cin >> x >> y) {
    Matriu m(x, Fila(y, 0));
    llegir_matriu(m);
    cin >> k;
    k = k % 4;
    Matriu m3;
    for (int i = 1; i <= k; ++i) {
      m3 = gira_matriu(m);
      m = m3;
    }
    escriure_matriu(m);
    cout << endl;
  }
}
