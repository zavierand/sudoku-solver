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

#include "LinkedList.h"
#include <queue>    // time crunch to implement working queue -> will implement my own eventually
#include <stack>
#include <vector>

class Graph
{
    private:
        // we will represent the graph through an adjacency list
        std::vector<LinkedList<int>*> adjList;
        int numVertices;
        int color;
    
    public:
        // constructor and destructor
        Graph(int);
        ~Graph();

        // getters
        int getVertices();

        // searching algorithms
        void BFS(int);
        void DFS(int);

        // add graph components
        void addVertex(int, int);
        void addEdge(int, int);

        // additional member methods
        bool isEmpty();
        void printAdjList();
};

#endif

// end of Graph header file