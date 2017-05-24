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
    head->back=nullptr;
    heap=head;
    heap->next=nullptr;
}
template <class T>
List<T>::List (std::vector<T>& v){
    if(v.size()>0){
        head=new Node<T>(v[0]);
        head->back=nullptr;
        Node<T>* nx=head;
        for (int cont=1;cont<v.size()-1;cont++){
            nx->next=new Node<T>(v[cont]);
            nx->next->back=nx;
            nx=nx->next;
        }
        heap=new Node<T>(v[v.size()-1]);
        heap->next=nullptr;
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