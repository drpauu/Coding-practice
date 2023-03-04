#include <iostream>
using namespace std;

int productededigits (int n){
    cin>>n;
    int producte = 1; //és l'element neutre de la multiplicació
    //Pre: n és un nombre enter 
    //Post: s'ha de retornar el producte del seus digits
    while(n>0){
      producte = producte*(n%10);
      n = n/10;
    }
    return producte;
}
int main() {
    int nombre;
    cin>>nombre;
    cout<<"El producte del digits val "<<productededigits(nombre)<<endl;
    return 0;
}