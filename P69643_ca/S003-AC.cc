#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

bool checkString(string s) {
  stack<char> st;

  for (int i = 0; i < int(s.size()); ++i) {
    char x = s[i];
    if (x == '(' or x == '[') {
      st.push(x);
    } else {

      if (not st.empty()) {
        if (x == ']')
          if (st.top() != '[') {
            return false;
          }

        if (x == ')')
          if (st.top() != '(') {
            return false;
          }

        st.pop();
      } else {
        return false;
      }
    }
  }

  if (st.empty())
    return true;
  return false;
}

int main() {
  string s;
  while (getline(cin, s)) {
    istringstream ss(s);
    string x;
    while (ss >> x) {
      cout << x;
      bool correcte = checkString(x);
      if (correcte == true)
        cout << " es correcta";
      else
        cout << " es incorrecta";

      cout << endl;
    }
  }
}
