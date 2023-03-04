 #include <cstddef>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class deque {
   public:
     deque();
     // Pre: True
     // Post: El p.i. és una deque buida.
 
     deque(const deque &dq);
     // Pre: True
     // Post: El p.i. conté una còpia de dq.
 
     ~deque();
     // Post: Destrueix els elements del p.i.
 
     nat size() const;
     // Pre: True
     // Post: Retorna el nombre d’elements de la deque.
 
     bool empty() const;
     // Pre: True
     // Post: Retorna true si la deque és buida; false en cas contrari.
 
     T front() const;
     // Pre: La deque no és buida.
     // Post: Retorna el _primer element de la deque.
 
     T rear() const;
     // Pre: La deque no és buida.
     // Post: Retorna l’últim element de la deque.
 
     void push(T e);
     // Pre: True
     // Post: Insereix un element al davant de la deque.
 
     void inject(T e);
     // Pre: True
     // Post: Insereix un element al darrera de la deque.
 
     void pop();
     // Pre: La deque no és buida.
     // Post: Elimina el _primer element de la deque.
 
     void eject();
     // Pre: La deque no és buida.
     // Post: Elimina l’últim element de la deque.
 
   private:
   /* Double-ended queue implementada amb una llista doblement encadenada,
      sense fantasma i no circular. */
     struct node {
       T info;    // Informació del node
       node *seg; // Punter al següent element
       node *ant; // Punter a l’anterior element
     };
     node *_prim; // Punter al _primer element
     node *_ult;  // Punter a l’últim element
     nat _long;   // Nombre d’elements
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació dels mètodes públics i privats addicionals
template <typename T>
void deque<T>::push(T e)
// Pre: True
// Post: Insereix un element al davant de la deque.
{
  if(_prim != nullptr){
    node *aux1;
    node *aux2;
    aux1 = new node;
    aux1->info = e;
    aux2 = _prim;
    _prim = aux1;
    aux1->seg = aux2;
    aux2->ant = aux1;
  } else{
    node *aux1;
    aux1 = new node;
    aux1->info = e;
    _prim = aux1;
    _prim->seg = nullptr;
    _prim->ant = nullptr;
  }
  if(_long == 0){
    _ult = _prim;
  }
  _long++;
}

template <typename T>
void deque<T>::inject(T e)
// Pre: True
// Post: Insereix un element al darrera de la deque.
{
  if(_prim == nullptr){
    node *aux1;
    aux1 = new node;
    aux1->info = e;
    _prim = aux1;
    _prim->seg = nullptr;
    _prim->ant = nullptr;
  } else{
    node *aux1, *aux2;
    aux2 = new node;
    aux2->info = e;
    aux1 = _ult;
    _ult = aux2;
    aux1->seg = aux2;
    aux2->ant = aux1;
  }
  if(_long == 0){
    _ult = _prim;
  }
  _long++;
}

template <typename T>
void deque<T>::pop()
// Pre: La deque no  ́es buida.
// Post: Elimina el _primer element de la deque.

{
  if(_prim == _ult){
    _prim = nullptr;
  } else {
    if(_prim->seg == _ult){
      node *aux;
      aux = _prim;
      _prim = _ult;
      delete aux;
    } else {
      node *aux;
      aux = _prim;
      _prim = _prim->seg;
      delete aux;
    }
  }
  _long--;
}

template <typename T>
void deque<T>::eject()
// Pre: La deque no  ́es buida.
// Post: Elimina l’  ́_ultim element de la deque.
{
  if(_prim == _ult){
    _prim = nullptr;
  } else {
    if(_ult->ant == _prim){
      node *aux;
      aux = _ult;
      _ult = _prim;
      delete aux;
    } else {
      node *aux;
      aux = _ult;
      _ult = _ult->ant;
      delete aux;
    }
  }
  _long--;
}