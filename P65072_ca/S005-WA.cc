#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

bool palindroms(stack<int> a, stack<int> b) {
  while (!a.empty()) {
    if (a.top() == b.top()) {
      a.pop();
      b.pop();
      return palindroms(a, b);
    } else
      return false;
  }
  return true;
}

int main() {
  string s;
  while (getline(cin, s)) {
    istringstream ss(s);
    int x;
    stack<int> a;
    while (ss >> x) {
      a.push(x);
    }
    stack<int> b;
    while (!a.empty()) {
      b.push(a.top());
      a.pop();
    }
    if (palindroms(a, b)) {
      cout << "Es un palindrom." << endl;
    } else
      cout << "NO es un palindrom." << endl;
  }
}
