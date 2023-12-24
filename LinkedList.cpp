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
template <class T>
int LinkedList<T>::getSize()
{
    return size;
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
}

template class LinkedList<int>;