#ifndef __LISTA_DOBLEMENTE_ENLAZADA__
#define __LISTA_DOBLEMENTE_ENLAZADA__
#include "node.h"
#include <vector>
template<class T>
class List {
private:
    Node<T>* head;
    Node<T>* heap;
protected:
public:
    List (T key);
    List (std::vector<T>& v);
    virtual ~List();
    void MakeListNull();
};

template <class T>
List<T>::List (T key){
    head=new Node<T>(key);
    head->setBack(nullptr);
    heap=head;
    heap->setNext(nullptr);
}
template <class T>
List<T>::List (std::vector<T>& v){
    if(v.size()>0){
        head=new Node<T>(v[0]);
        head->setBack(nullptr);
        Node<T>* nx=head;
        for (int cont=1;cont<v.size();cont++){
            nx->setNext(new Node<T>(v[cont]));
            nx->getNext()->setBack(nx);
            nx=nx->getNext();
        }
        heap=nx;
        heap->setNext(nullptr);
    }
}

template <class T>
List<T>::~List(){
    this->MakeListNull();
}

template <class T>
void List<T>::MakeListNull(){
    
}
#endif