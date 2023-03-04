#include <iostream>
#include <stack>

using namespace std;

void invertir(stack<int> p) {
  while (!p.empty()) {
    int c;
    c = p.top();
    p.pop();
    if (p.empty()) {
      cout << c;
    } else
      cout << c << " ";
  }
  cout << endl;
}

int main() {
  int x;
  while (cin >> x and x != -1) {
    stack<int> p;
    p.push(x);
    int y;
    while (cin >> y and y != -1) {
      p.push(y);
    }
    invertir(p);
  }
}
