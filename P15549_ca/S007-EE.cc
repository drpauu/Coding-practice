#include <iostream>
#include <vector>

using namespace std;

void ordena_per_bombolla(vector<double> &a) {
  int temp, pass = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (a[j] < a[i]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
    pass++;
  }
  for (int i = 0; i < 10; i++) {
    cout << a[i] << endl;
  }
  return;
}
