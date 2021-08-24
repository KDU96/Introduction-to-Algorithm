#ifndef     _GRAPH_SEARCH_CPP_
#define     _GRAPH_SEARCH_CPP_

#include    "graph_search.hpp"
#include    "../Graph/Adjacency_List_Graph.cpp"

Graph_Search::Graph_Search(int vertex_num, bool directionality, bool weightedEdge)
:Graph(vertex_num, directionality, weightedEdge)
{
    color           =   new unsigned char[vertex_num];
    distance        =   new int[vertex_num];
    predecessor     =   new int[vertex_num];
    StartTimeTable  =   new int[vertex_num];
    EndTimeTable    =   new int[vertex_num];   
    ClassifedEdge               =   NULL;
}
Graph_Search::~Graph_Search(){
    delete[]    color;
    delete[]    distance;
    delete[]    predecessor;
    delete[]    StartTimeTable;
    delete[]    EndTimeTable;
    if(ClassifedEdge)               delete[]    ClassifedEdge;
}
void Graph_Search::InitiatingStateTable(){
    for(int i=0; i<getVertexNumber(); i++){
        color[i]            =   static_cast<unsigned char>(VertexState::WHITE);
        distance[i]         =   numeric_limits<int>::min();
        predecessor[i]      =   numeric_limits<int>::min();
        StartTimeTable[i]   =   -1;
        EndTimeTable[i]     =   -1;
        time                =    0;
    }
}

// @@@@ Algorithm for BFS @@@ //
bool Graph_Search::BFS(const int& source){
    if(source >= getVertexNumber()){
        cout << "wrong source vertex number was entered" << endl;
        return false;
    }
    InitiatingStateTable();

    queue<GraphNode*> QueueForBFS;
    // set table for source node
    color[source] = static_cast<unsigned char>(VertexState::BLACK);
    distance[source] = 0;
    predecessor[source] = -1;

    GraphNode** AdjList = getAdjList();

    QueueForBFS.push(AdjList[source]);

    int parentNodeNum = source;
    
    while(!QueueForBFS.empty()){
        GraphNode* p = AdjList[parentNodeNum];
        while(p){
            if(color[p->key] == static_cast<unsigned char>(VertexState::WHITE)){
                color[p->key]       =   static_cast<unsigned char>(VertexState::GRAY);
                distance[p->key]    =   distance[parentNodeNum] + 1;
                predecessor[p->key] =   parentNodeNum;   
                if(color[p->key] == static_cast<unsigned char>(VertexState::GRAY))
                    QueueForBFS.push(p);  
            }
            p                   =   p->next; 
        }
        QueueForBFS.pop();
        color[parentNodeNum] = static_cast<unsigned char>(VertexState::BLACK);
        if(!QueueForBFS.empty())
            parentNodeNum = QueueForBFS.front()->key;
    }
    return true;
}
bool Graph_Search::PrintShortestDistance(const int& source){//for BFS
    if(!BFS(source)){
        cout << "Breadth First Searh Error!" << endl;
        return false;
    }
    for(int i=0; i < getVertexNumber(); i++){
        cout << '[' << i << "]\t";
    }
    cout << endl;
    for(int i=0; i < getVertexNumber(); i++){
        cout << '|' << distance[i] << "|\t";
    }
    cout << endl;
    return false;
}
bool Graph_Search::PrintShortestPath(const int& source){// for BFS
    if(!BFS(source)){
        cout << "Breadth First Searh Error!" << endl;
        return false;
    }
    for(int i=0; i< getVertexNumber(); i++){
        if(predecessor[i] == numeric_limits<int>::min()){
            cout << "Vertex " << i <<  " is an Unreachable Vertex!" << endl;
            continue;
        }
        else if(predecessor[i] == -1){
            cout << "Vertex " << i << " is a source vertex!" << endl;
            continue;
        }
        else{
            cout << "Arrival Vertex" << i << "|| ";
            cout << i << ' ';
            int x = predecessor[i];
            while(x != -1){
                cout << x << ' ';
                x = predecessor[x];
            }
            cout << endl;
        }
    }
    return true;
}
// @@@ Algorithm for DFS @@@ //
bool Graph_Search::DFS(const int& source){
    if(source >= getVertexNumber()){
        cout << "wrong vertex number was entered" << endl;
        return false;
    }
    InitiatingStateTable();
    GraphNode** adjList =   getAdjList();
    
    color[source]       =   static_cast<unsigned char>(VertexState::WHITE);
    distance[source]    =   0;
    predecessor[source] =   -1;
    int count           =   0;

    for(int i=source; count < getVertexNumber(); i = (i+1) % getVertexNumber()){
        GraphNode*  p   =   adjList[i];
        while(p){
            if(color[i] == static_cast<unsigned char>(VertexState::WHITE))
                DFS_Visit(i);
            p = p->next;
        }
        count++;        
    }
    return true;
}
void Graph_Search::DFS_Visit(const int& vertex){
    color[vertex]           =   static_cast<unsigned char>(VertexState::GRAY);
    StartTimeTable[vertex]  =   ++time;
    GraphNode** adjList     =   getAdjList();
    GraphNode*  p           =   adjList[vertex];

    while(p){
        if(color[p->key] == static_cast<unsigned char>(VertexState::WHITE)){
            predecessor[p->key] =   vertex;
            DFS_Visit(p->key);
        }
        p   =   p->next;
    }
    color[vertex]           =   static_cast<unsigned char>(VertexState::BLACK);
    EndTimeTable[vertex]    =   ++time;

    topologicalSort.push_back(vertex);
}
void Graph_Search::PrintTimeTable(const int& source){
    if(!DFS(source)){
        cout << "DFS is failed!" << endl;
        return; 
    }
    cout << "start: ";
    for(int i=0; i<getVertexNumber(); i++){
        cout << StartTimeTable[i] << '\t';
    }
    cout << endl;
    cout << "end : ";
    for(int i=0; i<getVertexNumber(); i++){
        cout << EndTimeTable[i] << '\t';
    }
    cout << endl;
}
void Graph_Search::EdgeClassification(const int& source){
    if(!DFS(source)){
        cout << "DFS is failed!" << endl;
        return;
    }
    int count           =   0;
    GraphNode** adjList =   getAdjList();
    ClassifedEdge       =   new Edge[getEdgeNumber()];
    for(int i=0; i<getVertexNumber(); i++){
        GraphNode *p    =   adjList[i];
        while(p){
            ClassifedEdge[count].departure  =   i;
            ClassifedEdge[count].arrival    =   p->key;
            if(color[p->key]    ==  static_cast<unsigned char>(VertexState::WHITE))
                ClassifedEdge[count].state  =   static_cast<int>(EdgeState::TreeEdges);
            else if(color[p->key]    ==  static_cast<unsigned char>(VertexState::GRAY))
                ClassifedEdge[count].state  =   static_cast<int>(EdgeState::BackEdges);
            else{
                if(StartTimeTable[i] < StartTimeTable[p->key])
                    ClassifedEdge[count].state  =   static_cast<int>(EdgeState::ForwardEdges);
                else
                    ClassifedEdge[count].state  =   static_cast<int>(EdgeState::CrossEdges);
            }
        }
    }
}
void Graph_Search::TopologicalSort(const int& source){
    topologicalSort.clear();
    
    if(!DFS(source)){
        cout << "DFS is failed!" << endl;
        return;
    }
    vector<int>::reverse_iterator   rit;;
    for(rit = topologicalSort.rbegin(); rit != topologicalSort.rend(); rit++)
        cout << *rit << ' ';
    cout << endl;
}
#endif
