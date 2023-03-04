#include <iostream>
#include <sstream>
#include <string>
#include <stack>
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
  bool final = false;
  vector<stack<string>> llista;
  vector<int> caramels;
  while (getline(cin, s)) {
    int nc;
    istringstream ss(s);
    ss >> nc;
    vector<stack<string>> llista;
    vector<int> caramels(0, nc);
    for (int i = 0; i < nc; ++i) {
      string s;
      getline(cin, s);
      istringstream ss(s);
      string name;
      stack<string> q;
      while (ss >> name) {
        q.push(name);
      }
      q.pop();
      llista.push_back(q);
    }
    int x, c, y;
    ss >> x >> c >> y;
    while(x != 0 and c != 0 and y != 0){
      x--;
      y--;
      for(int i = 0; i < c; i++){
        if(!llista.empty()){
          llista[x].push(llista[y].top());
          llista[y].pop();
        } else caramels[y] += 1;
      }
      ss >> x >> c >> y;
    }
    for (int i = 0; i < nc; ++i) {
      llista[i] = reverse(llista[i]);
      cout << caramels[i];
      if(llista[i].empty()){
          cout << endl;
        } else cout << " ";
      while (!llista[i].empty()) {
        cout << llista[i].top();
        llista[i].pop();
        if(llista[i].empty()) {
          cout << endl;
        } else cout << " ";
      }
    }
    cout << "----------" << endl;
    caramels.clear();
    llista.clear();
  }
}
