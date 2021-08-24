#include    "GraphForDijkstra.hpp"

int main(){
    GraphForDijkstra    myGraph(5);
    myGraph.InsertEdge(0, 1, 10);
    myGraph.InsertEdge(0, 2, 5);
    myGraph.InsertEdge(1, 2, 2);
    myGraph.InsertEdge(1, 3, 1);
    myGraph.InsertEdge(2, 1, 3);
    myGraph.InsertEdge(2, 3, 9);
    myGraph.InsertEdge(2, 4, 2);
    myGraph.InsertEdge(3, 4, 4);
    myGraph.InsertEdge(4, 0, 7);
    myGraph.InsertEdge(4, 3, 6);

    myGraph.PrintSolution(0);    
}
