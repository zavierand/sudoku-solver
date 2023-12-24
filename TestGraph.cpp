#include "LinkedList.h"
#include "Graph.h"

int main() {

    Graph testGraph(5);

    std::cout << "Graph contains " << testGraph.getVertices() << " vertices.\n";

    testGraph.addVertex(1);
    testGraph.addVertex(2);
    testGraph.addVertex(3);
    testGraph.addVertex(4);
    testGraph.addVertex(5);

    std::cout << "Graph, G, Adjacency List:\n";
    testGraph.printAdjList();
    
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

    std::cout << "Graph, G, Adjacency List:\n";
    testGraph.printAdjList();

    return 0;

}