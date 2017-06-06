
template <class T>
Node<T>::Node(){}

template <class T>
Node<T>::Node(T key){
    this->next=nullptr;
    this->back=nullptr;
    this->key=key;
}
template <class T>
Node<T>::~Node(){}
template <class T>
Node<T>* Node<T>::getNode(T key){
    return new Node<T>(key);
}
template <class T>
Node<T>* Node<T>::getNode(){
    return new Node<T>();
}
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

template <class T>
void Node<T>::setKey(T key){
    this->key=key;
}
template <class T>
T& Node<T>::getKey(){
    return this->key;
}