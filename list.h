#ifndef __LISTA_DOBLEMENTE_ENLAZADA__
#define __LISTA_DOBLEMENTE_ENLAZADA__
#include "node.h"
#include <vector>
#include <string>
#include <sstream>
template<class T>
class List final : private Node<T>{
private:
    Node<T>* head;
    Node<T>* heap;
    Node<T>* goTo(int pos);
public:
    List (T key);
    List (std::vector<T> v);
    virtual ~List();
    void make_null();
    int size();
    bool insert(T key,int pos);
    bool erase(int pos);
    T& operator[](int pos);
    List<T>& operator<<(T key);
    std::string& operator>>(std::string& str);
    List<T> operator>>(List<T>& lis);
    std::string to_string();
    std::vector<T> to_vector();
};

#include "list.tcc"
#endif