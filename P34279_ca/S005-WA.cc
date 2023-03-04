#include <cmath>
#include <iostream>
#include <string>
using namespace std;

/*int main() {   P98960
  char ll;
  cin >> ll;
  // mayus es ll, minus es aux;
  if (ll >= 'a' and ll <= 'z') {
    ll += 'A'-'a';
  } else {
    ll += 'a'-'A';
  }
  std::cout << ll << '\n';
}
*/

/*int main() {  P42042
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
*/

int main() {
  int h, m, s;
  cin >> h;
  cin >> m;
  cin >> s;
  if (s == 59) {
    if (m == 59) {
      h++;
      std::cout << h << ":00"
                << ":00" << '\n';
    } else {
      m++;
      std::cout << h << ":" << m << ":00" << '\n';
    }
  } else {
    s++;
    std::cout << h << ":" << m << ":" << s << '\n';
  }
}
