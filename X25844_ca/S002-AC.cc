#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename T>
class pila
{ // pila en memòria dinàmica
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

    void duplica_amb_sumes();
    // Pre: true
    // Post: S’han duplicat els elements de la pila, a sobre de cada element hi ha un
    // nou element que conté la suma dels elements restants de la pila original

private:
    struct node
    {
        T info;
        node *seg;
    };
    node *_cim; // Apunta al cim de la pila
    nat _mida;  // Nombre d’elements de la pila

    // Aquí va l’especificació dels mètodes privats addicionals
    int duplica_amb_sumes_recursiu(node *p, node *ant);
};

// Aquí va la implementació del mètode duplica_amb_sumes i dels privats addicionals

template <typename T>
void pila<T>::duplica_amb_sumes()
{
    int suma = duplica_amb_sumes_recursiu(_cim, nullptr);
}

template <typename T>
int pila<T>::duplica_amb_sumes_recursiu(node *p, node *ant)
{
    node *nou;
    int suma;
    if (p == NULL)
    {
        suma = 0;
    }
    else if (p == _cim)
    {
        nou = new node;
        suma = p->info + duplica_amb_sumes_recursiu(p->seg, p);
        nou->info = suma;
        nou->seg = p;
        _cim = nou;
        ++_mida;
    }
    else
    {
        nou = new node;
        suma = p->info + duplica_amb_sumes_recursiu(p->seg, ant->seg);
        nou->info = suma;
        nou->seg = p;
        ant->seg = nou;
        ++_mida;
    }
    return suma;
}