# PROJECT: SUDOKU SOLVER

## Goal: To solve sudoku problems that are input into the program

This is a simple project to solve 4x4 sudoku problems. The goal of this project is to 
create a program that provides solutions to solve any sudoku problem that it's given.
The implemenation of the project was done in an object-oriented programming manner with
the language used to implent the code being C++.

The implementation defines a graph that is used to represent the puzzle. Each cell within
the graph is a node/vertex that can be found in the graph. 

I wanted to incorporate and demonstrate my understanding of graph theory as well as the graph
data structure to solve the problems that were given. Hence - the algorithm in laymens terms,
takes each vertex and assigns each of them a number. Graph coloring was used to output a 
filled graph, indicating the solution to the puzzle. 

Each "color" represents the value in which a node should be filled. From 1 - 4, the color
coordination is as follows -

Color Code for Graph Coloring Algorithm:
1 = blue
2 = red
3 = yellow
4 = green

## Graph Coloring Algorithm:
The graph coloring algorithm is a simple way to visualize, represent, and label a graph. Given
an undirected graph, one can apply the algorithm of graph coloring to label the graph in such a
way that no vertex can be adjacent to another vertex with the same information - in the case of
coloring, the same color.

After coloring the graph, the vertices that are adjacent to each other can be represented through
a variety of different representations such as an adjacency matrix or through set notation. 

There are many applications for the use of graph coloring, for example finding whether or not a 
graph has a path, is cyclic or not, and the applications run large. In the case of this project, 
graph coloring is used to find whether an adjacent vertex (sudoku cell) is filled with a repeating
number - represented by a color, and if so, the vertices being compared in that situation should not
be adjacent to each other.

## Thought Process:
Each cell (node) within the puzzle cannot be adjacent to a cell (node) with the same color.
If there is a color ollision with these nodes and the colors are the same, the immediate 
response to that would be that there should be no edge connecting these respective cells. Hence,
each node should be adjacent to another vertex that differs in color and each corresponding 
vertex should differ in color.
