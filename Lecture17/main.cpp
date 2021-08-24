#include "BellmanFord.hpp"

int main(){
    GraphForBellmanFord myGraph(5);

    myGraph.InsertEdge(0, 1, 6);
    myGraph.InsertEdge(0, 2, 7);
    myGraph.InsertEdge(1, 2, 8);
    myGraph.InsertEdge(1, 3, 5);
    myGraph.InsertEdge(1, 4, -4);
    myGraph.InsertEdge(2, 3, -3);
    myGraph.InsertEdge(2, 4, 9);
    myGraph.InsertEdge(3, 1, -2);
    myGraph.InsertEdge(4, 0, 2);
    myGraph.InsertEdge(4, 3, 7);

    myGraph.PrintSolution(0);
    
}