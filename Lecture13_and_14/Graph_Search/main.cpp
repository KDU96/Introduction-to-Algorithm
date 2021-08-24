#include "graph_search.hpp"

int main(){
    Graph_Search  graph_with_directionality(6, DIRECTIONALITY, NON_WEIGHTED_EDGE);
    graph_with_directionality.InsertEdge(0, 1);
    graph_with_directionality.InsertEdge(0, 3);
    graph_with_directionality.InsertEdge(1, 4);
    graph_with_directionality.InsertEdge(2, 5);
    graph_with_directionality.InsertEdge(2, 4);
    graph_with_directionality.InsertEdge(3, 1);
    graph_with_directionality.InsertEdge(4, 3);
    graph_with_directionality.InsertEdge(5, 5);

    graph_with_directionality.PrintShortestDistance(0);
    graph_with_directionality.PrintShortestPath(0);
    graph_with_directionality.print_graph();

    graph_with_directionality.PrintTimeTable(0);
//    graph_with_directionality.PrintTimeTable(5);
    
    graph_with_directionality.TopologicalSort(0);

}