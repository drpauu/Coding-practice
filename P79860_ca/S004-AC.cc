#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int barres(int n) {
  int nn = n;
  if (nn > 0) {
    while (nn > 0) {
      nn--;
      cout << "*";
    }
  } else {
    return 0;
  }
  cout << endl;
  barres(n - 1);
  barres(n - 1);
  return 0;
}

int main() {
  int n;
  cin >> n;
  barres(n);
}
