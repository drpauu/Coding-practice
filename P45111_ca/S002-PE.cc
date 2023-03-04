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
  while (cin >> x) {
    stack<int> p;
    p.push(x);
    int y;
    if(x == -1){
      cout << " " << endl;
    } else {
      while (cin >> y and y != -1) {
        p.push(y);
      }
      invertir(p);
    }
  }
}
