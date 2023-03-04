#include <sstream>
#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool checkString(string s)
// Pre: cert
// Post: retorna true si la string donada es una sequencia correcta de paretesis o corchetes, false en cas contrari
{
    stack <char> st;

    for (int i=0; i < int( s.size()); ++i) {
        char x = s[i];
        if (x == '(' or x == '[' ){
            st.push(x);
        } else {

            if (not st.empty()){
                if (x == ']') 
                    if (st.top() != '[') {
                        return false;
                    }
    
                if (x == ')') 
                    if ( st.top() != '(') {
                        return false;
                    }
        
                st.pop();
            } else {
                return false;
            }
        }
            
    }
    
    if (st.empty())
        return true;
    return false;
}


int main() {
    string s;
    while (getline(cin, s)) {
        istringstream ss(s);
        string x;
        while (ss >> x) {
            cout << x;
            bool correcte = checkString(x);
            if (correcte == true)
                cout << " is correct";
            else
                cout << " is incorrect";

            cout << endl;
        }
    }

}
