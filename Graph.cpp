/****************************************************************************
*   This is the graph implementation file. In this file, you will find the 
*   implementation of the graphs member methods along with comments that 
*   indicate and describe what the code is doing.
****************************************************************************/

#include "Graph.h"
#include <iostream>

// constructor and destructor
Graph::Graph(int vertices)
{
    std::vector<LinkedList<int> > adjList(vertices);
    numVertices = vertices;
}

// getters
int Graph::getVertices()
{
    return numVertices;
}

// searching algorithms

// graph traversal - done in BFS
/*****************************************************************************************
*                       Here is a basic rundown of BFS on a graph:
*   1. set up a queue to hold the vertices to be visited
*   2. set up a boolean vector to mark vertices visited
*   3. push the adjacent vertices of source onto the queue
*   4. while the queue isn't empty, mark the node at the front as visited
*       4b. push adjacent nodes of vertex at the front onto the queue
*   5. if a vertex on the queue has already been visited, we pop and check the next
*   6. repeat until the queue is empty
*****************************************************************************************/

    // start of BFS definition
void Graph::BFS(int source)
{
    std::queue<int> bfsQueue;
    std::vector<bool> visited(numVertices, false);
    int current = source;

    visited[source - 1] = true;
    bfsQueue.push(source);

    while (!bfsQueue.empty())
    {
        std::cout << current << " ";

        // Process all adjacent nodes of the current node
        for (int i = 0; i < adjList[current - 1]->getSize() - 1; i++)
        {
            int adjacent = adjList[current - 1]->getAfterFirst(i);
            if (!visited[adjacent - 1])
            {
                bfsQueue.push(adjacent);
                visited[adjacent - 1] = true;
            }
        }

        bfsQueue.pop();
        if (!bfsQueue.empty())
            current = bfsQueue.front();
    }
}


/*********************************************************************************************
*   DFS runs opposite of BFS, however, the simple trick is to use a stack instead of a queue
*                       Here is a basic rundown of DFS on a graph:
*   1. set up a stack to hold the vertices to be visited
*   2. set up a boolean vector to mark vertices visited
*   3. push the adjacent vertices of source onto the stack
*   4. while the stack isn't empty, mark the node at the top as visited
*       4b. push adjacent nodes of vertex at the front onto the stack
*   5. if a vertex on the stack has already been visited, we pop and check the next
*   6. repeat until the stack is empty
*********************************************************************************************/
void Graph::DFS(int source)
{
    std::stack<int> dfsStack;
    std::vector<bool> visited(numVertices, false);

    visited[source - 1] = true;
    dfsStack.push(source);

    while (!dfsStack.empty())
    {
        int current = dfsStack.top();
        dfsStack.pop();

        std::cout << current << " "; // Output the current node

        // Process neighbors of the current node
        for (int i = 0; i < adjList[current - 1]->getSize(); i++)
        {
            int neighbor = adjList[current - 1]->getAtPosition(i);
            if (!visited[neighbor - 1])
            {
                visited[neighbor - 1] = true;
                dfsStack.push(neighbor);
            }
        }
    }
}

// add graph components
void Graph::addVertex(int v)
{   
    /*********************************************************************************
    *
    *   Since we have an array of type Linked Lists(which are dynamically allocated),
    *   we must create a pointer to each linked list so that way we can access each
    *   element in the linked list when modifying the list.
    *
    *********************************************************************************/
    LinkedList<int>* vertex = new LinkedList<int>;
    vertex->insertNode(v);
    adjList.push_back(vertex);
}

void Graph::addEdge(int s, int d) {
    if (s >= 0 && s <= adjList.size()) 
    {
        adjList[s - 1]->insertNode(d);
    } 
    else 
    {
        std::cout << "Invalid edge vertices!" << std::endl;
    }
}

// additional member methods
bool Graph::isEmpty()
{
    return numVertices == 0;
}

void Graph::printAdjList()
{
    std::cout << "Graph Adjacency List:\n";
    std::cout << "Vertex:\tAdjacent Vertices:\n";
    std::cout << "******************************\n";

    for (int i = 0; i < numVertices; i++)
    {
        std::cout << adjList[i]->search(i + 1) << "   --->   ";
        // helper function specific for this class
        adjList[i]->printAfterFirstNode();
    }
    std::cout << "******************************\n";
}

void Graph::printBFS()
{

}
