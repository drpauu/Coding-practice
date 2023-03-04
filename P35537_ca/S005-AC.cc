#include <iostream>
using namespace std;


bool es_creixent(int n){
//Pre:  true
//Post: retorna si el n es creixent
    if (n <= 9)
        return true;

    if (n%10 < ((n/10)%10))
        return false;

    return es_creixent(n/10);
    //H.I: retorna si el n/10 es creixent
    //FITA: size de n
}

int main() {
    int num;
    while (cin >> num){
        if (es_creixent(num))
            cout << "true";
        else 
            cout << "false";

        cout << endl;


    }
}
