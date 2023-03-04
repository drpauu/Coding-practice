#include <iostream>
#include <vector>

using namespace std;

void ordena_per_bombolla(vector<double> &v) {
  bool swapp = true;
  while (swapp) {
    swapp = false;
    for (size_t i = 0; i < v.size() - 1; i++) {
      if (v[i] > v[i + 1]) {
        v[i] += v[i + 1];
        v[i + 1] = v[i] - v[i + 1];
        v[i] -= v[i + 1];
        swapp = true;
      }
    }
  }
}

int main() {
  int n;
  while (cin >> n) {
    vector<double> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    ordena_per_bombolla(v);
    for (int i = 0; i < n; ++i) {
      cout << " " << v[i];
    }
    cout << endl;
  }
}
