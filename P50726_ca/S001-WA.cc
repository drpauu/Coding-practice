#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<string> v(16);
  string f1, f2, f3;
  int j = 0, cont = 0;
  bool trobat = false;
  f1 = "a";
  f2 = "b";
  v[0] = f1;
  v[1] = f2;
  for (int i = 2; i < 16; i++) {
    v[i] = v[i - 2] + v[i - 1];
  }
  cin >> f3;
  while (j < 16 and not trobat) {
    if (v[j] == f3) {
      trobat = true;
    }
    j++;
    cont++;
  }
  if (trobat) {
    cout << f3 << " es la paraula numero " << cont << endl;
  } else {
    cout << f3 << " no es de Fibonacci" << endl;
  }
}
