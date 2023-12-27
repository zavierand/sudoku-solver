#include "LinkedList.h"
#include "Graph.h"

int main() {

    Graph testGraph(9);

    std::cout << "The graph contains " << testGraph.getVertices() << " vertices.\n";

    // new test graph add vertices to the graph - on alpha
    testGraph.addVertex(1);
    testGraph.addVertex(2);
    testGraph.addVertex(3);
    testGraph.addVertex(4);
    testGraph.addVertex(5);
    testGraph.addVertex(6);
    testGraph.addVertex(7);
    testGraph.addVertex(8);
    testGraph.addVertex(9);
    
    // add edges connecting vertices
    testGraph.addEdge(1, 4);
    testGraph.addEdge(1, 6);
    testGraph.addEdge(1, 8);
    testGraph.addEdge(2, 8);
    testGraph.addEdge(3, 6);
    testGraph.addEdge(3, 7);
    testGraph.addEdge(4, 3);
    testGraph.addEdge(5, 7);
    testGraph.addEdge(5, 9);
    testGraph.addEdge(6, 2);
    testGraph.addEdge(6, 7);
    testGraph.addEdge(8, 9);
    testGraph.addEdge(9, 5);
    testGraph.addEdge(9, 1);

    // check size of array
    std::cout << "Graph has " << testGraph.getVertices() << " vertices.\n";

    testGraph.printAdjList();

    // test BFS;
    std::cout << "*** BFS TESTS ***\n";
    std::cout << "BFS Traversal of Graph from node 1:\n";
    testGraph.BFS(1);
    std::cout << "\n";

    std::cout << "BFS Traversal of Graph from node 2:\n";
    testGraph.BFS(2);
    std::cout << "\n";

    std::cout << "BFS Traversal of Graph from node 3:\n";
    testGraph.BFS(3);
    std::cout << "\n";

    std::cout << "BFS Traversal of Graph from node 4:\n";
    testGraph.BFS(4);
    std::cout << "\n\n";

    // test DFS
    std::cout << "*** DFS TESTS ***\n";
    std::cout << "DFS Traversal of Graph from node 1:\n";
    testGraph.DFS(1);
    std::cout << "\n";

    std::cout << "DFS Traversal of Graph from node 2:\n";
    testGraph.DFS(2);
    std::cout << "\n";

    std::cout << "DFS Traversal of Graph from node 3:\n";
    testGraph.DFS(3);
    std::cout << "\n";

    std::cout << "DFS Traversal of Graph from node 4:\n";
    testGraph.DFS(4);
    std::cout << "\n";

    return 0;

}