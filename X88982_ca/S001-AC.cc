#include <cstdlib>
#include <string>
using namespace std;
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

  // Comprova que el contingut de cada node coincideix amb la suma dels nodes
  // dels seus fills, exceptuant les fulles (els de grau 0).
  bool es_arbre_suma();

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
  static bool sumes(node *m);

  // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode es_arbre_suma

template <typename T>
bool Arbre<T>::es_arbre_suma()
{
  return sumes(_arrel);
}

template <typename T>
bool Arbre<T>::sumes(node *m)
{
  bool es_suma = true;
  if(m != nullptr){
    if(m->primf != nullptr){
      int suma = 0;
      int pare = m->info;
      m = m->primf;
      while(m != nullptr){
        suma = suma + m->info;
        if(!sumes(m)) return false;
        m = m->seggerm;
      }
      if(pare != suma)  return false;
    }
  }
  return es_suma;
}