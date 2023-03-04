#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int nat;

class dicc
{
public:
    dicc() : _arrel(NULL){};
    // Pre: Cert
    // Post: El resultat és un dicc sense cap element

    ~dicc();
    // Pre: Cert
    // Post: El dicc ha estat destruït

    void insereix(const int &k);
    // Pre: Cert
    // Post: La clau k s’ha inserit en el diccionari si no hi era. Retorna la clau dels nodes
    // visitats a on hi ha el desequilibri més proper a les fulles i un caràcter amb el seu
    // tipus de desequilibri: ’E’: Esquerre, ’D’: Dret, ’ ’: No s’ha trobat cap desequilibri

    bool consulta(int k);

private:
    struct node
    {
        int _k;      // Clau
        node *_esq;  // fill esquerre
        node *_dret; // fill dret
        nat _h;      // Altura del subarbre
    };
    node *_arrel;

    static void esborra_nodes(node *m);

    static node *insereix_bst(node *n, int k);

    node *consulta_bst(node *n, int &k);
};

dicc::node *dicc::consulta_bst(node *n, int &k)
{
    if (n == nullptr or n->_k == k)
    {
        return n;
    }
    else
    {
        if (k < n->_k)
            return consulta_bst(n->_esq, k);
        else
            // k > n->_k
            return consulta_bst(n->_dret, k);
    }
}

bool dicc::consulta(int k)
{
    node *n = consulta_bst(_arrel, k);
    if (n == nullptr)
    {
        return false;
    }
    else
    {
        k = n->_k;
        return true;
    }
}

dicc::node *dicc::insereix_bst(node *n, int k)
{
    if (n == nullptr)
    {
        node *nou = new node;
        nou->_k = k;
        nou->_esq = nullptr;
        nou->_dret = nullptr;
        return nou;
    }
    else if (k < n->_k)
    {
        n->_esq = insereix_bst(n->_esq, k);
    }
    else if (k > n->_k)
    {
        n->_dret = insereix_bst(n->_dret, k);
    }
    return n;
}

void dicc::insereix(const int &k)
{
    _arrel = insereix_bst(_arrel, k);
}

void dicc::esborra_nodes(node *m)
{
    if (m != NULL)
    {
        esborra_nodes(m->_esq);
        esborra_nodes(m->_dret);
        delete m;
    }
}

dicc::~dicc()
{
    esborra_nodes(_arrel);
}

int main()
{
    int n, t;
    dicc d;
    cin >>t;
    while(cin>>n){
        d.insereix(n);
    }
    int v;
    while (cin >> v)
    {
        cout << v << " " << d.consulta(v) << endl;
    }
    return 0;
}