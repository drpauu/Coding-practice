#include <iostream>
using namespace std;


int mcd(int a, int b){
    if (b == 0)
        return a;
    
    return mcd(b, a%b);

}


int main() {
    int x, y;
    while (cin >> x >> y) {
        cout << mcd(x, y) << endl;
    }
