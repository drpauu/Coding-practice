#include <iostream>
#include <vector>
using namespace std;

void ordena_per_bombolla(vector<double> &v) {
  int n = int(v.size());
  for (int i = 1; < n; i++) {
    for (int j = i; j > 0 and v[j - 1] > v[j]; j--) {
      swap(v[j - 1], v[j]);
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
