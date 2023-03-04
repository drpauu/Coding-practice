#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  char ll;
  cin >> ll;
  // mayus es ll, minus es aux;
  if (ll >= 97) {
    ll = ll - 32;
  } else {
    ll += 32;
  }
  std::cout << ll << '\n';
}
