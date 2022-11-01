/*
Mason Pennell, Timothy Pieschala
2370867 2391088
pennell@chapman.edu, pieschala@chapman.edu
CPSC 350-01
Programming Assignment 4: The Waiting Game

This type of queue has a FIFO data structure and uses the linked list methods
*/
#ifndef ListQueue_H
#define ListQueue_H
#include <iostream>
#include "DblList.h"

template<typename T>
class ListQueue{
    public:
        ListQueue();
        virtual ~ListQueue();
        void add(T data); //add to the back
        T remove(); //remove from the front
        T peek();
        bool isEmpty();
        int size();
    private:
        DblList<T>* m_list;
};

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

#endif
