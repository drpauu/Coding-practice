#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  string s;

  getline(cin, s);
  istringstream ss(s);
  int nc;

  ss >> nc;

  vector<queue<string>> queue_list;
  for (int i = 0; i < nc; ++i) {
    queue<string> q;
    getline(cin, s);
    istringstream ss(s);
    string name;
    while (ss >> name) {
      q.push(name);
    }
    queue_list.push_back(q);
  }

  cout << "SORTIDES\n--------";
  while (getline(cin, s)) {
    istringstream ss(s);
    string command;
    ss >> command;

    if (command == "ENTRA") {
      string name;
      ss >> name;

      int queue;
      ss >> queue;
      queue--;
      if (queue >= 0 and queue < nc) {
        queue_list[queue].push(name);
      }

    } else if (command == "SURT") {
      int queue;
      ss >> queue;
      queue--;
      if (queue >= 0 and queue < nc) {
        if (not queue_list[queue].empty()) {
          cout << endl << queue_list[queue].front();
          queue_list[queue].pop();
        }
      }
    }
  }
  cout << "\n\nCONTINGUTS FINALS" << endl;
  cout << "-----------------" << endl;
  for (int i = 0; i < nc; ++i) {
    cout << "cua " << i + 1 << ":";
    while (not queue_list[i].empty()) {
      cout << " " << queue_list[i].front();
      queue_list[i].pop();
    }
    cout << endl;
  }
}
