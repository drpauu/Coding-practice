#include <iostream>

using namespace std;

int main() {
  int x, min = 0, dist = 0;
  bool tr = true;
  while (cin >> x) {
    if (min == x) {
      rt = true;
    } else if (min >= x) {
      min = x;
      dist = 0;
    } else {
      dist++;
    }
    if (min > x) {
      x = min;
      dist = 0;
    } else if (min == x) {
      tr = true;
    } else if (min < x) {
      if (tr) {
        dist++;
      } else {
        x = x;
      }
    }
  }
  cout << "el minim es " << min << endl;
  cout << "la distancia es " << dist << endl;
}
/*
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
*/
