/****************************************************************************
*   This is the graph implementation file. In this file, you will find the 
*   implementation of the graphs member methods along with comments that 
*   indicate and describe what the code is doing.
****************************************************************************/

#include "GRAPH.h"
#include <iostream>

// constructor and destructor
Graph::Graph()
{
    std:;vector<LinkedList<int>> adjList;
    numVertices = 0;
}

Graph::~Graph()
{

}

// search graph
void Graph::DFS(LinkedList<int> graph[], int source)
{
    
}

// search for a path
void Graph::Hamiltonian()
{

}

// add graph components
void Graph::addVertex(int vertex)
{   
    g
}

void Graph::addEdge(int vertex, int newEdge)
{

}

// additional member methods
bool Graph::isEmpty()
{
    return numVertices == 0;
}

void Graph::printAdjList()
{
    for(int i = 0; i < numVertices; i++)
    {
        adjList[i].printList();
        std::cout << "\n";
    }
    std::cout << "\n";
}