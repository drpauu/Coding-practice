#include <iostream>
#include <cstddef>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

template <typename T>
class Abin {
  private:
    struct node {
      node* f_esq;
      node* f_dret;
      T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);
    
    static node* insereix_bst(node *n, const T &k);
    
    static node* consulta_bst(node *n, const T &k);

    static void print(node *n, string pre);


  public:
    //constructors
    Abin(): _arrel(NULL) {};
    /* Pre: cert */
    /* Post: el resultat és un arbre sense cap element */
    Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
    /* Pre: cert */
    /* Post: el resultat és un arbre amb un element i dos subarbres */

    // Les tres grans
    Abin(const Abin<T> &a);
    ~Abin();
    Abin<T>& operator=(const Abin<T>& a);

    // Iterador sobre arbres binaris.
    friend class iterador;
    class iterador {
      private:
        Abin<T>::node* _p;

      public:
        friend class Abin;
        iterador(): _p(NULL) {};
        /* Pre: cert */
        /* Post: Construeix un iterador no vàlid. */

        Abin<T> arbre() const;
        /* Pre: cert */
        /* Post: Retorna el subarbre al que apunta l'iterador; llança un error
        si l'iterador no és vàlid. */

        T operator*() const;
        /* Pre: cert */
        /* Post: Retorna l'element en el node al que apunta l'iterador, o
        llança un error si l'iterador no és vàlid. */

        iterador fesq() const;
        /* Pre: cert */
        /* Post: Retorna un iterador al fill esquerre; llança
        un error si l'iterador no és vàlid. */

        iterador fdret() const;
        /* Pre: cert */
        /* Post: Retorna un iterador al fill dret; llança
        un error si l'iterador no és vàlid. */

        /* Operadors de comparació. */
        bool operator==(const iterador &it) const {
          return _p == it._p;
        };
        bool operator!=(const iterador &it) const {
          return _p != it._p;
        };
        static const int IteradorInvalid = 410;
    };

    //consultors
    bool es_buit() const;
    /* Pre: cert */
    /* Post: el resultat indica si el p.i. és buit o no */

    iterador arrel() const;
    /* Pre: cert */
    /* Post: Retorna un iterador al node arrel. */
    
    iterador final() const;
    /* Pre: cert */
    /* Post: Retorna un iterador no vàlid. */

    void insereix_bst(const T&k);
    //Pre: cert
    //Post: L'element k s'ha d'inserir en p.i tenint en compte que és un BST

    void print() const;
    //Pre: cert
    //Post: imprimeix l'arbre binari de cerca

    bool consulta_bst(const T&k) const;
    //Pre: cert
    //Post: Retrona true si l'elelemnt k esta en p.i tenint en compte que és un BST


};

/***********inserir*************/

//metode privat
template <typename T>
typename Abin<T>::node* Abin<T>::insereix_bst(node *n, const T &k)
//metode recursiu-insereix la k en l'arbre donat amb el node n
{
  if(n==nullptr){   //k no esta a l'arbre-crear nou node 
    n=new node;
    n->info=k;
    n->f_dret=n->f_esq=nullptr;
    return n;
  }
  else{
    if(n->info < k){  //n valor mes petit a k-  anar a la dreta
      n->f_dret= insereix_bst(n->f_dret,k);
    }   
    else if(n->info > k){   //n valor mes gran a k - anar a l'esquerra
        n->f_esq=insereix_bst(n->f_esq,k);
    }
    else{           //valor k==n->info-esta ja en l'arbre
        n->info=k;
    }
    return n;
  }
}

template <typename T>
void Abin<T>::insereix_bst(const T&k)
//Pre: cert
  //Post: L'element k s'ha d'inserir en p.i tenint en compte que és un BST
{
  node *a=_arrel;
  _arrel=insereix_bst(a,k);
}

/**********imprimir*****************/

//metode privat
template <typename T>
void Abin<T>::print(node *n, string pre)
{
  if(n!=nullptr){
    print(n->f_dret, pre+"          ");
    cout<<pre<<setw(10)<<n->info<<endl;
    print(n->f_esq,pre+"          ");
  }
}

template <typename T>
void Abin<T>::print() const
{
  print(_arrel,"");
}

/*************consultar*******************/
//metode privat
template <typename T>
typename Abin<T>::node* Abin<T>::consulta_bst(node *n, const T &k)
{
  if(n==nullptr or n->info==k){
    return n;
  }
  else{
    if(n->info < k){
      return consulta_bst(n->f_dret,k);
    }
    else if(n->info > k){
      return consulta_bst(n->f_esq,k);
    }
  }
}

template <typename T>
bool Abin<T>::consulta_bst(const T&k) const
    //Pre: cert
    //Post: Retrona true si l'elelemnt k esta en p.i tenint en compte que és un BST
{
  bool trobat=true;
  if(_arrel!=nullptr){
    node *a=consulta_bst(_arrel,k);
    if(a==nullptr) trobat=false;
    else if(a->info=k) trobat=true;
    }
  return trobat;
}

template <typename T>
typename Abin<T>::node* Abin<T>::copia_nodes(node* m) {
/* Pre: cert */
/* Post: si m és NULL, el resultat és NULL; sinó,
   el resultat apunta al primer node d'un arbre binari
   de nodes que són còpia de l'arbre apuntat per m */
  node* n;
  if (m == NULL) n = NULL;
  else {
    n = new node;
    try {
      n->info = m->info;
      n->f_esq = copia_nodes(m->f_esq);
      n->f_dret = copia_nodes(m->f_dret);
    } catch(...) {
      delete n;
      throw;
    }
  }
  return n;
};

template <typename T>
void Abin<T>::esborra_nodes(node* m) {
/* Pre: cert */
/* Post: no fa res si m és NULL, sinó allibera
   espai dels nodes de l'arbre binari apuntat per m */
  if (m != NULL) {
    esborra_nodes(m->f_esq);
    esborra_nodes(m->f_dret);
    delete m;
  }
};

template <typename T>
Abin<T>::Abin(Abin<T>& ae, const T& x, Abin<T>& ad) {
/* Pre: cert */
/* Post: el resultat és un arbre amb x com arrel, ae com a fill
esquerre i ad com a fill dret. No fa còpia dels arbres ae i ad */
  _arrel = new node;
  try {
    _arrel->info = x;
  }
  catch (...) {
    delete _arrel;
    throw;
  }
  _arrel->f_esq = ae._arrel;
  ae._arrel = NULL;
  _arrel->f_dret = ad._arrel;
  ad._arrel = NULL;
}

template <typename T>
Abin<T>::Abin(const Abin<T> &a) {
  _arrel = copia_nodes(a._arrel);
};

template <typename T>
Abin<T>::~Abin() {
  esborra_nodes(_arrel);
};

template <typename T>
Abin<T>& Abin<T>::operator=(const Abin<T>& a) {
  if (this != &a) {
    node* aux;
    aux = copia_nodes(a._arrel);
    esborra_nodes(_arrel);
    _arrel = aux;
  }
  return (*this);
};

template <typename T>
bool Abin<T>::es_buit() const {
/* Pre: cert */
/* Post: el resultat indica si el p.i. és buit o no */
  return (_arrel == NULL);
};

template <typename T>
typename Abin<T>::iterador Abin<T>::arrel() const {
/* Pre: cert */
/* Post: Retorna un iterador al node arrel. */
  iterador it;
  it._p = _arrel;
  return it;
};

template <typename T>
typename Abin<T>::iterador Abin<T>::final() const{
/* Pre: cert */
/* Post: Retorna un iterador no vàlid. */
  return iterador();
};

template <typename T>
Abin<T> Abin<T>::iterador::arbre() const {
/* Pre: cert */
/* Post: Retorna el subarbre al que apunta l'iterador; llança un error
si l'iterador no és vàlid. */
  if (_p == NULL)
    throw IteradorInvalid;
  Abin<T> a;
  a._arrel = copia_nodes(_p);;
  return a;
};

template <typename T>
T Abin<T>::iterador::operator*() const {
/* Pre: cert */
/* Post: Retorna l'element en el node al que apunta l'iterador, o
llança un error si l'iterador no és vàlid. */
  if (_p == NULL)
    throw IteradorInvalid;
  return _p->info;
};

template <typename T>
typename Abin<T>::iterador Abin<T>::iterador::fesq() const {
/* Pre: cert */
/* Post: Retorna un iterador al fill esquerre; llança
un error si l'iterador no és vàlid. */
  if (_p == NULL) 
    throw IteradorInvalid;
  iterador it;
  it._p = _p->f_esq;
  return it;
};

template <typename T>
typename Abin<T>::iterador Abin<T>::iterador::fdret() const {
/* Pre: cert */
/* Post: Retorna un iterador al fill dret; llança
un error si l'iterador no és vàlid. */
  if (_p == NULL) 
    throw IteradorInvalid;
  iterador it;
  it._p = _p->f_dret;
  return it;
};

int main(){
  Abin<int> a;
  string s;
  int k;
  int num;
  cin>>num;     //num nodes
  int cont=1;
  while(cont<num){
    cin>>k;
    if(k!=-1){            //estructura donada - es pot ignorar
      a.insereix_bst(k);
      ++cont;
    } 
  }
  //a.print();
  //llegir els k a buscar a l'arbre
  int i;
  while(getline(cin,s)){
    istringstream ss(s);
    while(ss>>i and i!=-1){ 
      if(a.consulta_bst(i)) cout<<i<<" "<<1<<endl;
      else cout<<i<<" "<<0<<endl;
      }
  }
}


/*



*/