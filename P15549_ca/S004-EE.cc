#include <iostream>
#include <vector>

using namespace std;

void ordena_per_bombolla(vector<double> &a) {
  int temp;
  for (unsigned int i = 0; i < a.size(); ++i)
    cin >> a[i];

  for (unsigned int i = 1; i < a.size(); ++i) {
    for (unsigned int j = 0; j < (a.size() - i); ++j)
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
  }
  for (unsigned int i = 0; i < a.size(); ++i)
    cout << a[i] << endl;

  return;
}
