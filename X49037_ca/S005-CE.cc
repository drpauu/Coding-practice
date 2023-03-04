#include <cstdlib>
#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Abin
{
public:
  Abin() : _arrel(NULL){};
  // Pre: cert
  // Post: el resultat és un arbre sense cap element
  Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
  // Pre: cert
  // Post: el resultat és un arbre amb un element i dos subarbres

  // Les tres grans
  Abin(const Abin<T> &a);
  ~Abin();
  Abin<T> &operator=(const Abin<T> &a);

  // operador << d’escriptura
  template <class U>
  friend std::ostream &operator<<(std::ostream &, const Abin<U> &a);

  // operador >> de lectura
  template <class U>
  friend std::istream &operator>>(std::istream &, Abin<U> &a);

  bool compleix_suma_fills() const;
  // Pre: true
  // Post: retorna si compleix la propietat ’Suma dels fills’:
  // Per tot node el seu valor és igual a la suma dels valors
  // dels nodes (arrels) del fill esquerre i del fill dret.

private:
  struct node
  {
    node *f_esq;
    node *f_dret;
    T info;
  };
  node *_arrel;
  static node *copia_nodes(node *m);
  static void esborra_nodes(node *m);
  static void print_nodes(node *m, ostream &os, string d1);
  static bool compleix(node *m);
};

template <typename T>
bool Abin<T>::compleix_suma_fills() const
{
  return compleix(_arrel);
}

template <typename T>
bool Abin<T>::compleix(node *m)
{
  bool comp = true;
  if (m != nullptr)
  {
    int varrel = m->info;
    node *fd, *fe;
    fd = m->f_dret;
    fe = m->f_esq;
    int vfe = 0, vfd = 0;
    if (fe != nullptr)
    {
      vfe = fe->info;
    }
    if (fd != nullptr)
    {
      vfd = fd->info;
    }
    if (fe != nullptr or fd != nullptr)
    {
      return (varrel == vfe + vfd) and compleix(fe) and compleix(fd);
    }
  }
  return comp;
}

/*
#include <iostream>
#include <stack>

template <typename T>
typename Abin<T>::node *Abin<T>::copia_nodes(node *m)
{
  /* Pre: cert */
  /* Post: si m és NULL, el resultat és NULL; sinó,
     el resultat apunta al primer node d'un arbre binari
     de nodes que són còpia de l'arbre apuntat per m 
  node *n;
  if (m == NULL)
    n = NULL;
  else
  {
    n = new node;
    try
    {
      n->info = m->info;
      n->f_esq = copia_nodes(m->f_esq);
      n->f_dret = copia_nodes(m->f_dret);
    }
    catch (...)
    {
      delete n;
      throw;
    }
  }
  return n;
};

template <typename T>
void Abin<T>::esborra_nodes(node *m)
{
  /* Pre: cert */
  /* Post: no fa res si m és NULL, sinó allibera
     espai dels nodes de l'arbre binari apuntat per m 
  if (m != NULL)
  {
    esborra_nodes(m->f_esq);
    esborra_nodes(m->f_dret);
    delete m;
  }
};

template <typename T>
Abin<T>::Abin(Abin<T> &ae, const T &x, Abin<T> &ad)
{
  /* Pre: cert */
  /* Post: el resultat és un arbre amb x com arrel, ae com a fill
  esquerre i ad com a fill dret. No fa còpia dels arbres ae i ad 
  _arrel = new node;
  try
  {
    _arrel->info = x;
  }
  catch (...)
  {
    delete _arrel;
    throw;
  }
  _arrel->f_esq = ae._arrel;
  ae._arrel = NULL;
  _arrel->f_dret = ad._arrel;
  ad._arrel = NULL;
}

template <typename T>
Abin<T>::Abin(const Abin<T> &a)
{
  _arrel = copia_nodes(a._arrel);
};

template <typename T>
Abin<T>::~Abin()
{
  esborra_nodes(_arrel);
};

template <typename T>
Abin<T> &Abin<T>::operator=(const Abin<T> &a)
{
  if (this != &a)
  {
    node *aux;
    aux = copia_nodes(a._arrel);
    esborra_nodes(_arrel);
    _arrel = aux;
  }
  return (*this);
};

template <typename T>
void Abin<T>::print_nodes(node *p, ostream &os, string prefix)
{
  if (p == NULL)
    os << ".";
  else
  {
    string prefix2;
    os << "[" << p->info << "]\n"
       << prefix << " \\__";
    prefix2 = prefix + " |  ";
    print_nodes(p->f_dret, os, prefix2);
    os << "\n"
       << prefix << " \\__";
    prefix2 = prefix + "    ";
    print_nodes(p->f_esq, os, prefix2);
  }
}

// operador << d'escriptura
template <class U>
ostream &operator<<(ostream &os, const Abin<U> &a)
{
  a.print_nodes(a._arrel, os, "");
  os << "\n";
  return os;
}

// operador >> de lectura
template <class U>
istream &operator>>(istream &is, Abin<U> &a)
{
  U node;
  int size, nf;
  std::stack<Abin<U>> p;

  is >> size;
  while (size > 0)
  {
    Abin<U> abuit;
    is >> node >> nf;
    if (nf == 0)
    { // fills buits
      p.push(Abin<U>(abuit, node, abuit));
    }
    else if (nf == -1)
    { // nf=-1 --> nomes un fill, l'esquerre
      Abin<U> fe = p.top();
      p.pop();
      p.push(Abin<U>(fe, node, abuit));
    }
    else if (nf == 1)
    { // nf=1 --> nomes un fill, el dret
      Abin<U> fd = p.top();
      p.pop();
      p.push(Abin<U>(abuit, node, fd));
    }
    else
    { // nf=2 --> dos fills no buits
      Abin<U> fd = p.top();
      p.pop();
      Abin<U> fe = p.top();
      p.pop();
      p.push(Abin<U>(fe, node, fd));
    }
    --size;
  }
  if (not p.empty())
    a = p.top();
  return is;
}

int main()
{
  Abin<int> ar;
  cin >> ar;
  cout << ar << endl;

  if (ar.compleix_suma_fills())
    cout << "L'arbre compleix la propietat 'Suma dels fills'." << endl;
  else
    cout << "L'arbre no compleix la propietat 'Suma dels fills'." << endl;
  return 0;
}
*/