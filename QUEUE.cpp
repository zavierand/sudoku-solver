#include "QUEUE.h"

// constructor and destructor
Queue::Queue()
{
    queue = NULL;
    length = 0;
}

Queue::~Queue()
{
    // since the implementation of the queue is a linked list, we can use the same 
    node<int>* temp = new node<int>;
    temp = queue;

    // traverse and delete each node from the list
    while( temp != NULL )
    {
        temp = temp->next;
        delete temp;
    }

    // once all the nodes are deleted, we delete the head pointer
    delete queue;
    length = 0;
}

// getters
int Queue::getLength()
{
    return length;
}

// enqueue and dequeue
void Queue::enqueue(int data)
{
    /***************** function similar to insert ***********************
    *   we check if the queue is empty. if it is, then the first        *
    *   element in the list is stored with the argument passed through  *
    *   the function. Otherwise, we traverse the list until we get to   *
    *   the next element to be pushed into the queue.                   *
    ********************************************************************/

    // we allocate (create) a node
    node<int * temp = new node<int>;
    temp->data = data;
    temp->next = NULL;
    
    // first case is if list is empty
    if( queue == NULL )
    {
        queue = temp;
    }
    else
    {
        /*******************************************************************************
        *   second case is if head != NULL (since the list does not have to be sorted,
        *   we traverse to the end of the list, and add the node to the end
        *******************************************************************************/
        node<int>* p = new node<int>;
        p = queue;
    
        while( p->next != NULL )
        {
            p = p->next;
        }
        p->next = temp;
    }
    length++;
}

void Queue::dequeue()
{
    /********************************************************************
    *   since this is a fifo data structure, we to need remove the      *
    *   first element of the queue and shift the head pointer to the    *
    *   next element of the queue.                                      *
    ********************************************************************/

    node<int>* temp = new node<int>;
    temp = queue;

    /************************************************************************
    *   check to see if the queue is empty first; cannot perform operation  *
    *   since we cannot perform a dequeue on an empty stack.                *
    ************************************************************************/

    if( isEmpty() )
    {
        std::cout << "Queue is empty." << std::endl;
    }
    else
    {
        for(int i = 0; i < 1; i++)
        {
            // shift address pointer is pointing to by one address
            queue = queue->next;
        }
        delete temp;
    }
    length--;

}

// additional member methods for the queue class
int Queue::peek()
{
    /************************************************************************
    *   we traverse to the tail of the queue and return the value at tail   *
    ************************************************************************/
    node<int>* temp = new node<int>;
    temp = queue;
    while( temp != NULL )
    {
        temp = temp->next;
    }
    return temp->data;
}

bool Queue::isEmpty()
{
    return length == 0;    
}

void Queue::printQueue()
{
    node<int>* temp = new node<int>;
    temp = queue;
    while( temp != NULL )
    {
        std::cout << temp->data << " ";
    }
    std::cout << std::endl;
}