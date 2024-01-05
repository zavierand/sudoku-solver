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
    // 1. Add vertices (nodes) to the graph
    for (size_t i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            sudokuGraph->addVertex(sudokuMap[i][j], sudokuMatrix[i][j]); // Adding vertices with values from 1 to sizeOfGrid
        }
    }

    sudokuGraph->printAdjList();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << sudokuMap[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = 1; k < sqrt(sizeOfGrid); k++)
            {
                // col constraint
                if (k != j)
                {
                    sudokuGraph->addEdge(sudokuMap[i][j], sudokuMap[j][k]);
                    sudokuGraph->addEdge(sudokuMap[j][k], sudokuMap[i][j]);
                }

                if (k != i)
                {
                    sudokuGraph->addEdge(sudokuMap[i][j], sudokuMap[k][i]);
                    sudokuGraph->addEdge(sudokuMap[k][i], sudokuMap[i][j]);
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