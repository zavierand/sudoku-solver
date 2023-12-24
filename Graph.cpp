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

// search for a path
/*
void Graph::Hamiltonian()
{

}
*/

// add graph components
void Graph::addVertex(int v)
{   
    LinkedList<int>* vertex = new LinkedList<int>;
    vertex->insertNode(v);
    adjList.push_back(vertex);
}

void Graph::addEdge(int s, int d) {
    if (s >= 0 && s < adjList.size() && d >= 0 && d < adjList.size()) 
    {
        adjList[s]->insertNode(d);
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
    for (int i = 0; i < numVertices; i++)
    {
        adjList[i]->printList();
        std::cout << "\n";
    }
}
