/***************************************************************
*
*   This is the header file for the linked list data structure.
*   The linked list will be used by the graph to store 
*   any adjacent vertices to a vertex
*
***************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<class T>
struct node
{
    T data;
    node<T>* next;
};

template<class T>
class LinkedList
{
    private:
        node<T>* head;
        int length;

    public:
        // constructor and destructor
        LinkedList();
        ~LinkedList();

        // getters
        int getSize();

        // insert and delete methods
        void insertNode(T);
        void deleteNode(int);

        // additional member methods for list
        void printList();
        bool isEmpty();
        void traverseList();

};

#endif

// end of linked list class implementation