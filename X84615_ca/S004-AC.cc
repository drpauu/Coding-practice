#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

class dicc
{
public:
  // Constructora per defecte. Crea un diccionari buit.
  dicc();

  // Destructora
  ~dicc();

  // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
  void insereix(const string &k);

  vector<nat> freq_longituds() const;
  // Pre: True
  // Post: Retorna un vector amb les freqüències de les longituds de les claus.
  // La mida del vector és igual a la longitud de la clau més llarga més un.

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
  static nat longitud_maxima_clau(node *t);
  static void recorre_trie_longitud(node *t, nat longitud, nat &max);
  static void recorre_trie(node *t, nat longitud, vector<nat> &freq);
  // Aquí va l’especificació dels mètodes privats addicionals
};

nat dicc::longitud_maxima_clau(node *t)
{
  nat max = 0;
  recorre_trie_longitud(t, 0, max);
  return max;
}

void dicc::recorre_trie_longitud(node *t, nat longitud, nat &max)
{
  if (t == NULL)
    return;
  if (t->_c == '#')
  {
    max = max > longitud ? max : longitud;
  }
  recorre_trie_longitud(t->_esq, longitud, max);
  recorre_trie_longitud(t->_cen, longitud + 1, max);
  recorre_trie_longitud(t->_dre, longitud, max);
}

vector<nat> dicc::freq_longituds() const
{
  vector<nat> freq;
  if (longitud_maxima_clau(_arrel) == 0)
  {
    return freq;
  }
  else
  {
    vector<nat> ret(longitud_maxima_clau(_arrel) + 1, 0);
    recorre_trie(_arrel, 0, ret);
    return ret;
  }
}

void dicc::recorre_trie(node *t, nat longitud, vector<nat> &freq)
{
  if (t == NULL)
    return;
  if (t->_c == '#')
  { // Si es troba el símbol de final de clau, incrementem la freqüencia de la longitud
    freq[longitud]++;
  }
  recorre_trie(t->_esq, longitud, freq);
  recorre_trie(t->_cen, longitud + 1, freq);
  recorre_trie(t->_dre, longitud, freq);
}

/*
    O(1) o notación constante: indica que el número de operaciones es constante, independientemente del tamaño de los datos de entrada. Ejemplo: acceder a un elemento de un array utilizando un índice.

    O(log n): indica que el número de operaciones crece a medida que aumenta el tamaño de los datos de entrada, pero a un ritmo más lento que la línea recta. Ejemplo: búsqueda binaria.

    O(n): indica que el número de operaciones es proporcional al tamaño de los datos de entrada. Ejemplo: búsqueda lineal.

    O(n log n): indica que el número de operaciones es proporcional al producto del tamaño de los datos de entrada y logaritmo del tamaño de los datos de entrada. Ejemplo: ordenamiento rápido.

    O(n^2): indica que el número de operaciones es proporcional al cuadrado del tamaño de los datos de entrada. Ejemplo: ordenamiento burbuja.

    O(2^n): indica que el número de operaciones se multiplica exponencialmente a medida que aumenta el tamaño de los datos de entrada. Ejemplo: problema de las 8 reinas.

Para calcular los costes de una función, debes seguir los siguientes pasos:

    Identifica la función que deseas analizar.
    Identifica las operaciones básicas que se realizan en la función.
    Identifica las variables que afectan al número de operaciones básicas que se realizan.
    Utiliza esta información para determinar la relación entre el número de operaciones básicas y las variables que afectan al número de operaciones.
    Utiliza esta relación para determinar el número de operaciones básicas en términos de las variables. Esto es el costo de la función en términos de la notación O.
*/
