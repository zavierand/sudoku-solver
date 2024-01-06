#include "Solver.h"
#include <cmath>

// constructor and destructor
Solver::Solver(int n)
{ 
    rows = n;
    cols = n;
    sizeOfGrid = n * n;

    // dynamically allocate the graph and the 2d matrix
    sudokuGraph = new Graph(sizeOfGrid);

    // allocate rows for both matrices
    sudokuMatrix = new int*[rows];
    sudokuMap = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        // allocate the columns for both matrices
        sudokuMatrix[i] = new int[cols];
        sudokuMap[i] = new int[cols];
    }

    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            k++;
            sudokuMap[i][j] = k;
        }
    }
}

Solver::~Solver()
{
    delete sudokuGraph;
    delete sudokuMatrix;
}

// setters
void Solver::inputGrid()
{
    int gridValue;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> gridValue;
            sudokuMatrix[i][j] = gridValue;
        }
    }
}

// getters
int Solver::getRows()
{
    return rows;
}

int Solver::getCols()
{
    return cols;
}

int Solver::getSizeOfGrid()
{
    // check if graph size is initialized correctly
    return sudokuGraph->getVertices();
}

// create a reference to the original graph to be modified during solving
void Solver::mapSudokuToGraph() 
{
    // add vertices (nodes) to the graph
    for (size_t i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            sudokuGraph->addVertex(sudokuMap[i][j], sudokuMatrix[i][j]);
        }
    }

    // add edges between all vertices in rows and cols
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            for (int k = 0; k < cols; k++) 
            {
                // col constraint
                if (k != j) 
                {         
                    sudokuGraph->addEdge(sudokuMap[i][j], sudokuMap[i][k], sudokuMatrix[i][k]);
                }

                // row constraint
                if (k != i) 
                {
                    sudokuGraph->addEdge(sudokuMap[i][j], sudokuMap[k][j], sudokuMatrix[k][j]);
                }          
            }
        }
    }


    /************************************************************************************
    *   1. in each subgrid, there should be an edge between all the vertices
    *   2. to check that, we can check if there is a path between all of the vertices
    *   3. if the shortest path is a path with an edge count > 1, then there is no edge 
    *   between the starting vertex and the destination vertex.
    *   4. we can create an edge if the path returns a length > 1
    *   5. what i decided to do was run BFS or DFS to find a path from all vertices
    *   within a subgrid to create edges within a subgrid.
    *   6. this should work on all within a subgrid.
    ************************************************************************************/

    // add respective edges remaining in each subgrid
    // subgrid constraints
    // subgrid declarations

    int subgridSize = sqrt(sizeOfGrid);
    int subgridRow = 2;
    int subgridCol = 2;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = 1; k < subgridCol; k++)
            {
                if (sudokuGraph->BFS(sudokuMap[i][j], sudokuMap[i][k]) == true && sudokuGraph->checkEdge(sudokuMap[i][j], sudokuMap[i][k]) == false)
                {
                    sudokuGraph->addEdge(sudokuMap[i][j], sudokuMap[i][k], sudokuMatrix[i][k]);
                }
            }
        }
    }
    // Print or perform other operations with the graph
    sudokuGraph->printAdjList();
}

// solving algorithm

// additional member methods for solver class
void Solver::printGrid()
{
    std::cout << "- - - - - - - - - - - - -\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "|  " << sudokuMatrix[i][j] << "  ";
        }
        std::cout << "|\n";
        if ((i % rows) - 1 == 0)
        {
            std::cout << " - - - - - - - - - - - - \n"; 
        }
    }
    std::cout << "- - - - - - - - - - - - -\n";
}