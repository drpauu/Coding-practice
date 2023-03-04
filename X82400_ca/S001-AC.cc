#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

void eliminar_suma_major_queue(int &j, queue<int> &q1, queue<int> &q2) {
  // Pre: cert
  // Post: afegeix els elements de q1 a q2 si son mayor a igual a j, on j es
  // igual a j+q1.front, q1 es quedara buit
  if (not q1.empty()) {

    int now = q1.front();
    if (j >= now) {
      q2.push(now);
    }

    j += now;

    q1.pop();
    eliminar_suma_major_queue(j, q1, q2);
    // Post: afegeix els elements de q1-1 a q2 si son mayor a igual a j,
    // on j es igual a j+q1.front, q1 es quedara buit
    // Fita: mida de q1
  }
}

int main() {

  string s;

  while (getline(cin, s)) {
    istringstream ss(s);

    int x;
    queue<int> q1;
    queue<int> q2;
    while (ss >> x) {
      q1.push(x);
    }
    x = 0;
    eliminar_suma_major_queue(x, q1, q2);

    while (not q2.empty()) {
      cout << q2.front();
      if (q2.size() != 1)
        cout << " ";
      q2.pop();
    }
    cout << endl;
  }
}
