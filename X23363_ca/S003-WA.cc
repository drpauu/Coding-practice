#include <cstdlib>
#include <string>
#include <iostream>
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

    // Imprimeix la informació dels nodes en preordre, cada element en una nova línia i
    // precedit per espais segons el nivell on està situat.
    void preordre() const;

    static const int ArbreInvalid = 400;

    // Modifica el contingut dels nodes per tal de guardar a cada node l’altura
    // del seu subarbre
    void arbre_altures();

private:
    Arbre() : _arrel(NULL){};
    struct node
    {
        T info;        // Informació del node
        node *primf;   // Punter al primer fill
        node *seggerm; // Punter al següent germà
    };
    node *_arrel; // Punter a l’arrel de l’arbre
    static node *copia_arbre(node *p);
    static void destrueix_arbre(node *p) throw();
    static void preordre(node *p, string pre);
    static int altura(node *m, int h);
    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode arbre_altures i privats addicionals


template <typename T>
void Arbre<T>::arbre_altures(){
    int h = 0;
    node *m;
    m = _arrel;
    while(m != nullptr){
        m->info = altura(m, h);
        while(m->seggerm != nullptr){
            cout << "entra" << endl;
            m = m->seggerm;
            if(m->primf != nullptr) m->primf->info = altura(m->primf, h);
            m->info = altura(m, h);
        }
        m = m->primf;
    }
}

template <typename T>
int Arbre<T>::altura(node *m, int h){
    if(m == nullptr) return h;
    while(m != nullptr){
        h++;
        m = m->primf;
        if(m == nullptr) return h;
        while(m->seggerm != nullptr){
            int max = altura(m->seggerm, h);
            h = altura(m, h);
            if(max > h){
                return max;
            } else return h;
        }
    }
    return h;
}
