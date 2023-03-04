#include <iostream>

using namespace std;

int main (){
	int n, m = 1, s;
	cin>>n;
	for(int i = 0; i < n; i++){
		s = m*n;
		cout<<n<<" "<<"x "<<m<<" = "<<s<<endl;
		m++;
	}
}
