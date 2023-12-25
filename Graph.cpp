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
    std::vector<LinkedList<int>> adjList(vertices);
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
    std::queue<int> = bfsQueue;
    bool visited[numVertices];

    // mark each vertex as not visited
    for (int i = 0; i < visited.size(); i++)
    {
        visited[i] = false;
    }

    // push vertices adjacent to source onto the queue from adjList
    for (int i = 0; i < adjList[i].getSize(); i++)
    {
        bfsQueue.push(adjList[i].search(i));
    }

    // while the queue is not empty, search
    while (!bfsQueue.empty())
    {
        
    }
}

// search for path from a vertex
void Graph::Hamiltonian()
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
}
