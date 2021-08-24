#ifndef _GRAPH_FOR_DIJKSTRA_
#define _GRAPH_FOR_DIJKSTRA_

#include    "../Lecture13_and_14/Graph/Adjacency_List_Graph.hpp"
#include    <limits>
#include    <queue>

using namespace std;

struct VertexForPQ{
    int     index;
    int     distance;
    int     parent;
    bool    isVisited;
};
class Compare{
    public :
        bool operator()(VertexForPQ a, VertexForPQ b){
            return a.distance > b.distance;
        }
};

class GraphForDijkstra : public Graph{
    private :
        VertexForPQ   *node;
        void           relax(const int& u, const int& v, const int& w);
    public :
        GraphForDijkstra(int vertex_num, bool directionality = true, bool weightedEdge = true);
        ~GraphForDijkstra();
        void ExecutingDijkstraAlgorithm(const int& source);
        void PrintSolution(const int& source);
};
#endif