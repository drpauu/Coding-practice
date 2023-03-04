#include <iostream>
#include <stack>
#include <sstream>

using namespace std;


void showPila(stack <int> pila){
// Pre: cert
// Post: mostra la pila per pantalla utilitzant un espai com line delimiter, la pila quedara buida
    while (not pila.empty()){
        cout << pila.top();
        pila.pop();
        if (not pila.empty()){
            cout << " ";
        }
    }
}

int main () {
    string s;
    while (getline(cin, s)) {

        istringstream ss(s);
        stack <int> parells;
        stack <int> senars;
        int x;

        while (ss >> x){
            if (x % 2 == 0){
                parells.push(x);
            } else {
                senars.push(x);
            }
        }
        bool notShow = parells.empty();
        showPila(parells);
        if (not senars.empty()){
           if (not notShow) cout << " ";
           showPila(senars);
        }
        cout << endl;
    }
}
