#include "LINKEDLIST.h"
#include <iostream>

int main()
{
    LinkedList<int> testList;

    if( testList.isEmpty() )
    {
        std::cout << "List is empty." << std::endl;
    }
    else
    {
        std::cout << "List size: " << testList.getSize() << std::endl;
    }

    // test insert method
    testList.insertNode(1);
    testList.printList();

    testList.insertNode(2);
    testList.insertNode(3);
    testList.insertNode(1);

    testList.printList();
    
    // test delete method
    testList.deleteNode(2);

    return 0;
}