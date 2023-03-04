#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool es_fantastic(int x) {
  bool trobat = false;
  int pos = 1;
  if (x != 0) {
    while (x > 0 and not trobat) {
      if ((pos % 2 == 1 and (x % 10) % 2 == 1) or
          (pos % 2 == 0 and (x % 10) % 2 == 0)) {
        ++pos;
        x = x / 10;
      } else
        trobat = true;
    }
    return not trobat;
  } else
    return false;
}

int main() {
  int a;
  int compt = 0;
  int triplets = 0;
  int nombre = 0;
  while (cin >> a) {
    ++nombre;
    if (es_fantastic(a)) {
      ++compt;
      if (compt >= 3)
        ++triplets;
      // cout<<"a "<<a<<" compt = "<<compt<< " triplets "<< triplets<<endl;
    } else
      compt = 0;
  }
  cout << "nombres: " << nombre << endl;
  cout << "triplets fantastics: " << triplets << endl;
}
