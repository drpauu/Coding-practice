#include <iostream>
#include <vector>
using namespace std;

struct Info {
  string nom, hora;
};

string busca(string nom, const vector<Info> &v) {
  // Pre: nom es un string i v es un vector de Info ordenada per nom.
  // Post Retorna l’hora corresponent a nom dins de la taula ordenada per nom v.
  //      Retorna "???" si nom està repetit. Retorna "ABANDONA" si nom no hi és.
  string res = "";
  bool trobat = false;
  int i = 0, j = int(v.size() - 1), pos;

  while (i <= j and not trobat) {
    pos = (i + j) / 2;
    if (nom > v[pos].nom)
      i = pos + 1;
    else if (nom < v[pos].nom)
      j = pos - 1;
    else
      trobat = true;
  }
  bool repetit = false;
  if (trobat) {
    if (pos + 1 < int(v.size()) and v[pos + 1].nom == nom)
      repetit = true;
    if (pos - 1 >= 0 and v[pos - 1].nom == nom)
      repetit = true;
  }

  if (trobat and repetit)
    res = "???";
  else if (trobat and not repetit)
    res = v[pos].hora;
  else
    res = "ABANDONA";
  return res;
}

int main() {
  int n;
  cin >> n;
  string c = "", h = "";
  Info a;
  vector<Info> vf;
  for (int i = 0; i < n; ++i) {
    cin >> a.nom >> a.hora;
    vf.push_back(a);
  }

  string dni, nom;

  while (cin >> dni >> nom) {
    cout << dni << " " << busca(nom, vf) << endl;
  }
}
