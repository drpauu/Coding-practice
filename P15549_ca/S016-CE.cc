#include <iostream>
#include <vector>

using namespace std;

void ordena_per_bombolla(vector<double> &v) {
  for (size_t i = 0; i < v.size() - 1; ++i) {
    for (size_t j = 0; j < v.size() - i - 1; ++j) {
      if (v.at(j) > vec.at(j + 1))
        swap(v.at(j), v.at(j + 1));
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
