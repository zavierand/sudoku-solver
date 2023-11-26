#include <iostream>
#include "QUEUE.h"
#include "LINKEDLIST.h"

int main()
{
    Queue testQueue;

    if( testQueue.isEmpty() )
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        std::cout << "Queue size: " << testQueue.getLength() << std::endl;
    }

    // test enqueue
    testQueue.enqueue(1);
    testQueue.enqueue(2);
    testQueue.enqueue(1);

    testQueue.printQueue();

    if( testQueue.isEmpty() )
    {
        std::cout << "Queue is empty." << std::endl;
    }
    else
    {
        std::cout << "Queue size: " << testQueue.getLength() << std::endl;
    }

    // test dequeue
    testQueue.dequeue();

    testQueue.printQueue();

    if( testQueue.isEmpty() )
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        std::cout << "Queue size: " << testQueue.getLength() << std::endl;
    }

    return 0;
}