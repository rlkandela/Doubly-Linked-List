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
    void setBack(Node<T>* ptr);
    Node<T>* getBack();
    void setNext(Node<T>* ptr);
    Node<T>* getNext();
};

template <class T>
Node<T>::Node(T key){
    this->next=nullptr;
    this->back=nullptr;
    this->key=key;
}
template <class T>
Node<T>::~Node(){}
template <class T>
void Node<T>::setBack(Node<T>* ptr){
    this->back=ptr;
}
template <class T>
Node<T>* Node<T>::getBack(){return back;}
template <class T>
void Node<T>::setNext(Node<T>* ptr){
    this->next=ptr;
}
template <class T>
Node<T>* Node<T>::getNext(){return next;}
#endif