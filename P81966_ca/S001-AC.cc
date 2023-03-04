#include<iostream>
#include <vector>

using namespace std; 
  
int posicio(double x, const vector<double>& v, int esq, int dre)
// Pre: true
// Post: retorna on esta x en v[l..r] si esta present si no retorna -1 
{ 
    if (dre >= esq) { 
        int medio = (dre + esq) / 2; 
  
        if (v[medio] == x) 
            return medio; 
  
        if (v[medio] > x) 
            return posicio(x, v, esq, medio-1); 
            //H.I: retorna on esta x en v[l..r-1] si esta present si no retorna -1 
            //FITA: rang de busqueda decreix
  
        if (v[medio] < x)
            return posicio(x, v, medio+1, dre); 
            //H.I: retorna on esta x en v[l+1..r] si esta present si no retorna -1 
            //FITA: rang de busqueda decreix
    } 
  
    return -1; 
} 

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            int esq, dre;
            cin >> x >> esq >> dre;
            cout << posicio(x, V, esq, dre) << endl;
        }
    }
}