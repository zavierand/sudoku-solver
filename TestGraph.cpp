#include "LinkedList.h"
#include "Graph.h"

int main() {

    Graph testGraph(5);

    std::cout << "The graph contains " << testGraph.getVertices() << " vertices.\n";

    // add vertices to the graph
    testGraph.addVertex(1);
    testGraph.addVertex(2);
    testGraph.addVertex(3);
    testGraph.addVertex(4);
    testGraph.addVertex(5);
    
    // add edges connecting vertices
    testGraph.addEdge(1, 2);
    testGraph.addEdge(1, 3);
    testGraph.addEdge(1, 4);
    testGraph.addEdge(2, 1);
    testGraph.addEdge(2, 4);
    testGraph.addEdge(3, 1);
    testGraph.addEdge(3, 4);
    testGraph.addEdge(4, 1);
    testGraph.addEdge(4, 2);
    testGraph.addEdge(4, 3);
    testGraph.addEdge(4, 5);
    testGraph.addEdge(5, 4);

    // check size of array
    std::cout << "Graph has " << testGraph.getVertices() << " vertices.\n";

    testGraph.printAdjList();

    // test BFS;
    std::cout << "BFS Traversal of Graph:\n";
    testGraph.BFS(1);

    return 0;

}