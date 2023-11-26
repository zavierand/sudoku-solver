/************************************************************************
*
*   This is the implentation file for the linked list data structure.
*   All members of the linked list class will be defined/implemented
*   here with comments explaining the thought process behind the
*   implementation of algorithm
*
************************************************************************/

#include "LINKEDLIST.h"

// constructor and destructor
template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    length = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    node<T>* temp = new node<T>;
    temp = head;

    // traverse and delete each node from the list
    while( temp != NULL )
    {
        temp = temp->next;
        delete temp;
    }

    // once all the nodes are deleted, we delete the head pointer
    delete head;
    length = 0;
}

// getters
template<class T>
int LinkedList<T>::getSize()
{
    return length;
}

// insert and delete methods
template<class T>
void LinkedList<T>::insertNode(T data)
{
    // we allocate (create) a node
    node<T>* temp = new node<T>;
    temp->data = data;
    temp->next = NULL;
    
    // first case is if list is empty
    if( head == NULL )
    {
        head = temp;
    }
    else
    {
        /*******************************************************************************
        *   second case is if head != NULL (since the list does not have to be sorted,
        *   we traverse to the end of the list, and add the node to the end
        *******************************************************************************/
        node<T>* p = new node<T>;
        p = head;
    
        while( p->next != NULL )
        {
            p = p->next;
        }
        p->next = temp;
    }
    length++;
}

template<class T>
void LinkedList<T>::deleteNode(int data)
{
    /**************************************************************************
    *   we allocate two nodes to the heap, one to delete the given node, and
    *   one to modify the linkages of the pointers
    **************************************************************************/ 
    node<T>* temp = new node<T>;
    temp = head;
    node<T>* p = new node<T>;
    p = head;

    // if list is empty
    if( head == NULL )
    {
        std::cout << "List is empty." << std::endl;
        
    }
    // next we take care of the case where there is only one node
    else if( length == 1 )
    {
        delete temp;
        head = NULL;
    }
    // now we delete if the list has more than one node
    else
    {
        // traverse to the node to be deleted
        
        p->next = temp->next;
        delete temp;
    }
    length--;
}

// additional member methods for list
template<class T>
void LinkedList<T>::traverseToNextNode()
{
    node<T>* temp = new node<T>;
    temp = head;
    for(int i = 0; i < 1; i++)
    {
        temp = temp->next;
    }
}

template<class T>
void LinkedList<T>::printList()
{
    node<T>* temp = new node<T>;
    temp = head;
    while( temp != NULL )
    {   
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    return length == 0;
}

template class LinkedList<int>;
template class LinkedList<char>;
template class LinkedList<std::string>;