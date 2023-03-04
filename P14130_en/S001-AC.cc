#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, cont=0;
    cin>>n;
    vector <int>algo(n);
    for(int i = 0; i < n; i++) {
       cin>>algo[i];
    }
    for(int j = 0; j < n-1; j++) {
       if(algo[n-1] == algo[j]) cont++;
    }
    cout<<cont<<endl;
}