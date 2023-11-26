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
    LinkedList<int> adjList[numVertices];
    this->numVertices = 0;
}

Graph::~Graph()
{
    /******************************************************** 
    *   we simply call the linked list destructor and then 
    *   delete the head pointer at each array index
    ********************************************************/
    for(int i = 0; i < numVertices - 1; i++)
    {
        adjList[i].~;
    }
}

// search for edges
void Graph::searchEdge(node*<int>, int)
{

}

// search graph
void Graph::DFS(LinkedList<int> graph[], int source)
{
    // we initialize the queue to hold our data
    Queue<int> Q;
    for( /* all vertices in the set of vertices in the graph */ )
    {
        
    }

    // we push onto the queue to keep track of vertices being visited
    Q.push(source);
    while( !Q.isEmpty() )
    {
        Q.pop(adjList[i]);
        for()
        {

        }
    }
    
}

// add edges
void Graph::addEdge(int vertex, int newEdge)
{
    node<T>* temp = new node<T>;

    // since we are hashing the data, we can simply
    adjList[vertex].insertNode(newEdge);
}

// additional member methods
bool Graph::isEmpty()
{
    return numVertices == 0;
}