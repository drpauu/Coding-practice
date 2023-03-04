#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int main() {
  string s;
  stack<string> v;
  while (getline(cin, s)) {
    istringstream ss(s);
    string x;
    while (ss >> x) {
      if (x == "+") {
        int operation = 0;
        int segon = stoi(v.top());
        v.pop();
        int primer = stoi(v.top());
        v.pop();
        operation = primer + segon;
        auto s = to_string(operation);
        v.push(s);
      } else if (x == "-") {
        int operation = 0;
        int segon = stoi(v.top());
        v.pop();
        int primer = stoi(v.top());
        v.pop();
        operation = primer - segon;
        auto s = to_string(operation);
        v.push(s);
      } else if (x == "*") {
        int operation = 0;
        int segon = stoi(v.top());
        v.pop();
        int primer = stoi(v.top());
        v.pop();
        operation = primer * segon;
        auto s = to_string(operation);
        v.push(s);
      } else
        v.push(x);
    }
    cout << v.top() << endl;
  }
}
