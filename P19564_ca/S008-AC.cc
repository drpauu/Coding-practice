#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int valencia(int n) {
  int auxp = 0, auxs = 0, valencia = 0, pos = 1;
  while (n > 0) {
    if (pos % 2 == 0) {
      auxp = auxp + n % 10;
    } else {
      auxs = auxs + n % 10;
    }
    n = n / 10;
    pos++;
  }
  if (auxp == auxs) {
    return 0;
  } else if (auxs > auxp) {
    valencia = auxs - auxp;
    return valencia;
  } else {
    valencia = auxp - auxs;
    return valencia;
  }
  return 0;
}

int main() {
  int n, aux = 0, a = 0;
  bool tr = false;
  while (cin >> n and !tr) {
    a = valencia(n);
    if (a == 0) {
      cout << "El primer nombre equilibrat es " << n << "." << endl;
      tr = true;
    } else if (a > aux) {
      aux = a;
    }
  }
  if (!tr) {
    cout << "La valencia maxima es " << aux << "." << endl;
  }
}
