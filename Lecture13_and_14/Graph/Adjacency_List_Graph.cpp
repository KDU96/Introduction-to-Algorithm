#include "Adjacency_List_Graph.hpp"

// constructor  &   destructor

Graph::Graph(int vertex_num, bool directionality, bool weightedEdge)
:vertex_number(vertex_num), isDirectional(directionality), weighted_edge(weightedEdge) ,edge_number(0)
{
    adjList = new GraphNode*[vertex_num];
    for(int i=0; i<vertex_number; i++)  
        adjList[i]  =   NULL;
}
Graph::~Graph(){
    GraphNode* p, *q;
    for(int i=0; i<vertex_number; i++){
        p = adjList[i];
        while(p){
            q = p;
            p = p->next;
            delete q;
        }
    }
    delete[] adjList;
}

//  Update Edge
bool Graph::InsertEdge(int departure, int arrival, int weight){
    if(CheckEdge(departure, arrival))  return false;
    if(!isDirectional)
        if(CheckEdge(arrival, departure))   return false;

    GraphNode* newNode  =   new GraphNode;
    if(!newNode){
        cout << "memory allocation error" << endl;
        return false;
    }
    //  insert value
    if(weighted_edge)   newNode->weight =   weight;
    else                newNode->weight =   -1;
    newNode->next   =   NULL;
    newNode->key    =   arrival;

    if(!isDirectional){
        GraphNode *p = find_edge_location(departure);
        if(!p)     adjList[departure]  =   newNode;
        else        p->next             =   newNode;

        GraphNode   *reverseNode        =   new GraphNode;
        reverseNode->weight             =   -1;
        reverseNode->key                =   departure;
        p   =   find_edge_location(arrival);
        if(!p)      adjList[arrival]    =   reverseNode;
        else        p->next             =   reverseNode;
    }else{
        GraphNode *p = find_edge_location(departure);
        if(!p)     adjList[departure]  =   newNode;
        else       p->next             =   newNode;
    }
    edge_number++;
    return true;
}
bool Graph::DeleteEdge(int departure, int arrival){
    GraphNode   *p, *q;
    if(!isDirectional){
        if(!find_edge(departure, arrival, &p, &q))    return false;
        else{
            if(q == adjList[departure] && !(q->next)){
                delete  q;
                adjList[departure]  =   NULL;
            }else{
                if(q == adjList[departure]){
                    adjList[departure]  =   q->next;
                }else{
                    p->next =   q->next;
                }
                delete q;
            }
        }
        if(!find_edge(arrival, departure, &p, &q))    return false;
        else{
            if((q == adjList[arrival] && (!q->next))){
                delete  q;
                adjList[arrival]  =   NULL;
            }else{
                if(q == adjList[arrival]){
                    adjList[arrival]  =   q->next;
                }else{
                    p->next =   q->next;
                }
                delete q;
            }
        }
    }else{  //  when graph is directional
        if(!find_edge(departure, arrival, &p, &q))    return false;
        else{
            if(q == adjList[departure] && !(q->next)){
                delete  q;
                adjList[departure]  =   NULL;
            }else{
                if(q == adjList[departure]){
                    adjList[departure]  =   q->next;
                }else{
                    p->next =   q->next;
                }
                delete q;
            }
        }
    }
    return true;
}

//  query
bool Graph::CheckEdge(int departure, int arrival) const{
    GraphNode *p, *q;
    if(!isDirectional){
        p   =   adjList[departure];
        if(!p)  return false;
        while(p){
            if(p->key == arrival)   return true;
            p   =   p->next;
        }
        if(!p)  return  false;

        p   =   adjList[departure];
        if(!p)  return false;
        while(p){
            if(p->key == departure) return true;
            p = p->next;
        }
    }else{
        p   =   adjList[departure];
        if(!p)  return false;
        while(p){
            if(p->key == arrival)   return true;
            p   =   p->next;
        }
        if(!p)  return  false;
    }
    return false;
}
//  Read Graph  Information
int Graph::getEdgeNumber() const{
    return edge_number;
}
int Graph::getVertexNumber() const{
    return  vertex_number;
}
GraphNode** Graph::getAdjList() const{
    return adjList;
}
void Graph::print_graph() const{    //method for visualization
    GraphNode*  p;
    for(int i=0; i<vertex_number; i++){
        p   =   adjList[i];
        cout << '[' << i << ']' << "\t||";
        while(p){
            if(!weighted_edge){
                cout << p->key << '|';
            }else{
                cout << p->key << '>' << p->weight << '|';
            }
            p = p->next;
        }
        cout << endl;
    }
}

//  search
bool Graph::find_edge(int vertex, int arrival, GraphNode** PreNode, GraphNode** Target) const{
    *Target  =   adjList[vertex];
    if(!(*Target)) return  false;
    while(*Target && (*Target)->key != arrival){
        *PreNode =   *Target;
        *Target  =   (*Target)->next;
    }
    if(!(*Target))     return false;
    else            return true;
}
GraphNode*  Graph::find_edge_location(int vertex) const{
    if(!adjList[vertex])    return NULL;
    else{
        GraphNode* p    =   adjList[vertex];
        while(p->next)  p   =   p->next;
        return p;
    }
}