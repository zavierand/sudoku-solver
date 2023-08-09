#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

/**********************************************************
* This is the graph class. This class represents, as well 
* as the graph, that will be filled with  the values the 
* user inputs into the program. User will input a set of 
* numbers that will be used to fill the board.
*
* This class is the base of what will be used to represent
* the functions used in the sSolver.cpp file as well as a
* the algorithms behind solving each puzzle inputted.
***********************************************************/

// declare rows and columns of the graph; cannot be modified
const int ROWS = 4;
const int COLS = 4;

struct node 
{
    int data;
    int color;
    bool filled;
    node* next;
    node* back;
};

class Graph
{
    private:
        int boardArr[ROWS][COLS];
        int size;
        node* head;
    public:
        Graph();
        void insertNode( node*, int) ;
        int getSize();
        bool isEmpty();
        void addEdge( node*, node* );
        void BFS( node* );
        void inOrderTraversal( node* );
};

#endif