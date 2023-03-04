#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main (){
  string s;

  getline(cin, s);
  istringstream ss(s);
  int nc;

  ss >> nc;

  vector<stack<string>> llista;
  for (int i = 0; i < nc; ++i) {
    stack<string> q;
    getline(cin, s);
    istringstream ss(s);
    string name;
    while (ss >> name) {
      q.push(name);
    }
    llista.push_back(q);
  }
  while (getline(cin, s)) {
    istringstream ss(s);
    string command;
    ss >> command;

    if (command == "RETORN") {
      string name;
      ss >> name;

      int num;
      ss >> num;
      num--;
      if (num >= 0 and num < nc) {
        llista[num].push(name);
      }
    }
    } else if (command == "PESTEC") {
      int num;
      ss >> num;
      num--;
      if (num >= 0 and num < nc) {
        if (!llista[num].empty()) {
        llista[num].pop();
        }
      }
    }
  }
  for (int i = 0; i < nc; ++i) {
    cout << "Pila " << i+1 << ": ";
    while (!llista[i].empty()) {
      cout << llista[i].top();
      llista[i].pop();
      if(!llista.empty()) cout << " ";
    }
    cout << endl;
  }
}
