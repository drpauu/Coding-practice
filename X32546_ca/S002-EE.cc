#include <iostream>
using namespace std;
typedef unsigned int nat;

class dicc {
  // Taula de dispersió amb direccionament obert fent sondeig lineal.
public:
  dicc(nat m);
  // Pre: m > 0
  // Post: Crea un diccionari buit en una taula de dispersió de mida m

  ~dicc();
  // Pre: Cert
  // Post: Destrueix el diccionari

  nat quants() const;
  // Pre: Cert
  // Post: Retorna quants elements (claus) té el diccionari.

  void print() const;
  // Pre: Cert
  // Post: Imprimeix per cout del contingut de la taula de dispersió

  void insereix(const int &k);
  // Pre: Cert
  // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
  // Redimensiona la taula de dispersió amb una mida el doble que
  // l’anterior més un si el factor de càrrega és superior a 0.8

  float factor_de_carrega() const;
  // Pre: Cert
  // Post: Retorna el factor de càrrega de la taula de dispersió

  void redispersio();
  // Pre: Cert
  // Post: Redimensiona la taula de dispersió amb una mida el doble que
  // l’anterior més un (_M passa a ser 2*_M+1)

private:
  enum Estat { lliure, esborrat, ocupat };
  struct node_hash {
    int _k; // Clau
    Estat _est;
  };
  node_hash *_taula; // Taula amb les claus del diccionari
  nat _M;            // Mida de la taula
  nat _quants;       // Nº d’elements guardats al diccionari

  static long const MULT = 31415926;

  static long h(int k);
  // Pre: Cert
  // Post: Retorna un valor de dispersió entre 0 i LONG_MAX a partir de k

  nat busca_node(const int &k) const;
  // Pre: Cert
  // Post: Retorna la posició on es troba l’element amb la clau k o,
  // en cas que no trobi la clau, la primera posició no ocupada.

  // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació dels mètodes públics factor_de_carrega, redispersio
// i dels mètodes privats addicionals

float dicc::factor_de_carrega() const
// Pre: Cert
// Post: Retorna el factor de càrrega de la taula de dispersió
{
  // Retornem el factor de càrrega com el nombre d'elements dividit
  // per la mida de la taula.
  return (float)_quants / _M;
}

void dicc::redispersio() {
  // Declare the variable temp
  node_hash *temp;
  // Creem una taula temporal amb la mida el doble que l'anterior més un.
  temp = new node_hash[2 * _M + 1];
  // Inicialitzem la taula temporal com buida.
  for (nat i = 0; i < 2 * _M + 1; ++i)
    temp[i]._est = lliure;
  // Recorrem la taula original i reinsertem tots els elements ocupats en la
  // temporal.
  for (nat i = 0; i < _M; ++i) {
    if (_taula[i]._est == ocupat) {
      // Cerca la posició de inserció de la clau en la taula temporal.
      nat pos = busca_node(_taula[i]._k);
      // Insereix la clau en la posició trobada.
      temp[pos]._k = _taula[i]._k;
      temp[pos]._est = ocupat;
    }
  }
  // Esborrem la taula original.
  delete[] _taula;
  // La taula original ara és la temporal.
  _taula = temp;
  // Actualitzem la mida de la taula.
  _M = 2 * _M + 1;
}
/*
#include <iostream>
#include <sstream>
using namespace std;

long dicc::h(int k) {
  long i = (((k + 1) * k * MULT) << 47) >> 7;
  if (i < 0)
    i = -i;
  return i;
}

dicc::dicc(nat m) : _M(m), _quants(0) {
  _taula = new node_hash[_M];
  for (nat i = 0; i < _M; ++i) {
    _taula[i]._est = lliure;
  }
}

dicc::~dicc() { delete[] _taula; };

nat dicc::quants() const { return _quants; }

void dicc::print() const {
  for (nat i = 0; i < _M; ++i) {
    cout << i << ": ";
    if (_taula[i]._est == ocupat)
      cout << _taula[i]._k;
    else if (_taula[i]._est == lliure)
      cout << "LL";
    else if (_taula[i]._est == esborrat)
      cout << "ES";
    cout << endl;
  }
  cout << "-----------\n";
}

nat dicc::busca_node(const int &k) const {
  nat i = h(k) % _M;
  // prilliure és la primera posició esborrada que
  // trobem, val -1 si no trobem cap posició esborrada.
  int prilliure = -1;
  // comptem el nombre d'elements que visitem per només fer una passada.
  nat cont = 0;
  while (((_taula[i]._est == ocupat and _taula[i]._k != k) or
          _taula[i]._est == esborrat) and
         cont < _M) {
    ++cont;
    if (_taula[i]._est == esborrat and prilliure == -1) {
      prilliure = i;
    }
    i = (i + 1) % _M;
  }
  if (_taula[i]._est == lliure and prilliure != -1)
    i = prilliure;
  return i;
}

void dicc::insereix(const int &k) {
  nat i = busca_node(k);
  if (_taula[i]._est != ocupat) {
    ++_quants;
  }
  _taula[i]._k = k;
  _taula[i]._est = ocupat;
  if (factor_de_carrega() > 0.8) {
    redispersio();
  }
}

int main() {
  string linea;
  int n;
  cin >> n;
  getline(cin, linea);
  dicc d(n);

  // Inserim alguns elements al diccionari
  getline(cin, linea);
  istringstream ss1(linea);
  while (ss1 >> n) {
    d.insereix(n);
  }
  cout << "Nº elem: " << d.quants() << endl;
  cout << "Factor de càrrega: " << d.factor_de_carrega() << endl;
  d.print();

  // Inserim alguns elements al diccionari
  getline(cin, linea);
  istringstream ss2(linea);
  while (ss2 >> n) {
    d.insereix(n);
  }
  cout << "Nº elem: " << d.quants() << endl;
  cout << "Factor de càrrega: " << d.factor_de_carrega() << endl;
  d.print();

  return 0;
}
*/
