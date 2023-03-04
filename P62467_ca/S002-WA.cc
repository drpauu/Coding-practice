#include <iostream>
#include <string>

using namespace std;

void barres(int n) {
  int i = 2;
  while (i < n) {
    cout << "*" << endl;
    for (int j = 0; j < i; j++) {
      cout << "*";
    }
    cout << endl;
    i++;
  }
  while (n > 1) {
    cout << "*" << endl;
    for (int j = 0; j < n; j++) {
      cout << "*";
    }
    cout << endl;
    n--;
  }
}

int main() {
  int n;
  cin >> n;
  barres(n);
  cout << "*" << endl;
}
