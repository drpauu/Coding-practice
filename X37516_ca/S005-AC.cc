#include <iostream>
#include <list>
using namespace std;
typedef unsigned int nat;

class dicc
{
public:
  // Constructora per defecte. Crea un diccionari buit.
  dicc();

  // Destructora
  ~dicc();

  void insereix(const string &k);
  // Pre: True
  // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.

  list<string> llista_ordenada_dec() const;
  // Pre: True
  // Post: Retorna una llista amb totes les claus ordenades decreixentment.

private:
  struct node
  {
    char _c;    // Símbol posició i-èssima de la clau
    node *_esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
    node *_cen; // Fill central, apunta a símbols següent posició
    node *_dre; // Fill dret, apunta a símbols mateixa posició formant un BST
    node(const char &c, node *esq = NULL, node *cen = NULL, node *dre = NULL);
  };
  node *_arrel;

  static void esborra_nodes(node *t);
  static node *insereix(node *t, nat i, const string &k);
  static void ordenar(node *t, list<string> &llista, string &paraula);
  static bool germa(node *t);
  // Aquí va l’especificació dels mètodes privats addicionals
};

bool dicc::germa(node *t)
{
  if (t->_esq == NULL and t->_cen == NULL and t->_dre == NULL)
  {
    return false;
  }
  else
    return true;
}

void dicc::ordenar(node *t, list<string> &llista, string &paraula)
{
  if (t != nullptr)
  {
    if (t->_c == '#')
    {
      llista.push_front(paraula);
      if (!germa(t))
      {
        return;
      }
      if (t->_esq != nullptr)
      {
        ordenar(t->_esq, llista, paraula);
      }
    }
    string paraula1 = paraula + t->_c;
    if (t->_esq != nullptr)
    {
      ordenar(t->_esq, llista, paraula);
    }
    if (t->_cen != nullptr)
    {
      ordenar(t->_cen, llista, paraula1);
    }
    if (t->_dre != nullptr)
    {
      ordenar(t->_dre, llista, paraula);
    }
  }
}

// Aquí va la implementació del mètode llista_ordenada_dec i privats addicionals
list<string> dicc::llista_ordenada_dec() const
{
  string paraula;
  list<string> llista;
  ordenar(_arrel, llista, paraula);
  return llista;
}
