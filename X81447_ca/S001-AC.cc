#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef unsigned int nat;

template <typename T>
class pila { // pila en memòria dinàmica
public:
    pila();
    // Crea pila buida

    ~pila();
    // Destrueix el p.i.

    pila(const vector<int> &v);
    // Crea pila amb els elements de v amb el mateix ordre.

    nat longitud() const;
    // Retorna el nombre d’elements del p.i.

    void mostra() const;
    // Mostra el p.i. pel canal estàndard de sortida.

    void fusiona(const pila<T> &p2);
    // Pre: Les piles del p.i. i p2 estan ordenades de menor a major
    // Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica

private:
    struct node {
    T info;
    node* seg;
    };
    node* _cim; // Apunta al cim de la pila
    nat _mida;  // Nombre d’elements de la pila

    // Aquí va l’especificació dels mètodes privats addicionals
};
// Aquí va la implementació del mètode públic fusiona i privats addicionals

template <typename T>
void pila<T>::fusiona(const pila<T> &p2)
{
    node *pt_pi = _cim, *pt_p2 = p2._cim, *aux, *ant_pi;
    while(pt_pi != NULL and pt_p2 != NULL)
    {
        if(pt_pi->info < pt_p2->info) 
        {
            ant_pi = pt_pi;
            pt_pi = pt_pi->seg;
        }
        else if(pt_pi->info == pt_p2->info)
        {
            aux = new node;
            aux->info = pt_p2->info;
            aux->seg = pt_pi->seg;
            pt_pi->seg = aux;
            ant_pi = pt_pi;
            pt_pi = aux;
            pt_p2 = pt_p2->seg;
        }
        else if(pt_pi->info > pt_p2->info)
        {
            if(pt_pi == _cim)
            {
                aux = new node;
                aux->info = pt_p2->info;
                aux->seg = pt_pi;
                _cim = aux;
                ant_pi = aux;
                pt_p2 = pt_p2->seg;
            }
            else
            {
                aux = new node;
                aux->info = pt_p2->info;
                aux->seg = pt_pi;
                ant_pi->seg = aux;
                ant_pi = aux;
                pt_p2 = pt_p2->seg;
            }
        }
    }
    while(pt_p2 != NULL)
    {
        if(_cim == NULL)
        {
            aux = new node;
            aux->info = pt_p2->info;
            aux->seg = NULL;
            ant_pi = aux;
            _cim = aux;
            pt_p2 = pt_p2->seg;
        }
        else
        {
            aux = new node;
            aux->info = pt_p2->info;
            aux->seg = NULL;
            ant_pi->seg = aux;
            ant_pi = aux;
            pt_p2 = pt_p2->seg;
        }
    }
    _mida = _mida + p2._mida;
}