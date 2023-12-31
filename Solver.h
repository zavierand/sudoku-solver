/***************************************************************************************
*   This is the header file for the class that will be used so solve a sudoku puzzle.
*   This class will incorporate the linked list and graph implementation to solve for
*   a grid.
***************************************************************************************/

#ifndef SOLVER_H
#define SOLVER_H

#include "LinkedList.h"
#include "Graph.h"

class Solver
{
    private:
        int rows;
        int cols;
        int sizeOfGrid;

        /******************************************************************************
        *   Since the size of both the matrix and graph are not known at runtime, we
        *   must dynamically allocate the graph and the 2d matrix.
        ******************************************************************************/

        Graph* sudokuGraph;

        // pointer to memory works the same as an array
        int** sudokuMatrix;
    public:
        // constructor and destructor
        Solver(int);
        ~Solver();

        // setters
        void inputGrid();

        // getters
        int getSizeOfGrid();
        int getRows();
        int getCols();

        /*******************************************************************************
        *   create a reference to the original graph to be modified
        *
        *   This means, we need to return the new graph that has been modified from the
        *   original graph. Because we need to create a new copy of the graph, we will
        *   transform the adjacency matrix to an adjancey list because of our graph
        *   representation. Then we switch it back and output the new matrix.
        *******************************************************************************/
        void mapSudokuToGraph();

        // solving algorithm
        void solve(Graph&);


        // additional member methods for solver class
        void printGrid();
};

#endif

// end of solver header file