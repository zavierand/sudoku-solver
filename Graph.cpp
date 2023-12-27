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

Graph::~Graph()
{

}

// getters
int Graph::getVertices()
{
    return numVertices;
}

// searching algorithms

// graph traversal - done in BFS
void Graph::BFS(int source)
{
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
    std::queue<int> bfsQueue;
    std::vector<bool> visited(numVertices, false);
    int current = source;

    visited[source - 1] = true;

    for (int i = 0; i < adjList[source - 1]->getSize() - 1; i++)
    {
        bfsQueue.push(adjList[source - 1]->getAfterFirst(i));
    }

    while (!bfsQueue.empty())
    {
        std::cout << current << " ";
        for (int i = 1; i < adjList[i]->getSize() - 1; i++)
        {
            bfsQueue.push(adjList[bfsQueue.front() - 1]->getAfterFirst(i));
        }
        current = bfsQueue.front();
        visited[bfsQueue.front() - 1] = true;
        bfsQueue.pop();
        if (visited[bfsQueue.front() - 1] == true)
        {
            bfsQueue.pop();
        }
    }
}

// search for path from a vertex
void Graph::Hamiltonian(int source)
{

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
