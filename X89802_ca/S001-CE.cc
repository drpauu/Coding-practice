#include <iostream>
using namespace std;
typedef unsigned int nat;

class dicc
{
    // Taula de dispersió sinònims encadenats indirectes
    // Les llistes de sinònims estan ordenades per clau
public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Impressió per cout de totes les claus del diccionari segons l’ordre
    // en que estan a cadascuna de les llistes encadenades indirectes
    void print() const;

    // Pre: Cert
    // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const int &k);

    // Pre: El diccionari res està buit
    // Post: Omple res amb la intersecció entre el p.i. i d2
    void interseccio(const dicc &d2, dicc &res) const;

private:
    struct node_hash
    {
        int _k; // Clau
        node_hash *_seg;
    };
    node_hash **_taula; // Taula amb punters a les llistes de sinònims
    nat _M;             // Mida de la taula
    nat _quants;        // Nº d’elements guardats al diccionari

    static long const MULT = 31415926;

    // Calcula un valor de dispersió entre 0 i LONG_MAX a partir de k
    static long h(int k);

    // Destrueix la llista de nodes apuntats per p
    static void esborra_nodes(node_hash *p);

    // Aquí va l’especificació dels mètodes privats addicionals

};

// Pre: Cert
// Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
void dicc::insereix(const int &k)
{
    node_hash *p = new node_hash;
    p->_k = k;
    _taula[h(p->_k)]->_k = p->_k;

// Pre: El diccionari res està buit
// Post: Omple res amb la intersecció entre el p.i. i d2
void dicc::interseccio(const dicc &d2, dicc &res) const {}

#include <iostream>
#include <sstream>
using namespace std;

long dicc::h(int k)
{
    long i = ((k * k * MULT) << 20) >> 4;
    if (i < 0)
        i = -i;
    return i;
}

dicc::dicc() : _quants(0)
{
    _M = 13;
    _taula = new node_hash *[_M];
    for (int i = 0; i < _M; ++i)
    {
        _taula[i] = NULL;
    }
}

void dicc::esborra_nodes(node_hash *p)
{
    if (p != NULL)
    {
        esborra_nodes(p->_seg);
        delete p;
    }
};

dicc::~dicc()
{
    for (int i = 0; i < _M; ++i)
    {
        esborra_nodes(_taula[i]);
    }
    delete _taula;
};

nat dicc::quants() const
{
    return _quants;
}

void dicc::print() const
{
    for (int i = 0; i < _M; ++i)
    {
        cout << i << ": ";
        node_hash *p = _taula[i];
        while (p != NULL)
        {
            cout << p->_k << " ";
            p = p->_seg;
        }
        cout << endl;
    }
    cout << "-----------\n";
}

int main()
{
    string linea;
    int n;
    dicc d1, d2, dr;

    // Obtenim elements 1er diccionari
    getline(cin, linea);
    istringstream ss1(linea);
    while (ss1 >> n)
    {
        d1.insereix(n);
    }
    cout << "Nº elem: " << d1.quants() << endl;
    d1.print();

    // Obtenim elements 2on diccionari
    getline(cin, linea);
    istringstream ss2(linea);
    while (ss2 >> n)
    {
        d2.insereix(n);
    }
    cout << "Nº elem: " << d2.quants() << endl;
    d2.print();

    // Intersecció
    d1.interseccio(d2, dr);
    cout << "Nº elem: " << dr.quants() << endl;
    dr.print();

    return 0;
}