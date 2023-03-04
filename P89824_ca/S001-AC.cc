/*
using namespace std;

int main() {
  int x, min = 0, dist = 0;
  while (cin >> x) {
    if (min == x) {
      cout << "el minim es " << x << endl;
      cout << "la distancia es " << dist << endl;
    } else if (min >= x) {
      min = x;
      dist = 0;
    } else {
      dist++;
    }
  }
}
*/
#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  int minimo = x;
  bool paradecontar = false;
  int contador = 0;
  while (cin >> x) {
    if (x < minimo) {
      minimo = x;
      contador = 0;
      paradecontar = false;
    }

    else if (x == minimo)
      paradecontar = true;

    else if (x > minimo)
      if (paradecontar == false)
        ++contador;

      else
        x = x;
  }
  cout << "el minim es " << minimo << endl;
  cout << "la distancia es " << contador << endl;
}
