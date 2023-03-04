#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int valencia(int n) {
  int auxp, auxs, aux, valencia;
  aux = n;
  int pos = 1;
  while (aux > 0) {
    if (pos & 2 == 0) {
      auxp = auxp + aux % 10;
      aux / 10;
    } else {
      auxs = auxs + aux % 10;
      aux / 10;
    }
  }
  if (auxs > auxp) {
    valencia = auxs - auxp;
  } else {
    valencia = auxp - auxs;
  }
  return valencia;
}

int main() {
  int n, aux = 0;
  bool tr = false;
  while (cin >> n && tr) {
    if (valencia(n) == 0) {
      cout << "El primer nombre equilibrat es " << valencia(n) << "." << endl;
      tr = true;
    } else if (valencia(n) < aux) {
      aux = valencia(n);
    }
  }
  cout << "La valencia maxima es " << aux << "." << endl;
}
