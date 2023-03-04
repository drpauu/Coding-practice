#include <iostream>
using namespace std;


int mcd(int a, int b)
{
    if (a == 0)
        return b;
    return mcd(b % a, a);
}
 
int main()
{
    int a, b;
    while(cin >> a >> b){
    	cout<< mcd(a,b) <<endl;
    }
    return 0;
}
