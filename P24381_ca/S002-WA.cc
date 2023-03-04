#include <iostream>
using namespace std;

void cross(int n, char c) {
  int aux;
  aux = n + 1;
  aux = aux / 2;
  for (int i = 1; i < aux; i++) {
    for (int j = 1; j < aux; j++) {
      cout << " ";
    }
    cout << c << endl;
  }
  for (int i = 0; i < n; i++) {
    cout << 'c';
  }
  cout << endl;
  for (int i = 1; i < aux; i++) {
    for (int j = 1; j < aux; j++) {
      cout << " ";
    }
    cout << c << endl;
  }
}

int main() {
  int n;
  char c;
  while (cin >> n >> c)
    cross(n, c);
}
