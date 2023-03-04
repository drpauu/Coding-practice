#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int conc, premif, i = 0;
  cin >> conc;
  vector<int> num(conc);
  vector<string> nom(conc);
  int guanyador = -1;
  while (i < conc) {
    cin >> nom[i] >> num[i];
    i++;
  }
  cin >> premif;
  int premiaux1 = premif;
  for (int i = 0; i < conc; i++) {
    int premiaux;
    if (num[i] <= premif) {
      premiaux = premif - num[i];
      if (premiaux < premiaux1) {
        premiaux1 = premiaux;
        guanyador = i;
      }
    }
  }
  if (guanyador == -1) {
    cout << "CAP GUANYADOR" << endl;
  } else {
    cout << "guanyador/a: " << nom[guanyador] << endl;
  }
}
