#include    "../Lecture13_and_14/Graph/Adjacency_List_Graph.cpp"
#include    "BellmanFord.hpp"

GraphForBellmanFord::GraphForBellmanFord(int vertex_num)
:Graph(vertex_num, DIRECTIONALITY, WEIGHTED_EDGE){
    vertex  =   new VertexState[getVertexNumber()];
}
GraphForBellmanFord::~GraphForBellmanFord(){
    delete[]    vertex;
}
void GraphForBellmanFord::relaxation(const int& u, const int& v, const int& w){
    if(vertex[v].distance > vertex[u].distance + w){
        vertex[v].distance  =   vertex[u].distance + w;
        vertex[v].parent    =   u;
    }
}
bool GraphForBellmanFord::BellmanFord(const int& source){
    GraphNode** adjList =   getAdjList();
    GraphNode*  p       =   adjList[source];

    for(int i=0; i<getVertexNumber(); i++){
        vertex[i].index =   i;
        vertex[i].distance  =   numeric_limits<int>::max();
        vertex[i].parent    =   numeric_limits<int>::min();
    }
        vertex[source].distance =   0;
        vertex[source].parent   =   -1;

    for(int i=1; i <= getVertexNumber()-1; i++){
        for(int j=0;    j < getVertexNumber(); j++){
            p   =   adjList[j];
            while(p){
                relaxation(j, p->key, p->weight);
                p   =   p->next;
            }
        }
    }
    for(int i=0; i<getVertexNumber(); i++){
        p   =   adjList[i];
        while(p){
            if(vertex[p->key].distance > vertex[i].distance + p->weight)
                return false;
            p   =   p->next;
        }
    }
    return true;
}
bool GraphForBellmanFord::PrintSolution(const int& source){
    if(!BellmanFord(source)){
        cout << "The negative edge cycle was detected" << endl;
        return false;
    }
    for(int i=0; i<getVertexNumber(); i++){
        cout << "index : " << vertex[i].index << ' ';
        cout << "distance : " << vertex[i].distance << ' ';
        cout << "parent : " << vertex[i].parent << endl;
    }
    return true;
}

