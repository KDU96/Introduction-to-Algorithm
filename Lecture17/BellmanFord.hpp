#ifndef     _BELLMAN_FORD_HPP_
#define     _BELLMAN_FORD_HPP_

#include    "../Lecture13_and_14/Graph/Adjacency_List_Graph.hpp"
#include    <limits>

struct VertexState{
    int index;
    int distance;
    int parent;
};

class GraphForBellmanFord : public Graph{
    // Bellman-Ford can detect the negative edge cyecle.
    private :
        VertexState *vertex;
        void relaxation(const int& u, const int& v, const int& w);
        bool BellmanFord(const int& source);
    public :
        GraphForBellmanFord(int vertex_num);
        ~GraphForBellmanFord();
        bool PrintSolution(const int& source);
};

#endif
