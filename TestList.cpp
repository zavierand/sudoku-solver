#include "LinkedList.h"
#include <iostream>

int main()
{
    LinkedList<int> testList;

    if (testList.isEmpty())
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
    testList.insertNode(4);

    std::cout << testList.search(4) << " is in the linked list.\n";
    testList.printList();
    
    std::cout << "List size is: " << testList.getSize() << "\n";

    std::cout << "Node at position 2 is: " << testList.getAtPosition(2) << std::endl;
    
    // test delete method
    testList.deleteNode(2);

    testList.printList();

    std::cout << "List size is: " << testList.getSize() << "\n";

    testList.deleteNode(3);
    testList.printList();

    if (testList.isEmpty())
    {
        std::cout << "List is empty." << std::endl;
    }
    else
    {
        std::cout << "List size: " << testList.getSize() << std::endl;
    }


    testList.deleteNode(4);
    testList.printList();

    if (testList.isEmpty())
    {
        std::cout << "List is empty." << std::endl;
    }
    else
    {
        std::cout << "List size: " << testList.getSize() << std::endl;
    }


    testList.deleteNode(1);
    testList.printList();

    if (testList.isEmpty())
    {
        std::cout << "List is empty." << std::endl;
    }
    else
    {
        std::cout << "List size: " << testList.getSize() << std::endl;
    }

    return 0;
}