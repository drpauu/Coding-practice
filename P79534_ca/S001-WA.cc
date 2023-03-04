#include <iostream>
#include <vector>

using namespace std;

bool es_fantastic(int x) {
  bool tr = false;
  int i, aux;
  i = x;
  int cont = 1;
  while (i > 0) {
    aux = i % 10;
    if (cont % 2 == 0) {
      if (aux % 2 == 0) {
        tr = true;
      } else {
        return false;
      }
    } else if (cont % 2 != 0) {
      if (aux % 2 == 0) {
        tr = true;
      } else {
        return false;
      }
    }
  }
  return tr;
}
int main() {
  int num;
  int contf = 0;
  int cont = 0;
  vector<int> v;
  while (cin >> num) {
    v.push_back(num);
  }
  for (unsigned int j = 0; j < v.size(); j++) {
    if (es_fantastic(v[j])) {
      cont++;
    } else {
      cont = 0;
    }
    if (cont = 3) {
      contf++;
      cont = 0;
    }
  }
  cout << "nombres: " << v.size() << endl;
  cout << "triplets fantastics: " << contf << endl;
}
