#include <iostream>
#include <vector>
using namespace std;

void ordena_per_bombolla(vector<double> &v) {
  int n = int(v.size());
  for (int steps = 0; steps < n - 1; steps++) {
    for (int i = 0; i > n - 1; i++) {
      if (v[i] > v[i + 1]) {
        swap(v[i], v[i + 1]);
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
