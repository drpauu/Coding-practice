#include <cstddef>
#include <vector>
using namespace std;
typedef unsigned int nat;

class Llista
{
  // Llista doblement encadenada, no circular i sense fantasma.

public:
  Llista();
  // Pre: True
  // Post: El p.i. és una llista buida.

  Llista(const vector<int> &v);
  // Pre: True
  // Post: El p.i. conté els elements de v amb el mateix ordre.

  ~Llista();
  // Post: Destrueix els elements del p.i.

  nat longitud() const;
  // Pre: True
  // Post: Retorna el nombre d’elements del p.i.

  void mostra() const;
  // Pre: True
  // Post: Mostra el p.i. pel canal estàndard de sortida.

  void mostra_invertida() const;
  // Pre: True
  // Post: Mostra el p.i. en ordre invers pel canal estàndard de sortida.

  void ordena();
  // Pre: True
  // Post: S’han ordenat eficientment els elements del p.i. de major a menor

private:
  struct node
  {
    int info;  // Informació del node
    node *seg; // Punter al següent element
    node *ant; // Punter a l’anterior element
  };
  node *_prim; // Punter al primer element
  node *_ult;  // Punter a l’últim element
  nat _long;   // Nombre d’elements

  // Aquí va l’especificació dels mètodes privats addicionals
};

void Llista::ordena()
{
  node *p = _prim;
  bool swapped;
  for (int i = 0; i < _long; i++)
  {
    swapped = false;
    while (p->seg != nullptr)
    {
      if (p->info < p->seg->info)
      {
        int temp = p->info;
        p->info = p->seg->info;
        p->seg->info = temp;
        swapped = true;
      }
      p = p->seg;
    }
    if (!swapped)
      break;
    p = _ult;
    while (p->ant != nullptr)
    {
      if (p->info > p->ant->info)
      {
        int temp = p->info;
        p->info = p->ant->info;
        p->ant->info = temp;
        swapped = true;
      }
      p = p->ant;
    }
    if (!swapped)
      break;
    p = _prim;
  }
}
