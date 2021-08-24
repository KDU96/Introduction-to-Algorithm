#ifndef _GRAPH_SEARCH_HPP_
#define _GRAPH_SEARCH_HPP_

#include    "../Graph/Adjacency_List_Graph.hpp"
#include    <queue>
#include    <limits>
#include    <vector>

enum class VertexState{
    WHITE,
    BLACK,
    GRAY,
};

enum class EdgeState{
    TreeEdges,
    BackEdges,
    ForwardEdges,
    CrossEdges,
};
struct Edge{
    int departure;
    int arrival;
    int state;
};

class Graph_Search : public Graph{
    private :
        unsigned char *color;   // state
        int           *distance;    // distance
        int           *predecessor; // parent vertex
        int           *StartTimeTable;
        int           *EndTimeTable;
        int            time;
        void           DFS_Visit(const int& vertex);
        Edge*          ClassifedEdge;
        vector<int>   topologicalSort;

    protected :
        void InitiatingStateTable();
    public :
        Graph_Search(int vertex_num, bool directionality, bool weightedEdge = -1);
        ~Graph_Search();
        bool BFS(const int& source);
        bool DFS(const int& source);
        bool PrintShortestPath(const int& source);
        bool PrintShortestDistance(const int& source);
        void PrintTimeTable(const int& source);
        void EdgeClassification(const int& source);
        void TopologicalSort(const int& source);
};

#endif