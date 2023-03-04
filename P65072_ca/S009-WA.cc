#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

stack<int> inversa(stack<int> v) {
  stack<int> inv;
  while (!v.empty()) {
    inv.push(v.top());
    v.pop();
  }
  return inv;
}

/*bool palindroms(stack<int> a, stack<int> b) {
  while (!a.empty() or !b.empty()) {
    if (a.top() == b.top()) {
      a.pop();
      b.pop();
      palindroms(a, b);
    } else
      return false;
  }
  return true;
}*/

int main() {
  string s;
  while (getline(cin, s)) {
    istringstream ss(s);
    int x;
    stack<int> a;
    while (ss >> x) {
      a.push(x);
    }
    stack<int> b = inversa(a);
    bool tr = false;
    while (!a.empty() and !tr) {
      if (a.top() != b.top()) {
        cout << "NO es un palindrom." << endl;
        tr = true;
      } else {
        a.pop();
        b.pop();
      }
    }
    cout << "Es un palindrom." << endl;
    /*if (palindroms(a, b)) {
      cout << "Es un palindrom." << endl;
    } else
      cout << "NO es un palindrom." << endl;
  }*/
  }
}
