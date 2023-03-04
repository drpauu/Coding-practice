#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

stack<int> suma(stack<int> sint, stack<string> sstring, stack <int> s, int c){
    stack<int> aux = sint;
    stack<int> aux2 = sint;
    if(sstring.empty()) return s;
    if(sstring.top() == "above"){
        int ab = 0;
        for(int i = 0; i < c; i++){
            ab = ab + aux.top();
            aux.pop();
        }
        s.push(ab);
        c++;
        sstring.pop();
        return suma(sint, sstring, s, c);
    }else {
        int ab = 0;
        for(int i = 0; i < c-1; i++){
            int ab = aux.top();
            aux.pop();
        }
        while(!aux.empty()){
            ab = ab + aux.top();
            aux.pop();
        }
        s.push(ab);
        c++;
        sstring.pop();
        return suma(sint, sstring, s, c);
    }
}

stack<int> reverse(stack<int> s){
    stack<int> r;
    while(!s.empty()){
        r.push(s.top());
        s.pop();
    }
    return r;
}

stack<int> sumAboveOrBelow(stack<int> sint, stack<string> sstring){
    stack<int> s;
    int c = 1;
    return reverse(suma(sint, sstring, s, c));
}

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS
static stack<int> readStackInt(string line)
{
    istringstream mycin(line);
    stack<int> s;
    int x;
    while (mycin >> x)
        s.push(x);
    return s;
}

static stack<string> readStackString(string line)
{
    istringstream mycin(line);
    stack<string> s;
    string x;
    while (mycin >> x)
        s.push(x);
    return s;
}

template <typename T>
static void writeStack(stack<T> s)
{
    vector<T> v;
    while (not s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    for (int i = int(v.size())-1; i >= 0; i--) {
        if (i < int(v.size())-1) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
#endif

int main()  {
    vector<stack<int> > v;
    vector<stack<string> > vs;
    string s;
    while (getline(cin, s)) {
        v.push_back(readStackInt(s));
        getline(cin, s);
        vs.push_back(readStackString(s));
    }
    for (int i = 0; i < int(v.size()); ++i) {
        stack<int> s;
        for (int j = 0; j < 30; ++j)
        	s = sumAboveOrBelow(v[i], vs[i]);
        writeStack(s);
    }
}