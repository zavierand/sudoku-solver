/********************************************************************************
*                                                                               *
*   This is the header file for the queue data structure that will be used to   *
*   primarily assist the graph during breadth-first search. The primary         *
*   methods that will be defined here are the enqueue(), dequeue(), isEmpty(),  * 
*   and the getSize() methods. The primary implemetation of this data strucutre *
*   will be in the form of a linked list that will have methods that perform    *
*   operations on the queue.                                                    *
*                                                                               *
********************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "LinkedList.h"

/****************************************************************************************
*   we include the header file for the linked list data structure to use on our queue.  *
*   since we also include our linked list header file in this, we can use the struct    *
*   node that we defined in the header file for the                                     *
****************************************************************************************/

class Queue 
{
    private:
        node<int>* queue;
        int length;

    public:
        // constructor and destructor
        Queue();
        ~Queue();

        // getters
        int getLength();

        // enqueue and dequeue
        void enqueue(int);
        void dequeue();

        // additional member methods for the queue class
        int peek();
        bool isEmpty();
        void printQueue();

};

#endif

// end of queue class definition