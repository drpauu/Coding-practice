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
  int nc;
  bool final = false;
  while(cin >> nc){
    bool final = false;
    int partides = 0;
    vector<stack<string>> llista;
    vector<int> caramels;
    int aux = 0, bossa = 0;
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
      caramels.push_back(aux);
    }
    int x, c, y;
    while(cin >> x >> c >> y and !final){
      if(x == 0 and c == 0 and y == 0){
        x--;
        y--;
        for(int i = 0; i < c; i++){
          if(!llista[y].empty()){
            llista[x].push(llista[y].top());
            llista[y].pop();
          } else{
            caramels[y] += 1;
          }
        }
      } else final = true;
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
  }
}
