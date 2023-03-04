#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

stack<int> inverse(stack<int> p) {
  stack<int> x;
  while (!p.empty()) {
    x.push(p.top());
    p.pop();
  }
  return x;
}

bool palindrom(stack<int> a, stack<int> b) {
  bool res;
  if (!a.empty() and !b.empty()) {
    if (a.top() == b.top()) {
      a.pop();
      b.pop();
      res = palindrom(a, b);
      return res;
    } else
      return false;
  } else
    return true;
}

int main() {
  string s;
  while (getline(cin, s)) {
    istringstream ss(s);
    stack<int> a;
    stack<int> b;
    int x;
    while (ss >> x) {
      a.push(x);
    }
    b = inverse(a);
    if (palindrom(a, b)) {
      cout << "Es un palindrom." << endl;
    } else
      cout << "NO un es palindrom." << endl;
  }
}
