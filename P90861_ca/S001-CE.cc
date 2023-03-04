#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void escriuCues(vector< queu<string> >& Q)
{
    cout << "continguts finals" << endl;
    cout << "-----------------" << endl;

    for (int i = 0; i < Q.size(); i++)
    {
        cout << "cua" << i+1 << ":";

        while (not Q[i].empty())
        {
            cout << " " << Q[i].front() << " ";
            Q[i].pop();
        }
        cout << endl;
    }
    return;
};

int main()
{
    int n;
    cin >> n;
    vector< queu<string> >& Q;

    string s;
    getline(cin, s);

    for (int i = 0 ; i < n; i++)
    {
        getline(cin, s);
        istringstream ss(s);
        string nom;
        while (ss >> nom) Q[i].push(nom);
    }

    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;

    string comanda;
    while (cin >> comanda)
    {
        if (comanda == "SURT")
        {
            int i;
            cin >> i;
            if (i >= 1 and i <= n and not Q[i-1].emty())
            {
                string sortida = Q[i-1].front();
                Q[i-1].pop();
                cout << sortida << endl;
            }
        }
        if (comanda == "ENTRA")
        {
            int i;
            string comanda;
            cin >> entrada >> i;

            if (i >= 1 and i <= n)      Q[i-1].push(entrada);
        }
    }
    escriuCues (Q);
    return 0;
} 