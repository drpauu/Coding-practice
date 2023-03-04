#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef unsigned int nat;

class graf
{
  // Graf dirigit i no etiquetat.
  // Les arestes es guarden en una matriu d’adjacència.
public:
  // Constructora per defecte. Crea un graf buit.
  graf();

  // Destructora
  ~graf();

  // Llegeix les dades del graf del canal d’entrada
  void llegeix();

  bool hi_ha_cami(nat ini, nat fi) const;
  // Pre: ini i fi són vèrtexs del graf (són menors que n)
  // Post: Retorna un booleà indicant si hi ha camí per anar d’ini a fi

private:
  nat n;                  // Nombre de vèrtexs
  nat m;                  // Nombre d’arestes
  vector<vector<bool>> a; // Matriu d’adjacència

  // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic hi_ha_cami i privats addicionals

bool graf::hi_ha_cami(nat ini, nat fi) const
{
  // Return false if either vertex is out of range
  if (ini >= n or fi >= n)
  {
    return false;
  }
  // Return true if there is a direct edge between the vertices
  if (a[ini][fi] == true)
  {
    return true;
  }
  // Use a queue to perform breadth-first search
  queue<nat> q;
  q.push(ini);
  vector<bool> vis(n, false); // visited vertices
  while (!q.empty())
  {
    nat u = q.front();
    q.pop();
    if (u == fi) // path found
    {
      return true;
    }
    if (!vis[u]) // visit vertex u
    {
      vis[u] = true;
      for (nat v = 0; v < n; v++) // explore neighbors of u
      {
        if (a[u][v] == true and !vis[v])
        {
          q.push(v);
        }
      }
    }
  }
  // Return false if no path was found
  return false;
}
/*
#include <iostream>
using namespace std;

graf::graf() : n(0), m(0) {}

graf::~graf() {}

void graf::llegeix()
{
  // Llegim el nombre de vèrtexs i arestes
  cin >> n >> m;

  // Creem la matriu d'adjacència
  a = vector<vector<bool>>(n, vector<bool>(n, false));

  // Llegim les m arestes
  nat u, v;
  for (nat i = 0; i < m; i++)
  {
    cin >> u >> v; // Aresta que connecta vèrtex u amb vèrtex v
    a[u][v] = true;
  }
}

int main()
{
  graf g;
  g.llegeix();
  nat ini, fi;
  while (cin >> ini >> fi)
  {
    if (g.hi_ha_cami(ini, fi))
      cout << "SI hi ha camí de " << ini << " a " << fi << endl;
    else
      cout << "NO hi ha camí de " << ini << " a " << fi << endl;
  }
  return 0;
}
*/