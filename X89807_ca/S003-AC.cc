#include <vector>
using namespace std;
typedef unsigned int nat;

class graf
{
  // Graf dirigit i no etiquetat.
  // Les arestes es guarden en llistes d’adjacència (vector amb els successors).
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
  nat n;                 // Nombre de vèrtexs
  nat m;                 // Nombre d’arestes
  vector<vector<nat>> a; // Vectors amb els successors de cada vèrtex

  // Aquí va l’especificació dels mètodes privats addicionals

  bool hi_ha_cami_dfs(nat u, nat fi, vector<bool>& vis) const;

};

// Aquí va la implementació del mètode públic hi_ha_cami i privats addicionals

/*
bool graf::hi_ha_cami(nat ini, nat fi) const
{
  // Return false if either vertex is out of range
  if (ini >= n or fi >= n)
  {
    return false;
  }
  if (ini == fi)
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
      for (nat v : a[u]) // explore neighbors of u
      {
        if (!vis[v])
        {
          q.push(v);
        }
      }
    }
  }
  // Return false if no path was found
  return false;
}
*/

bool graf::hi_ha_cami(nat ini, nat fi) const
{
  // Return false if either vertex is out of range
  if (ini >= n or fi >= n)
  {
    return false;
  }
  if(ini == fi){
    return true;
  }
  // Perform depth-first search
  vector<bool> vis(n, false); // visited vertices
  return hi_ha_cami_dfs(ini, fi, vis);
}

bool graf::hi_ha_cami_dfs(nat u, nat fi, vector<bool>& vis) const
{
  if (u == fi) // path found
  {
    return true;
  }
  if (!vis[u]) // visit vertex u
  {
    vis[u] = true;
    for (nat v : a[u]) // explore neighbors of u
    {
      if (hi_ha_cami_dfs(v, fi, vis))
      {
        return true;
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

  // Creem les llistes d'adjacència (vectors amb els successors dels n vèrtexs)
  a = vector<vector<nat>>(n);

  // Llegim les m arestes
  nat u, v;
  for (nat i = 0; i < m; i++)
  {
    cin >> u >> v; // Aresta que connecta vèrtex u amb vèrtex v
    a[u].push_back(v);
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