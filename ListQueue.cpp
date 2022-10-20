#include "ListQueue.h"

template<typename T>
ListQueue<T>::ListQueue(){
    m_list = new DblList<T>();
}

template<typename T>
ListQueue<T>::~ListQueue(){
    delete m_list;
}

template<typename T>
bool ListQueue<T>::isEmpty(){
    return (m_list->size() == 0);
}

template<typename T>
int ListQueue<T>::size(){
    return m_list->size();
}

template<typename T>
void ListQueue<T>::add(T data){
    m_list->addBack(data);
}

template<typename T>
T ListQueue<T>::remove(){
    return m_list->removeFront();
}

template<typename T>
T ListQueue<T>::peek(){
    return m_list-> get(0);
}
