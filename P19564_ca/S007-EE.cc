#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int valencia(int n) {
  int auxp = 0, auxs = 0, valencia = 0, pos = 1;
  for (int x = n; x > 0; x / 10) {
    if (pos % 2 == 0) {
      auxp = auxp + x % 10;
    } else {
      auxs = auxs + x % 10;
    }
    pos++;
  }
  if (auxs >= auxp) {
    valencia = auxs - auxp;
  } else {
    valencia = auxp - auxs;
  }
  return valencia;
}

int main() {
  int n, aux = 0, a;
  bool tr = false;
  while (cin >> n and !tr) {
    a = valencia(n);
    if (a == 0) {
      cout << "El primer nombre equilibrat es " << a << "." << endl;
      tr = true;
    } else if (a > aux) {
      aux = a;
    }
  }
  cout << "La valencia maxima es " << aux << "." << endl;
}
