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

  node *merge(node *first, node *second);

  node *mergeSort(node *head);

  node *split(node *head);

  node *getTail(node *cur);
  // Aquí va l’especificació dels mètodes privats addicionals
};

void Llista::ordena()
{
  _prim = mergeSort(_prim);
  _ult = getTail(_prim);
}

Llista::node *Llista::mergeSort(node *head)
{
  if (!head || !head->seg)
    return head;

  node *second = split(head);

  head = mergeSort(head);
  second = mergeSort(second);

  return merge(head, second);
}

Llista::node *Llista::split(node *head)
{
  node *fast = head, *slow = head;
  while (fast->seg && fast->seg->seg)
  {
    fast = fast->seg->seg;
    slow = slow->seg;
  }
  node *temp = slow->seg;
  slow->seg = nullptr;
  return temp;
}

Llista::node *Llista::merge(node *first, node *second)
{
  if (!first)
    return second;

  if (!second)
    return first;

  if (first->info > second->info)
  {
    first->seg = merge(first->seg, second);
    first->seg->ant = first;
    first->ant = nullptr;
    return first;
  }
  else
  {
    second->seg = merge(first, second->seg);
    second->seg->ant = second;
    second->ant = nullptr;
    return second;
  }
}

Llista::node *Llista::getTail(node *cur)
{
  while (cur != nullptr && cur->seg != nullptr)
    cur = cur->seg;
  return cur;
}
/*
#include <iostream>
#include <sstream>

Llista::Llista() : _long(0) {
  _ult = _prim = nullptr;
}

Llista::Llista(const vector<int> &v) : _long(v.size()) {
  _prim = nullptr;
  node *p(nullptr), *pant(nullptr);
  for (int i=0; i<v.size(); i++) {
    p = new node;
    p->info = v[i];
    p->seg = nullptr;
    p->ant = pant;
    if (pant != nullptr)
      pant->seg = p;
    else
      _prim = p;
    pant = p;
  }
  _ult = p;
}

Llista::~Llista() {
  node *p(_prim), *pelim;
  while (p != nullptr) {
    pelim = p;
    p = p->seg;
    delete pelim;
  }
}

nat Llista::longitud() const {
  return _long;
}

void Llista::mostra() const {
  node *p = _prim;
  cout << "[";
  if (p != nullptr) {
    cout << p->info;
    p = p->seg;
  }
  while (p != nullptr) {
    cout << " " << p->info;
    p = p->seg;
  }
  cout << "]";
}

void Llista::mostra_invertida() const {
  node *p = _ult;
  cout << "[";
  if (p != nullptr) {
    cout << p->info;
    p = p->ant;
  }
  while (p != nullptr) {
    cout << " " << p->info;
    p = p->ant;
  }
  cout << "]";
}

int main() {
  string linea;
  while (getline(cin, linea)) {
    vector<int> v;
    istringstream ss(linea);
    int n;
    while (ss >> n) {
      v.push_back(n);
    }
    Llista l(v);
    l.ordena();
    cout << l.longitud() << " ";
    l.mostra();
    cout << " ";
    l.mostra_invertida();
    cout << endl;
  }
  return 0;
}
*/