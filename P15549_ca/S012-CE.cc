#include <iostream>
#include <vector>

using namespace std;

void ordena_per_bombolla(vector<double> &v) {
  bool swapp = true;
  while (swapp) {
    swapp = false;
    for (size_t i = 0; i < a.size() - 1; i++) {
      if (a[i] > a[i + 1]) {
        a[i] += a[i + 1];
        a[i + 1] = a[i] - a[i + 1];
        a[i] -= a[i + 1];
        swapp = true;
      }
    }
  }
}
