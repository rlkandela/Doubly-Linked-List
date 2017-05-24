#ifndef __NODOS_LISTA_DOBLE__
#define __NODOS_LISTA_DOBLE__
#include <vector>
template<class T>
class Node{
private:
    Node<T>* back;
    Node<T>* next;
    T key;
public:
    Node (T key);
    virtual ~Node();
};

template <class T>
Node<T>::Node(T key){
    this->back=nullptr;
    this->next=nullptr;
    this->key=key;
}
template <class T>
Node<T>::~Node(){}
#endif