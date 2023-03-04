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
    n / 10;
    pos++;
  }
  if (auxs > auxp) {
    valencia = auxs - auxp;
  } else {
    valencia = auxp - auxs;
  }
  return valencia;
}

int main() {
  int n, aux = 0, func;
  bool tr = false;
  while (cin >> n) {
    cout << valencia(n) << endl;
    if (func == 0) {
      cout << "El primer nombre equilibrat es " << func << "." << endl;
      tr = true;
    } else if (func > aux) {
      aux = func;
    }
  }
  cout << "La valencia maxima es " << aux << "." << endl;
}
