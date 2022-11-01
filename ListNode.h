/*
Mason Pennell, Timothy Pieschala
2370867 2391088
pennell@chapman.edu, pieschala@chapman.edu
CPSC 350-01
Programming Assignment 4: The Waiting Game

Nodes have a type of data, as well as pointer to two instances of itself, next and prev
*/
#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <cstdlib>

template<typename T>
class ListNode{
    public:
    ListNode(T data);
    virtual ~ListNode();
    T m_data;
    ListNode<T>* m_next; //recursive data structure b/c it points to instances of itself
    ListNode<T>* m_prev;
};

template<typename T>
ListNode<T>::ListNode(T data){
    m_data = data;
    m_next = NULL;
    m_prev = NULL;
}

template<typename T>
ListNode<T>::~ListNode(){
    m_next = NULL;
    m_prev = NULL;
}

#endif


