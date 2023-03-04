#include <iostream>
#include <vector>
using namespace std;

void ordena_per_bombolla(vector<double> &v);
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
void ordena_per_bombolla(vector<double> &v) {

  for (int step = 0; step < (v.size() - 1); ++step) {

    for (int i = 0; i < v.size() - (step - 1); ++i) {

      if (v[i] > v[i + 1]) {
        int aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
      }
    }
  }
}
