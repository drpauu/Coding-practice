#include <cstdlib>
using namespace std;
#include <iostream>
typedef unsigned int nat;

template <typename T>
class Arbre
{

public:
  // Construeix un Arbre format per un únic node que conté a x.
  Arbre(const T &x);

  // Tres grans.
  Arbre(const Arbre<T> &a);
  Arbre &operator=(const Arbre<T> &a);
  ~Arbre() throw();

  // Col·loca l’Arbre donat com a primer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
  void afegir_fill(Arbre<T> &a);

  static const int ArbreInvalid = 400;

  // Indica quants nodes de grau n té.
  nat quants_grau(nat n) const;

private:
  Arbre() : _arrel(NULL){};
  struct node
  {
    T info;
    node *primf;
    node *seggerm;
  };
  node *_arrel;
  static node *copia_arbre(node *p);
  static void destrueix_arbre(node *p) throw();
  static void grau(node *m, int n, int &cont);
  // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode quants_grau

template <typename T>
void Arbre<T>::grau(node *m, int n, int &cont)
{
  if(m == nullptr){
    return;
  }
  if(n > 0){

    if(m->seggerm != nullptr){
      grau(m->seggerm, n, cont);
    }
    int s = n-1;
    grau(m->primf, s, cont);
    return;
  }
  node *a;
  a = m;
  cont++;
  while(a->seggerm != nullptr){
    cont++;
    a = a->seggerm;
  }
}

template <typename T>
nat Arbre<T>::quants_grau(nat n) const
{
  int cont = 0;
  int nn;
  nn = n;
  grau(_arrel, nn, cont);
  nat grade;
  grade = cont;
  return grade;
}