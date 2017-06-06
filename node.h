#ifndef __NODOS_LISTA_DOBLE__
#define __NODOS_LISTA_DOBLE__
#include <vector>
#include <sstream>
template<class T>
class Node{
private:
    Node<T>* back;
    Node<T>* next;
    T key;
protected:
    Node ();
    Node (T key);
    Node<T>* getNode(T key);
    Node<T>* getNode();
public:
    virtual ~Node();
    void setBack(Node<T>* ptr);
    Node<T>* getBack();
    void setNext(Node<T>* ptr);
    Node<T>* getNext();
    void setKey(T ket);
    T& getKey();
};

#include "node.tcc"
#endif