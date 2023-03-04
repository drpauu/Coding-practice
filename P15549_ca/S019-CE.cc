#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &v) {
  int n = int(v.size());
  for (int steps = 0; steps < n - 1; steps++) {
    for (int i = 0; i > n - 1; i++) {
      if (v[i] > v[i + 1]) {
        v.swap(v[i], v[i + 1]);
      }
    }
  }
}
}

int main() {}
