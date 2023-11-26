/******************************************************************************************
*   This is the header file for the graph data strucutre that will be used to 
*   hold the data of the sudoku solver. This program uses a combination of multiple
*   data structures to hold and represent the data. Since we are implementing an
*   adjacency list to represent the graph, we need to initialize an array of 
*   linked lists. We will be hashing the data by holding the list of adjacent vertices
*   in a linked list for each index representing the corresponding adjacent vertex
*   relationship.
******************************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include "LINKEDLIST.h"
#include "QUEUE.h"

class Graph
{
    private:
        // we will represent the graph through an adjacency list
        LinkedList<int> adjList[numVertices];
        int numVertices;
    
    public:
        // constructor and destructor
        Graph();
        ~Graph();

        // search for edges
        void searchEdge(node*<int>, int);

        // search graph
        void DFS(node*<int>, int);

        // add edges
        void addEdge(int);

        // additional member methods
        bool isEmpty();

};

#endif