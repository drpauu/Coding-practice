#include <iostream>

using namespace std;


void barras(int n){
//Pre: cert
/*Post 
    si n==1 mostra *
    si !=1 mostra n-1 * + endl + n * + endl + n-1*
*/
    if (n == 1) {
        cout << "*"<<endl;
    } else {
        barras(n-1);
        /*H.I: n=n-1 
            si n==1 mostra *
            si !=1 mostra n-1 * + endl + n * + endl + n-1*
        */
        //Fita: n decreix
        for (int i=0;i < n;i++){
            cout << "*";
        }
        cout << endl;
        barras(n-1);
        /*H.I: n=n-1 
            si n==1 mostra *
            si !=1 mostra n-1 * + endl + n * + endl + n-1*
        */
        //Fita: n decreix
    }
}

int main (){

    int n;
    cin >>n;
    barras(n);
}
