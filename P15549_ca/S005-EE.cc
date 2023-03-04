#include <iostream>
#include <vector>

using namespace std;

void ordena_per_bombolla(vector<double> &a) {
  int i, j, temp, pass = 0;
  ;
  for (i = 0; i < 10; i++) {
    for (j = i + 1; j < 10; j++) {
      if (a[j] < a[i]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
    pass++;
  }
  for (i = 0; i < 10; i++) {
    cout << a[i] << endl;
  }
  return;
}
