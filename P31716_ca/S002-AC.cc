#include <iostream>
using namespace std;

bool divisors_3_7(int y) {
  // Pre: y>=1
  // Post: Retorn true si tots els divisors de y son 3 i 7 sino retorna false
  bool trobat = false;
  int d = 2;
  while (y > 1 and not trobat) {
    if (y % d == 0) {
      if (d != 3 and d != 7)
        trobat = true;
      else {
        y = y / d;
        d = 2;
      }
    } else
      ++d;
  }
  return not trobat;
}

bool es_perfecte(int x) {
  // Pre: x>=1
  // Post: Retorna true si x es un quadrat perfecte sino retorna false
  int i = 1;
  while (i * i < x)
    ++i;
  if (i * i == x)
    return true;
  else
    return false;
}

bool es_maco(int n) {
  // Pre: n>=1
  // Post: Retorn true si n es un nombre maco, sino retorna false
  if (es_perfecte(n) and divisors_3_7(n))
    return true;
  else
    return false;
}

int main() {
  int a;
  while (cin >> a) {
    if (es_maco(a))
      cout << a << " es maco" << endl;
    else
      cout << a << " es lleig" << endl;
  }
}
