#ifndef SSOLVER_H
#define SSOLVER_H

/**********************************************************
* This is the solver class. In this class, you will find
* the algorithms behind solving whether or not a sudoku 
* puzzle is solvable or not. Mainly applying the theory 
* behind graph coloring, coloring will be used to represent
* whether or not a number is being repeated. There are
* multiple algorithms defined in this file to assist in 
* applying coloring to the graph, mostly through the use of 
* bool values as well as through the use of 2D matricies to
* define the board as well as the input that will be received
* from the users through main.cpp
**********************************************************/

#include <iostream>
#include <vector>
#include <cctype>
#include "graph.h"

class SSolver : public Graph
{
    private:

    public:
        // setters
        void fillBoard( int );

        // getters
        int getFilledBoard();
        void getResult();

        // additional member methods
        void coloring( Graph& );
        bool isConnected( Graph ) const;
};

#endif