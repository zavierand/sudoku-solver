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

    // allocate rows
    sudokuMatrix = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        // allocate the columns
        sudokuMatrix[i] = new int[cols];
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
    return sudokuGraph->getVertices();
}

// create a reference to the original graph to be modified during solving
void Solver::mapSudokuToGraph() 
{
    // 1. Add vertices (nodes) to the graph
    for (size_t i = 0; i < sizeOfGrid; ++i) 
    {
        sudokuGraph->addVertex(i + 1); // Adding vertices with values from 1 to sizeOfGrid
    }

    // 2. Establish connections (edges) based on Sudoku constraints
    for (int i = 0; i < sizeOfGrid; ++i) 
    {
        std::cout << "1\n";
        for (int j = 0; j < sizeOfGrid; ++j) 
        {
            std::cout << "2\n";
            // Row constraint: Connect nodes in the same row
            for (int k = 0; k < sizeOfGrid; ++k) 
            {
                std::cout << "3\n";
                if (k != j) 
                {
                    sudokuGraph->addEdge(i + 1, sudokuMatrix[i][k] + 1);
                }
            }

            // Column constraint: Connect nodes in the same column
            for (int k = 0; k < sizeOfGrid; ++k) 
            {
                if (k != i) 
                {
                    sudokuGraph->addEdge(j + 1, sudokuMatrix[k][j] + 1);
                }
            }

            // Subgrid constraint: Connect nodes in the same subgrid (nxn subgrid)
            // Calculate subgrid boundaries (subRow, subCol) and connect nodes accordingly
            int subgridSize = sqrt(rows);
            int subRow = (i / subgridSize) * subgridSize;
            int subCol = (j / subgridSize) * subgridSize;

            for (int x = subRow; x < subRow + subgridSize; ++x) 
            {
                for (int y = subCol; y < subCol + subgridSize; ++y) 
                {
                    if (x != i || y != j) {
                        sudokuGraph->addEdge(sudokuMatrix[i][j], sudokuMatrix[x][y]);
                    }
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