#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

stack<string> reverse(stack<string> llista){
  stack<string> aux;
  while(!llista.empty()){
    aux.push(llista.top());
    llista.pop();
  }
  return aux;
}

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
    }else if (command == "PRESTEC") {
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
    llista[i] = reverse(llista[i]);
    cout << "Pila " << i+1 << ":";
    if(!llista.empty()) {
        cout << " ";
      }
    while (!llista[i].empty()) {
      cout << llista[i].top();
      llista[i].pop();
    }
    if(!llista[i].empty()) {
        cout << " ";
      } else cout << endl;
  }
}
