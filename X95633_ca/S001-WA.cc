#include <vector>
using namespace std;
typedef unsigned int nat;

class graf
{
  // Graf dirigit i no etiquetat.
  // Les arestes es guarden en multillistes d’adjacència en memòria dinàmica.
public:
  // Constructora per defecte. Crea un graf buit de n vèrtexs.
  graf(nat n);

  // Destructora
  ~graf();

  // Retorna un vector amb els successors del vèrtex v
  vector<nat> successors(nat v) const;

  // Retorna un vector amb els predecessors del vèrtex v
  vector<nat> predecessors(nat v) const;

  void insereix(nat orig, nat dest);
  // Pre: orig i dest són menors que el número de vèrtexs
  // Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
  // Si l’aresta ja existia no fa res.

private:
  nat nv; // Nombre de vèrtexs
  struct node
  {
    nat orig;       // Vèrtex origen
    nat dest;       // Vèrtex destí
    node *seg_succ; // Punter al següent successor
    node *seg_pred; // Punter al següent predecessor
  };
  vector<node *> prim_succ; // Punters al primer successor de cada vèrtex.
                            // La llista de successors està ordenada.
  vector<node *> prim_pred; // Punters al primer predecessor de cada vèrtex.
                            // La llista de predecessors està ordenada.

  // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic insereix i privats addicionals

void graf::insereix(nat orig, nat dest)
// Pre: orig i dest són menors que el número de vèrtexs
// Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
// Si l’aresta ja existia no fa res.
{
  // primero, comprobamos si la arista ya existe
  node *p = prim_succ[orig];
  while (p != nullptr)
  {
    if (p->dest == dest)
      return; // ya existe, no hacemos nada
    p = p->seg_succ;
  }

  // la arista no existe, la creamos
  // nuevo nodo de arista
  node *nuevo = new node();
  nuevo->orig = orig;
  nuevo->dest = dest;

  // insertamos el nodo en la lista de sucesores del origen
  nuevo->seg_succ = prim_succ[orig];
  prim_succ[orig] = nuevo;

  // insertamos el nodo en la lista de predecesores del destino
  nuevo->seg_pred = prim_pred[dest];
  prim_pred[dest] = nuevo;
}
/*
#include <iostream>
#include <sstream>

graf::graf(nat n) : nv(n)
{
  // Creem les multillistes d'adjacència dels n vèrtexs buides
  prim_succ = vector<node *>(n, nullptr);
  prim_pred = vector<node *>(n, nullptr);
}

graf::~graf()
{
  for (nat i = 0; i < nv; i++)
  {
    node *p = prim_succ[i];
    while (p != nullptr)
    {
      node *elim = p;
      p = p->seg_succ;
      delete elim;
    }
  }
}

vector<nat> graf::successors(nat v) const
{
  vector<nat> r;
  node *p = prim_succ[v];
  while (p != nullptr)
  {
    r.push_back(p->dest);
    p = p->seg_succ;
  }
  return r;
}

vector<nat> graf::predecessors(nat v) const
{
  vector<nat> r;
  node *p = prim_pred[v];
  while (p != nullptr)
  {
    r.push_back(p->orig);
    p = p->seg_pred;
  }
  return r;
}

int main()
{
  string linea, comanda;
  nat n;
  cin >> n;
  graf g(n);
  getline(cin, linea);

  // Processem comandes
  while (getline(cin, linea))
  {
    cout << linea << ":";
    istringstream ss(linea);
    ss >> comanda;

    if (comanda == "insereix")
    {
      nat orig, dest;
      ss >> orig >> dest;
      g.insereix(orig, dest);
    }
    else if (comanda == "successors")
    {
      nat v;
      ss >> v;
      vector<nat> r = g.successors(v);
      for (nat i = 0; i < r.size(); i++)
      {
        cout << " " << r[i];
      }
    }
    else if (comanda == "predecessors")
    {
      nat v;
      ss >> v;
      vector<nat> r = g.predecessors(v);
      for (nat i = 0; i < r.size(); i++)
      {
        cout << " " << r[i];
      }
    }
    cout << endl;
  }
  return 0;
}
*/