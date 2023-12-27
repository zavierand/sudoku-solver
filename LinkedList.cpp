#include "LinkedList.h"

// constructor and destructor
template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{

}

// getters
// get size of list
template <class T>
int LinkedList<T>::getSize()
{
    return size;
}

// retrieve value at certain node
template <class T>
int LinkedList<T>::getAtPosition(int position)
{
    node<T>* temp = new node<T>;
    temp = head;

    if (isEmpty())
    {
        std::cout << "List is empty.\n";
        return 0;
    }
    else
    {
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}

template <class T>
int LinkedList<T>::getAtPositionAfterFirst(int position)
{
    node<T>* temp = new node<T>;
    temp = head;

    if (head == NULL)
    {
        std::cout << "List is empty.\n";
        return 0;
    }
    else
    {
        // start from next node;
        temp = temp->next;

        // traverse to position
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}

// linear search on an unsorted Linked List
template <class T>
int LinkedList<T>::search(int x)
{
    node<T>* temp = new node<T>;
    temp = head;
    
    if (!isEmpty())
    {
        while (temp->data != x)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    else
    {
        std::cout << "List is empty.\n";
        return -1;
    }
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
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        
        node<T>* p = new node<T>;
        p = head;
     
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    size++;
}

template <class T>
void LinkedList<T>::deleteNode(int x)
{
    node<T>* nodeToLink = new node<T>;
    node<T>* nodeToFree = new node<T>;

    // assign both nodes to head 
    nodeToLink = head;
    nodeToFree = head;
    int counter = 0;

    if (head == NULL)
    {
        std::cout << "List does not contain anything.\n";
    }
    else
    {

        // traverse to the node containing the data we want to delete
        while (nodeToFree->data != x)
        {
            nodeToFree = nodeToFree->next;
            counter++;
        }

        // traverse to the node before the node to be deleted

        /**********************************************************  
        *   We want to traverse to this node so that way we can
        *   link the two nodes, the node before the deleted node
        *   and the node after together, so we don't lose data
        *   and have memory roaming on the heap (fragmentation)
        **********************************************************/
    
        for (int i = 0; i < counter - 1; i++)
        {
            nodeToLink = nodeToLink->next;
        }
        nodeToLink->next = nodeToFree->next; 
        delete nodeToFree;
    }
    size--;
}

// additional member methods for list
template <class T>
void LinkedList<T>::printList()
{
    node<T>* temp;
    temp = head;

    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        if (temp->next != NULL)
        {
            std::cout << " --> ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::printAfterFirstNode()
{
    node<T>* temp = new node<T>;
    temp = head;
    // traverse to one node after head node
    for (int i = 0; i < 1; i++)
    {
        temp = temp->next;
    }

    // print remaining information
    while (temp != NULL)
    {
        std::cout << temp->data;
        if (temp->next != NULL)
        {
            std::cout << " --> ";
        }
        temp = temp->next;
    }
    std::cout << "\n";
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return size == 0;
}

template <class T>
void LinkedList<T>::traverseList()
{
    node<T>* temp = new node<T>;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
}

template class LinkedList<int>;