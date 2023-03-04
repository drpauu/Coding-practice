#include <iostream>
#include <vector>

using namespace std; 

int max(vector <int> v, int &rep){
	int max = -1, int aux;
	vector <int> cont(v.size(), 0);
	for(unsigned int i = 0; i < v.size(); i++){
		for(unsigned int j = 0; j < v.size(); j++){
			if(v[i] == v[j]){
				v[i] += 1;
			}
		}
	}
	for(unsigned int i = 0; i < v.size(); i++){
		if(cont[i] > max){
		max = cont[i]:
		aux = i;
		}
	}
	rep = v[aux];
	return max;
}

int main () {
	int a;
	cin>>a;
	vector <int> v(a);
	for(int i = 0; i < a; i++){
		cin>>v[i];
	}
	int b;
	cin>>b;
	vector <int> m(b);
	for(int i = 0; i < b; i++){
		cin>>m[i];
	}
	vector <int> s(a+b);
	for(int i = 0; i < a+b; i++){
		if(i < a){
			v[i] = s[i]
		} else {
			m[i] = s[i]
		}
	}
	int rep, cont = 0;
	cont = max(s, rep); 
	cout<<rep<<" "<<cont<<endl;
}

