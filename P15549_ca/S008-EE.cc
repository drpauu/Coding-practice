#include <iostream>
#include <vector>

using namespace std;

void ordena_per_bombolla(vector<double> &a) {
  int aux;
  for (unsigned int i = 0; i < a.size(); i++) {
    for (unsigned int j = i + 1; j < a.size(); j++) {
      if (a[j] < a[i]) {
        aux = a[i];
        a[i] = a[j];
        a[j] = aux;
      }
    }
  }
  for (unsigned int i = 0; i < a.size(); i++) {
    cout << a[i] << endl;
  }
  return;
}
