#ifndef     ADJACENCY_LIST_GRAPH_HPP_
#define     ADJACENCY_LIST_GRAPH_HPP_

#include    <iostream>
#include    <cstdlib>
#include    <ctime>

#define     GRAPH_VERTEX_NUMBER     10
#define     GRAPH_EDGE_NUMBER       5
#define     DIRECTIONALITY          true
#define     NON_DIRECTINALITY       false
#define     WEIGHTED_EDGE           true
#define     NON_WEIGHTED_EDGE       false

using namespace std; 

struct GraphNode{
    int key;
    int weight;
    GraphNode *next;  
};

class Graph{
    private :
        GraphNode   **adjList;
        int         vertex_number;
        bool        isDirectional;
        bool        weighted_edge;
        int         edge_number;
        //  search
        GraphNode*  find_edge_location(int vertex) const;
        bool  find_edge(int vertex, int arrival, GraphNode **PreNode, GraphNode **Target) const;
    protected :
        GraphNode** getAdjList() const;
    public :
        Graph(int vertex_num, bool directionality, bool weightedEdge);
        ~Graph();
        //  Update Edge
        bool InsertEdge(int departure, int arrival, int weight = -1);
        bool DeleteEdge(int departure, int arrival);
        //query
        bool CheckEdge(int departure, int arrival) const;

        //  Read Graph Information
        int getEdgeNumber() const;
        int getVertexNumber() const;
        void print_graph() const;
};
#endif