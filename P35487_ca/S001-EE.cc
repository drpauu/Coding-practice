#include <iostream>
#include <vector>

using namespace std;

struct Info {
  string nom, hora;
} info;

string busca(string nom, const vector<Info> &v) {
  string u, dos, tres;
  u = "???";
  dos = "ABANDONA";
  for (int i = 0; i < v.size(); i++) {
    tres = v[i].hora;
    if (v[i].nom == v[i + 1].nom) {
      return u;
    } else if (v[i].nom == nom) {
      return tres;
    }
  }
  return dos;
}

int main() {
  vector<Info> v;
  int tamany;
  cin >> tamany;
  for (int i = 0; i < tamany; i++) {
    cin >> v[i].nom >> v[i].hora;
  }
  string nom, dni;
  while (cin >> dni >> nom) {
    cout << dni << " " << busca(nom, v) << endl;
  }
}
