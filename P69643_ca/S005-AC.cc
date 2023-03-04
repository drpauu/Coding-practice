#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool parentesis(const string &s) {
  stack<char> p;
  for (int i = 0; i < int(s.size()); i++) {
    char c = s[i];
    if (c == '(' or c == '[')
      p.push(c);
    else {
      if (p.empty())
        return false;
      if (c == ')' and p.top() != '(')
        return false;
      if (c == ']' and p.top() != '[')
        return false;
      p.pop();
    }
  }
  return p.empty();
}

int main() {
  string s;
  stack<string> con;
  while (cin >> s) {
    if (parentesis(s)) {
      cout << s << " es correcta" << endl;
    } else
      cout << s << " es incorrecta" << endl;
  }
}
