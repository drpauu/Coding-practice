#include <iostream>
using namespace std;

int main() {
int x, y, z;
cin >>x>>y>>z;
if (x>=y and x>=z) 
	cout<<x<<endl;
else if (y>=x and y>=z)
	cout<<y<<endl;
else 
	cout<<z<<endl;
}
