#include <iostream>
#include <cctype>
#include <vector>
#include "sSolver.h"

// main fucntion prototypes
void printGameBoard( int[][COLS], int );

int main()
{
    // enter the program

    // local variables to store puzzle
    int storePuzzleInfo, cellNum;
    char yesNo;

    // 2D matrix to display/print to terminal
    int gameBoard[ROWS][COLS];  // array usage

    // display message to terminal
    std::cout << "SUDOKU SOLVER" << std::endl;

    // loop to take in puzzle
    std::cout << "Enter the puzzle to be solved (use 0s to represent blank spaces)" << std::endl;
    for( int i = 0; i < ROWS; i++ )
    {
        for( int j = 0; j < COLS; j++ )
        {
            // user input for each cell
            std::cin >> storePuzzleInfo;
            gameBoard[i][j] = storePuzzleInfo;

            // check to see if input is valid
            /*
            if( !std::isdigit( storePuzzleInfo ) )
            {
                std::cerr << "Not a digit! Enter a number:" << std::endl;
                std::cin >> storePuzzleInfo;
            }
            */
            
        }
    }

    std::cout << "Here is the puzzle you entered - is this correct? (y/n)" << std::endl;
    printGameBoard( gameBoard, ROWS );

    std::cin >> yesNo;

    // additional input validation
    do
    {
        std::cout << "Enter the cell number you would like to change: " << std::endl;
        std::cin >> cellNum;

        std::cout << "Enter the correct number: ";
        std::cin >> storePuzzleInfo;
        if( cellNum > 0 && cellNum < 4 )
        {
            gameBoard[ROWS - 4][( cellNum % COLS ) - 1] = storePuzzleInfo;
        }
        else if( cellNum > 5 && cellNum < 8 )
        {
            gameBoard[ROWS - 3][( cellNum % COLS ) - 1] = storePuzzleInfo;
        }
        else if( cellNum > 9 && cellNum < 12 )
        {
            gameBoard[ROWS - 2][( cellNum % COLS ) - 1] = storePuzzleInfo;
        } 
        else if( cellNum > 13 && cellNum < 16 )
        {
            gameBoard[ROWS - 1][( cellNum % COLS ) - 1] = storePuzzleInfo;
        }
        std::cout << "Is this puzzle correct? (y/n)" << std::endl;
        printGameBoard( gameBoard, ROWS );
        std::cin >> yesNo;
    }
    while( yesNo == 'n' );

    /**********************************
    *   [ insert solver functions ]   *
    **********************************/
}

// prototype definitions
void printGameBoard( int board[][COLS], int ROWS )
{
    for( int i = 0; i < 4; i++ )
    {
        std::cout << "( ";
        for( int j = 0; j < 4; j++ )
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << ")" << std::endl;
    }
}