#include <cmath>
#include <iostream>
#include <string>
using namespace std;

/*int main() {   P98960
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
*/

int main() {
  char x;
  cin >> x;
  if (x >= 65 and x < 97) {
    std::cout << "majuscula" << '\n';
  } else {
    std::cout << "minuscula" << '\n';
  }
  if (x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u') {
    std::cout << "vocal" << '\n';
  } else if (x == 'A' or x == 'E' or x == 'I' or x == 'O' or x == 'U') {
    std::cout << "vocal" << '\n';
  } else {
    std::cout << "consonant" << '\n';
    ;
  }
}
