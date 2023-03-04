#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Racional {
  int num, den;
};

Racional minim(const Racional &a, const Racional &b) {
  if (a.den < b.den) {
    return b;
  } else if (a.den > b.den) {
    return a;
  } else if (a.den == b.den) {
    if (a.num < b.num) {
      return b;
    } else if (a.den > b.num) {
      return a;
    } else {
      return a;
    }
  }
  return a;
}

int main() {
  char k;
  int x;
  cin >> x;
  vector<Racional> aa;
  vector<Racional> bb;
  Racional a;
  Racional b;
  for (int i = 0; i < x; i++) {
    int aux, auxx;
    cin >> aux >> k >> auxx;
    aa.push_back({aux, auxx});
  }
  for (int i = 0; i < x; i++) {
    int aux, auxx;
    cin >> aux >> k >> auxx;
    bb.push_back({aux, auxx});
  }
  for (int i = 0; i < x; i++) {
    Racional aux;
    aux = minim(aa[i], bb[i]);
    cout << aux.num << "/" << aux.den << endl;
  }
}
