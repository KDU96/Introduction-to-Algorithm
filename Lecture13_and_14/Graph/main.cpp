#include "Adjacency_List_Graph.hpp"

int main(){
    Graph   graph_with_non_directinality(5, NON_DIRECTINALITY, NON_WEIGHTED_EDGE);
    Graph   graph_with_directionality(6, DIRECTIONALITY, NON_WEIGHTED_EDGE);

    graph_with_non_directinality.InsertEdge(0, 1);
    graph_with_non_directinality.InsertEdge(0, 4);
    graph_with_non_directinality.InsertEdge(1, 2);
    graph_with_non_directinality.InsertEdge(1, 3);
    graph_with_non_directinality.InsertEdge(1, 4);
    graph_with_non_directinality.InsertEdge(2, 3);
    graph_with_non_directinality.InsertEdge(3, 4);

    cout << "non-directional graph" << endl;
    graph_with_non_directinality.print_graph();
    graph_with_non_directinality.DeleteEdge(0,1);
    graph_with_non_directinality.DeleteEdge(0,4);
    graph_with_non_directinality.DeleteEdge(1,2);
    graph_with_non_directinality.DeleteEdge(1,3);
    graph_with_non_directinality.DeleteEdge(1,4);
    graph_with_non_directinality.DeleteEdge(2,3);
    graph_with_non_directinality.DeleteEdge(3,4);

    cout << "after deletion" <<endl;
    graph_with_non_directinality.print_graph();

    graph_with_directionality.InsertEdge(0, 1);
    graph_with_directionality.InsertEdge(0, 3);
    graph_with_directionality.InsertEdge(1, 4);
    graph_with_directionality.InsertEdge(2, 5);
    graph_with_directionality.InsertEdge(2, 4);
    graph_with_directionality.InsertEdge(3, 1);
    graph_with_directionality.InsertEdge(4, 3);
    graph_with_directionality.InsertEdge(5, 5);

    cout << "directional graph" << endl;
    graph_with_directionality.print_graph();
    cout << "after deletion" << endl;
    graph_with_directionality.DeleteEdge(0, 1);
    graph_with_directionality.DeleteEdge(0, 3);
    graph_with_directionality.DeleteEdge(1, 4);
    graph_with_directionality.DeleteEdge(2, 5);
    graph_with_directionality.DeleteEdge(2, 4);
    graph_with_directionality.DeleteEdge(3, 1);
    graph_with_directionality.DeleteEdge(4, 3);
    graph_with_directionality.DeleteEdge(5, 5);

    graph_with_directionality.print_graph();

}