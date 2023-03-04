#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc
{
public:
  dicc() : _arrel(NULL){};
  // Pre: Cert
  // Post: El resultat és un dicc sense cap element

  ~dicc();
  // Pre: Cert
  // Post: El dicc ha estat destruït

  pair<Clau, char> insereix(const Clau &k);
  // Pre: Cert
  // Post: La clau k s’ha inserit en el diccionari si no hi era. Retorna la clau dels nodes
  // visitats a on hi ha el desequilibri més proper a les fulles i un caràcter amb el seu
  // tipus de desequilibri: ’E’: Esquerre, ’D’: Dret, ’ ’: No s’ha trobat cap desequilibri

private:
  struct node
  {
    Clau _k;     // Clau
    node *_esq;  // fill esquerre
    node *_dret; // fill dret
    nat _h;      // Altura del subarbre
  };
  node *_arrel;

  static void esborra_nodes(node *m);

  // Aquí va l’especificació dels mètodes privats addicionals
  int altura(node *n);
  int factor_equilibri(node *n);
  node *insereix_bst(node *n, const Clau &k, pair<Clau, char> &res);
};

template <typename Clau>
typename dicc<Clau>::node *dicc<Clau>::insereix_bst(node *n, const Clau &k, pair<Clau, char> &res)
{
  // 1. Fem la inserció a un BST normal
  if (n == nullptr)
  {
    node *nou = new node;
    nou->_k = k;
    nou->_h = 1;
    nou->_esq = nullptr;
    nou->_dret = nullptr;
    return nou;
  }
  else if (k < n->_k)
    n->_esq = insereix_bst(n->_esq, k, res);
  else if (k > n->_k)
    n->_dret = insereix_bst(n->_dret, k, res);

  // 2. Actualitzem l’altura
  n->_h = max(altura(n->_esq), altura(n->_dret)) + 1;

  // 3. Obtenim el factor d’equilibri per veure si està balancejat
  int fe = factor_equilibri(n);

  if (res.second == ' ')
  {
    // Cas E
    if (fe > 1)
    {
      res.first = n->_k;
      res.second = 'E';
    }

    // Cas DD
    if (fe < -1)
    {
      res.first = n->_k;
      res.second = 'D';
    }
  }
  return n;
}

template <typename Clau>
pair<Clau, char> dicc<Clau>::insereix(const Clau &k)
{
  pair<Clau, char> res;
  res.second = ' ';
  _arrel = insereix_bst(_arrel, k, res);
  return res;
}

template <typename Clau>
int dicc<Clau>::altura(node *n)
{
  if (n == nullptr)
    return 0;
  else
    return n->_h;
}
template <typename Clau>
int dicc<Clau>::factor_equilibri(node *n)
{
  if (n == nullptr)
    return 0;
  else
    return altura(n->_esq) - altura(n->_dret);
}
/*
template <typename Clau>
void dicc<Clau>::esborra_nodes(node *m)
{
  if (m != NULL)
  {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
dicc<Clau>::~dicc()
{
  esborra_nodes(_arrel);
}

int main()
{
  int n;
  dicc<int> d;
  while (cin >> n)
  {
    vector<int> v;
    pair<int, char> desq = d.insereix(n);
    cout << "insereix " << n << ':';
    if (desq.second != ' ')
    {
      cout << ' ' << desq.first << ' ' << desq.second;
    }
    cout << endl;
  }
  return 0;
}
*/