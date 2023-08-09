#include <iostream>
#include <ctype.h>
#include <vector>
#include "sSolver.h"

// global variable declaration
const int ROWS = 4;
const int COLS = 4;

// main fucntion prototypes
void printGameBoard(int[][COLS], int);

int main()
{
    // enter the program

    // local variables to store puzzle
    int storePuzzleInfo = 0;
    char yesNo;

    // 2D matrix to display/print to terminal
    int gameBoard[ROWS][COLS];  // array usage

    // display message to terminal
    std::cout << "\tSUDOKU SOLVER" << std::endl;

    // loop to take in puzzle
    std::cout << "enter the puzzle to be solved (use 0s to represent blank spaces)" << std::endl;
    for( int i = 0; i < ROWS; i++ )
    {
        for( int j = 0; j < COLS; j++ )
        {
            std::cin >> storePuzzleInfo;
            gameBoard[i][j] = storePuzzleInfo;

            // check to see if input is valid
            if( !std::isDigit(storePuzzleInfo) )
            {
                throw( "Not a digit! Enter a number" );
                std::cin >> storePuzzleInfo;
            }
        }
    }

    std::cout << "Here is the puzzle given - is this correct? (y/n)" << std::endl;
    printGameBoard(  );

}

// prototype definitions
void printGameBoard(int[][COLS] board, int ROWS)
{
    for( int i = 0; i < 4; i++ )
    {
        std::cout << "( ";
        for( int j = 0; j < 4; j++ )
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << " )\n";
    }
}