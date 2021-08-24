#ifndef     _GRAPH_FOR_DIJKSTRA_CPP_
#define     _GRAPH_FOR_DIJKSTRA_CPP_

#include    "GraphForDijkstra.hpp"
#include    "../Lecture13_and_14/Graph/Adjacency_List_Graph.cpp"

GraphForDijkstra::GraphForDijkstra(int vertex_num, bool directionality, bool weightEdge)
: Graph(vertex_num, directionality, weightEdge){
        node    =   new VertexForPQ[getVertexNumber()];
}
GraphForDijkstra::~GraphForDijkstra(){
        delete[]    node;
}

void GraphForDijkstra::relax(const int& u, const int& v, const int& w){
    if( node[v].distance > node[u].distance + w){
        node[v].distance =   node[u].distance + w;
        node[v].parent   =   u;
    }
}
void GraphForDijkstra::ExecutingDijkstraAlgorithm(const int& source){
    // initialization
    for(int i=0; i<getVertexNumber(); i++){
        node[i].distance    =   numeric_limits<int>::max();
        node[i].parent      =   numeric_limits<int>::min();
        node[i].isVisited   =   false;
        node[i].index       =   i;
    }
    node[source].distance    =   0;
    node[source].parent      =   -1;
    node[source].isVisited   =   true;

    priority_queue<VertexForPQ, vector<VertexForPQ>, Compare> pq;

    for(int i=0; i<getVertexNumber(); i++)  pq.push(node[i]);

    GraphNode** adjList     =   getAdjList();
    GraphNode* p;

    while(!pq.empty()){
        VertexForPQ tmp     =   pq.top();
        pq.pop();           //  V * logV
        tmp.isVisited       =   true;
        p                   =   adjList[tmp.index];
        while(p){   // E * logV     -- logV : PQ's heapfiy overhead
            relax(tmp.index, p->key, p->weight);
            node[p->key].isVisited  =   true;
            p                       =   p->next;
        }    
    }
}
void GraphForDijkstra::PrintSolution(const int& source){
    ExecutingDijkstraAlgorithm(source);
    for(int i=0; i<getVertexNumber(); i++){
        cout << "index    : " << node[i].index << ' ';
        cout << "distance : " << node[i].distance << ' ';
        cout << "parent   : " << node[i].parent << ' ';
        cout << "Visited  : " << node[i].isVisited << ' ';
        cout << endl;
    }
}

#endif