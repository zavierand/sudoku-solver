#include "LinkedList.h"
#include "Graph.h"
#include "Solver.h"

int main()
{
    int size;
    std::cout << "Solver Test\n";

    // test input and output
    std::cout << "Enter Size of Puzzle:\n";
    std::cin >> size;
    Solver testSolver(size);

    std::cout << "Rows: " << testSolver.getRows() << std::endl;
    std::cout << "Cols: " << testSolver.getCols() << std::endl;
    std::cout << "Size of Grid: " << testSolver.getSizeOfGrid() << std::endl;

    // test input of 4x4 grid
    std::cout << "Enter the puzzle to be solved - type 0 if the space is empty:\n";
    testSolver.inputGrid();

    std::cout << "Input Grid\n";
    testSolver.printGrid();

    std::cout << "Output Grid\n";
    testSolver.printGrid();

    // test sudoku mapping
    testSolver.mapSudokuToGraph();

    return 0;
}