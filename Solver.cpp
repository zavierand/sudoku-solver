#include "Solver.h"

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
    // first, we add all the vertices that we need
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            sudokuGraph->addVertex(sudokuMatrix[i][j]);
        }
    }

    // next, we'll create edges in between the vertices, keeping in mind grid constraints 
    int subRow;
    int subCol;
    
    sudokuGraph->printAdjList();
}
// solving algorithm

// additional member methods for solver class
void Solver::printGrid()
{
    std::cout << "- - - - - - - - -\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "| " << sudokuMatrix[i][j] << " ";
        }
        std::cout << "|\n";
        if ((i % rows) - 1 == 0)
        {
            std::cout << " - - - - - - - - \n"; 
        }
    }
    std::cout << "- - - - - - - - -\n";
}