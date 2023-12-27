# PROJECT: SUDOKU SOLVER

## Goal: To solve sudoku problems that are input into the program
The goal of this project is for the program to solve and spew out the result of any sudoku problem that is passed as input.
The

## Overview of the Project:
As a junior at NYU, I took CSCI-UA.310 - Basic Algorithms this past Fall 2023 semester, which taught me a lot of the fundamentals of algorithm design
and problem solving (shout out Professor Guan), which will be applied to this project. Duing the semester, we learned about a fundamental problem
within theoretical computer science and discrete mathematics, does "P" = "NP"? While this topic was only touched upon once during the semester - the applciations and intution behind many of these problems exist in a number of different domains.

Sudoku is a game where the player must fill in a board consisting of 81 cells, 9 rows and 9 columns, where the number in the cell is unique to its row, column, and 3x3 grid (which are labeled clearly on an actual gameboard). Alongside demonstrating skills in data structures and object-oriented programming, I
also wanted to demonstrate knowledge in algorithm design and modification. Knowing the contraints of the sudoku problem, I wanted to apply what was learned in my algorithms class to solve this problem.

## What is P and NP?
A brief overview on "P" and "NP". What the hell is $P$ and $NP$? Well, the letters simply refer to the term "polynomial" and "nondeterministic polynomial". Problems that are considered solvable in P are problems that have been verified containing proofs to confirm that the most optimal solution to these problems exist in polynomial, or "P", time. 

You can think of it almost like this - P is a set of the easiest problems that can be solved in polynomial time. One example of a problem in the P set is a simple multiplcaiton problem. In computer science, a problem that can be categorized as a P problem is sorting - which, in the worst-case we know most sorting algorithms have a time complexity of O(n^2) - which is still polynomial time (polynomial and exponential are different). 

Now that we know what P is, problems that are NP can be classified as problems that are more difficult than problems that can be classified in the set of P, aka, the answer may not be as obvious as something in P. However, we can guess a solution to a problem in the NP set, and will be able to verify that a solution to the problem can be computed in polynomial time. 

Within the set of problems, we established that $P$ is a subset of $NP$, $P \subset NP$. We can classify NP problems even more, as NP-complete problems and NP-hard problems. NP-complete problems are problems that can be solved by a nondeterministic machine to compute a solution in polynomial time. NP-hard problems are problems, in this case - let's say v, where it can only be solved by reducing v to an NP-complete problem, we'll call x in this situation. So - by reducing v to x, we can say that an NP-hard problem has a computable NP-complete solution. Examples of problems that are NP-complete are the Hamiltonian Path, 3SAT problem, and Vertex Covering. 

The question, though, is can we guarantee a solution to problems that are considered NP in P time? That is the whole debate, $P$ vs $NP$. Does $P = NP$? If P does indeed equal NP, we would have a ton of solutions overnight that would dramatically affect the discourse of the current computational tundra. 

However, that's a problem that is far beyond my current academic level - but an interesting for those who are interested in studying computational complexity theory.

## Algorithm:
As we discussed in the former, by reducing an $NP$-hard problem, u, to an NP-complete problem, x, we can at least verify that there exists a solution to u by proof of x. 

For the sudoku problem, being an NP-hard problem - given a 9x9 grid, we must find a unique combination of cell orderings from 1-9 within the same row, column, and 3x3 grid that fills the entire 9x9 set. We know that the Hamiltonian Path is an NP-complete problem, where the problem states that given a graph, we must find a path between a source vertex, s, and a destination vertex, d, such that for all vertices in the path, $\forall v \in V$ , each of them are unique in itself (no repeating vertices in the graph), $v_1 \neq v_2 \neq ... \neq v_n$, where n is the input size (in our case, 9).

Hence, by reducing the Sudoku Problem to the Hamiltonian Problem, we can verify that there exists a solution to the Sudoku Problem.

## Sources:
P vs NP
https://www.britannica.com/science/P-versus-NP-problem
https://www.geeksforgeeks.org/difference-between-np-hard-and-np-complete-problem/#
https://www.geeksforgeeks.org/difference-between-deterministic-and-non-deterministic-algorithms/

State Space Searching
https://www.baeldung.com/cs/state-space-search#:~:text=A%20state%20space%20is%20a,state%2C%20and%20the%20goal%20state.
