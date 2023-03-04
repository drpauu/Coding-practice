#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void ordena_per_fusio(vector<double> &V) {
  if (V.size() <= 1)
    return; // ja està ordenat

  // Divideix el vector en dos mitats
  int mid = V.size() / 2;
  vector<double> left(V.begin(), V.begin() + mid);
  vector<double> right(V.begin() + mid, V.end());

  // Ordena cada mitat
  ordena_per_fusio(left);
  ordena_per_fusio(right);

  // Fusiona les dues mitats ordenades
  int i = 0, j = 0, k = 0;
  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      V[k] = left[i];
      i++;
    } else {
      V[k] = right[j];
      j++;
    }
    k++;
  }

  // Copia els elements restants (si n'hi ha)
  while (i < left.size()) {
    V[k] = left[i];
    i++;
    k++;
  }
  while (j < right.size()) {
    V[k] = right[j];
    j++;
    k++;
  }
}

int main() {
  cout << fixed << setprecision(1);
  int n;
  while (cin >> n) {
    vector<double> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    ordena_per_fusio(v);
    for (int i = 0; i < n; ++i) {
      cout << " " << v[i];
    }
    cout << endl;
  }
  return 0;
}
