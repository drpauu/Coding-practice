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
void dic::insereix(const int &k)
{
  int i = hash(k);
  node_hash *p = _taula[i];
  bool trobat = false;
  while (p != nullptr and not trobat)
  {
    if (p->_k == k)
    {
      trobat = true;
    }
    else
    {
      p = p->_seg;
    }
  }
  if (trobat)
  {
    // Només canviem el valor associat
    p->_v = v;
  }
  else
  {
    // Cal crear un nou node i l’afegim al principi
    _taula[i] = new node_hash(k, v, _taula[i]);
    ++_quants;
  }
}

// Pre: El diccionari res està buit
// Post: Omple res amb la intersecció entre el p.i. i d2
void dicc::interseccio(const dicc &d2, dicc &res) const
{
  cout << "arixo val M: " << _M << endl;
  for (int i = 0; i < _M; i++)
  {
    node_hash *p = _taula[i];
    while (p != nullptr)
    {
      res.insereix(p->_k);
      p = p->_seg;
    }
  }
  for (int i = 0; i < d2._M; i++)
  {
    node_hash *p = d2._taula[i];
    while (p != nullptr)
    {
      res.insereix(p->_k);
      p = p->_seg;
    }
  }
}
