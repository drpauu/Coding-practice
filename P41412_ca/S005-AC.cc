#include <iostream>
#include <vector>
using namespace std;

void ordena_per_insercio(vector<double> &v) {
  int n = int(v.size());
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0 and v[j - 1] > v[j]; j--) {
      swap(v[j - 1], v[j]);
    }
  }
}

int main() {
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(4);
  int n;
  while (cin >> n) {
    vector<double> V(n);
    for (int i = 0; i < n; ++i) {
      cin >> V[i];
    }
    ordena_per_insercio(V);
    for (int i = 0; i < n; ++i) {
      cout << " " << V[i];
    }
    cout << endl;
  }
}
