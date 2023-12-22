# PROJECT: SUDOKU SOLVER

## Goal: To solve sudoku problems that are input into the program
The goal of this project is for the program to solve and spew out the result of any sudoku problem that is passed as input.
The

## Overview of the Project and the Algorithm
As a junior at NYU, I took CSCI-UA.310 - Basic Algorithms this past Fall 2023 semester, which taught me a lot of the fundamentals of algorithm design
and problem solving (shout out Professor Guan), which will be applied to this project. Duing the semester, we learned about a fundamental problem
within theoretical computer science and discrete mathematics, does "P" = "NP"? While this topic was only touched upon once during the semester - the applciations
and intution behind many of these problems exist in a number of different domains.

Sudoku is a game where the player must fill in a board consisting of 81 cells, 9 rows and 9 columns, where the number in the cell is unique to its row, column, and 3x3 grid (which are labeled clearly on an actual gameboard). Alongside demonstrating skills in data structures and object-oriented programming, I
also wanted to demonstrate knowledge in algorithm design and modification. Knowing the contraints of the sudoku problem, I wanted to apply what was learned in my algorithms class to solve this problem.

A brief overview on "P" and "NP". What the hell is "P" and "NP"? Well, the letters simply refer to the term "polynomial" and "nondeterministic polynomial". problems that are considered solvable in P time are problems that have verified and proofs to confirm that the most optimal solution to these problems exist in polynomial, or "P", time. 

On the otherhand, problems that are considered "NP" have solutions that can guessed and the algorithm that can be derived. However, the algorithms for these problems are confirmed to be in "nonpolynomial" (NP) time. However, there are problems within the the set of NP problems that have yet to be solved - including the graph isomorphism problem, the discrete logarithm problem, and the integer factorization problem.

NP problems can be categorized into different types of problems. NP complete problems and NP-hard problems.
## Thought Process:
Each cell (node) within the puzzle cannot be adjacent to a cell (node) with the same color.
If there is a color ollision with these nodes and the colors are the same, the immediate 
response to that would be that there should be no edge connecting these respective cells. Hence,
each node should be adjacent to another vertex that differs in color and each corresponding 
vertex should differ in color.

## Sources:
https://www.britannica.com/science/P-versus-NP-problem

