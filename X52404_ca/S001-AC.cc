#include <cstdlib>
#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Abin
{
public:
  Abin() : _arrel(NULL){};
  // Pre: cert
  // Post: el resultat és un arbre sense cap element
  Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
  // Pre: cert
  // Post: el resultat és un arbre amb un element i dos subarbres

  // Les tres grans
  Abin(const Abin<T> &a);
  ~Abin();
  Abin<T> &operator=(const Abin<T> &a);

  // operador << d’escriptura
  template <class U>
  friend std::ostream &operator<<(std::ostream &, const Abin<U> &a);

  // operador >> de lectura
  template <class U>
  friend std::istream &operator>>(std::istream &, Abin<U> &a);

  // Modifica el contingut de l’arbre per tal de guardar a cada node la suma dels
  // nodes del seu subarbre.
  void arbre_sumes();

private:
  struct node
  {
    node *f_esq;
    node *f_dret;
    T info;
  };
  node *_arrel;
  static node *copia_nodes(node *m);
  static void esborra_nodes(node *m);
  static void print_nodes(node *m, ostream &os, string d1);
  static Abin<T> suma(node *m);

  // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode arbre_sumes

template <typename T>
void Abin<T>::arbre_sumes()
{
  *this = suma(_arrel);
}

template <typename T>
Abin<T> Abin<T>::suma(node *m)
{
  int vfd, vfe, arrel;
  if (m == nullptr)
    return Abin<T>();
  Abin<T> filld, fille;
  filld = suma(m->f_dret);
  fille = suma(m->f_esq);
  if (m->f_dret == nullptr)
    vfd = 0;
  else
    vfd = filld._arrel->info;
  if (m->f_esq == nullptr)
    vfe = 0;
  else
    vfe = fille._arrel->info;
  arrel = m->info + vfe + vfd;
  return Abin<T>(fille, arrel, filld);
}
