#include <iostream>
#include <queue> // Incloem la llibreria de cues de prioritats

using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int>> q1;
  priority_queue<int, vector<int>, less<int>> q2;
  int x;
  // Afegim els nombres a les dues cues de prioritats
  while (cin >> x) {
    q1.push(x);
    q2.push(x);
  }

  // Escrivim els nombres ordenats de petit a gran
  if (q1.empty())
    cout << endl;

  while (!q1.empty()) {
    cout << q1.top();
    q1.pop();
    if (!q1.empty()) {
      cout << " ";
    } else
      cout << endl;
  }
  // Escrivim els nombres ordenats de gran a petit

  if (q1.empty())
    cout << endl;
  while (!q2.empty()) {
    cout << q2.top();
    q2.pop();
    if (!q2.empty()) {
      cout << " ";
    } else
      cout << endl;
  }
}
