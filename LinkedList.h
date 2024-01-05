/***************************************************************
*
*   This is the header file for the linked list data structure.
*   The use of a Linked List in this project is for the use
*
***************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<class T>
struct node
{
    int color;
    T data;
    node<T>* next;
};

template<class T>
class LinkedList
{
    private:
        node<T>* head;
        int size;

    public:
        // constructor and destructor
        LinkedList();
        ~LinkedList();

        // getters
        int getSize();
        int getAtPosition(int);
        int getAfterFirst(int);

        // linear search on an unsorted Linked List
        int search(int);

        // insert and delete methods
        void insertNode(T, int);
        void deleteNode(int);

        // additional member methods for list
        void printList();
        void printAfterFirstNode();
        bool isEmpty();
        void traverseList();

};

#endif

// end of linked list class definition