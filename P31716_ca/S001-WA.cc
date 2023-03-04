#include <iostream>

using namespace std;

int main() {
  int x;
  bool tr;
  while (cin >> x and tr) {
    cout << endl;
    bool tr = true;
    cout << x;
    for (int i = 1; i < x; i++) {
      if (x % i == 0) {
        if (i != 3 or i != 7) {
          tr = false;
        } else {
          tr = true;
        }
      }
    }
    cout << (tr ? " es maco" : " es lleig") << endl;
  }
}
