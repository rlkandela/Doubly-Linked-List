#ifndef __LISTA_DOBLEMENTE_ENLAZADA__
#define __LISTA_DOBLEMENTE_ENLAZADA__
#include "node.h"
#include <vector>
#include <sstream>
template<class T>
class List final : private Node<T>{
private:
    Node<T>* head;
    Node<T>* heap;
    Node<T>* goTo(int pos);
public:
    List (T key);
    List (std::vector<T>& v);
    virtual ~List();
    void make_null();
    int size();
    bool insert(T key,int pos);
    bool erase(int pos);
    T& operator[](int pos);
    friend std::ostream& operator << (std::ostream& os,const List<T> l);
    std::string to_string();
};

template <class T>
List<T>::List (T key){
    head=Node<T>::getNode(key);
    head->setBack(nullptr);
    heap=head;
    heap->setNext(nullptr);
}
template <class T>
List<T>::List (std::vector<T>& v){
    if(v.size()>0){
        head=Node<T>::getNode(v[0]);
        head->setBack(nullptr);
        Node<T>* nx=head;
        for (int cont=1;cont<v.size();cont++){
            nx->setNext(Node<T>::getNode(v[cont]));
            nx->getNext()->setBack(nx);
            nx=nx->getNext();
        }
        heap=nx;
        heap->setNext(nullptr);
    }
}

template <class T>
List<T>::~List(){
    this->make_null();
}

template <class T>
void List<T>::make_null(){
    
}

template <class T>
int List<T>::size(){
    int ret=0;
    if(head!=nullptr){
        Node<T>* aux=head;
        do{
            ret++;
            aux=aux->getNext();
        }while(aux!=nullptr);
    }
    return ret;
}

template <class T>
bool List<T>::insert(T key,int pos){
    int ret=false;
    if(pos<=this->size()+1){
        if(pos==1){
            Node<T>* nodoAux=Node<T>::getNode(key);
            if(nodoAux!=nullptr){
                nodoAux->setNext(head);
                head=nodoAux;
                ret=true;
            }else{
                ret=false;
            }
        }else if(pos==this->size()+1){
            Node<T>* nodoAux=Node<T>::getNode(key);
            if(nodoAux!=nullptr){
                Node<T>* nodo=heap;
                heap->setNext(nodoAux);
                nodoAux->setBack(nodo);
                nodoAux->setNext(nullptr);
                heap=nodoAux;
                ret=true;
            }else{
                ret=false;
            }
        }
        else{
            Node<T>* nodo=this->goTo(pos-1);
            if(nodo!=nullptr){
                Node<T>* nodoAux=Node<T>::getNode(key);
                if(nodoAux!=nullptr){
                    nodoAux->setNext(nodo->getNext);
                    nodoAux->setBack(nodo);
                    nodo->setNext(nodoAux);
                    ret=true;
                }else{
                    ret=false;
                }
            }
        }
    }else{
        ret=this->insert(key,this->size()+1);
    }
    return ret;
}

template <class T>
Node<T>* List<T>::goTo(int pos){
    Node<T>* nodoAux=head;
    for(int cont=1;cont<pos and nodoAux!=nullptr;cont++){
        nodoAux=nodoAux->getNext();
    }
    return nodoAux;
}

template <class T>
bool List<T>::erase(int pos){
    int ret=false;
    if(pos==1){
        Node<T>* nodoAux=head;
        if(nodoAux!=nullptr){
            head=head->getNext();
            delete nodoAux;
            if(head!=nullptr){
                head->setBack(nullptr);
            }else{
                heap=nullptr;
            }
            ret=true;
        }else{
            ret=false;
        }
    }else if(pos==this->size()){
        Node<T>* nodoAux=heap;
        if(nodoAux!=nullptr){
            heap=heap->getBack();
            delete nodoAux;
            if(heap!=nullptr){
                heap->setNext(nullptr);
            }else{
                head=nullptr;
            }
            ret=true;
        }else{
            ret=false;
        }
    }else if(pos>1 and pos<this->size()){
        Node<T>* nodoAux=this->goTo(pos);
        nodoAux->getBack()->setNext(nodoAux->getNext());
        nodoAux->getNext()->setBack(nodoAux->getBack());
        delete nodoAux;
        ret=true;
    }else ret=false;
    return ret;
}

template <class T>
T& List<T>::operator[](int pos){
    Node<T>* nodo;
    nodo=this->goTo(++pos);
    return nodo->getKey();
}

template <class T>
std::ostream& operator << (std::ostream& os,const List<T> l){
    for(int cont=0;cont<l.size();cont++){
        os<<"["<<cont<<"] : "<<l[cont]<<"\n";
    }
    return os;
}

template <class T>
std::string List<T>::to_string(){
    std::stringstream sstr;
    for(int cont=0;cont<this->size();cont++){
        sstr<<"["<<cont<<"] : "<<((*this)[cont])<<"\n";
    }
    return sstr.str();
}
#endif