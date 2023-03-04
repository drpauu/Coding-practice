#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
typedef unsigned int nat;

template <typename T>
class cua { // Cua no circular en memòria dinàmica
public:
    cua();
    // Construeix una cua buida.

    ~cua();
    // Destrueix el p.i.

    cua(const vector<int> &v);
    // Crea cua amb els elements de v amb el mateix ordre.

    nat longitud() const;
    // Retorna el nombre d’elements del p.i.

    void mostra() const;
    // Mostra el p.i. pel canal estàndard de sortida.

    void fusiona(const cua<T> &c2);
    // Pre: Les cues del p.i. i c2 estan ordenades de menor a major
    // Post: Al p.i. se li han afegit els elements de c2 ordenadament. c2 no es modifica

private:
    struct node {
    T info;
    node* seg;
    };
    node* _pri; // Apunta al primer element de la cua
    node* _ult; // Apunta al darrer element de la cua
    nat _mida;

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic fusiona i privats addicionals

template <typename T>
void cua<T>::fusiona(const cua<T> &c2)
{
    node *pt_ci = _pri, *pt_c2 = c2._pri, *ant, *aux;
    while(pt_ci != NULL and pt_c2 != NULL)
    {
        if(pt_ci->info < pt_c2->info)
        {
            ant = pt_ci;
            pt_ci = pt_ci->seg;
        }
        else if(pt_ci->info == pt_c2->info)
        {
            aux = new node;
            aux->info = pt_c2->info;
            aux->seg = pt_ci->seg;
            pt_ci->seg = aux;
            if(pt_ci == _ult) _ult = aux;
            ant = pt_ci;
            pt_ci = aux;
            pt_c2 = pt_c2->seg;
        }
        else if(pt_ci->info > pt_c2->info)
        {
            if(pt_ci == _pri)
            {
                aux = new node;
                aux->info = pt_c2->info;
                aux->seg = pt_ci;
                _pri = aux;
                ant = aux;
                pt_c2 = pt_c2->seg;
            }
            else
            {
                aux = new node;
                aux->info = pt_c2->info;
                aux->seg = pt_ci;
                ant->seg = aux;
                ant = aux;
                pt_c2 = pt_c2->seg;
            }
        }
    }
    while(pt_c2 != NULL)
    {
        if(_pri == NULL)
        {
            aux = new node;
            aux->info = pt_c2->info;
            aux->seg = NULL;
            ant = aux;
            _pri = aux;
            _ult = aux;
            pt_c2 = pt_c2->seg;
        }
        else
        {
            aux = new node;
            aux->info = pt_c2->info;
            aux->seg = NULL;
            ant->seg = aux;
            ant = aux;
            _ult = aux;
            pt_c2 = pt_c2->seg;
        }
    }
    _mida += c2._mida;
}