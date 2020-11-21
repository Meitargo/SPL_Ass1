//
// Created by spl211 on 08/11/2020.
//

#include "Graph.h"
#include "Session.h"

using namespace std;



Graph::Graph(std::vector<std::vector<int>> matrix) :edges(matrix),status(vector<int>()){ //we initialize the edges to be empty


        if(edges.size()>0)
             status.assign(edges.size(),0);

}//now our edges initialize to be the matrix


//Graph methods
bool Graph::isInfected(int nodeInd) {
        return (getStatus()[nodeInd] == 2);

}


void Graph::infectNode(int nodeInd) {
getStatus()[nodeInd]=2;

}


//methods we add
vector<vector<int>>& Graph::getEdges() {
    return edges;
}
Tree * Graph::BFS(Session session, Tree *bfstree,queue<int> q,vector<bool> &discoverd) {
    if(q.empty())
        return bfstree;
    int v=q.front();
    q.pop();

    Tree *tmp=Tree::createTree(session,v);
    queue<int> childrenOf;
    for(int u=0;u<edges[v].size();u++){
        if(edges[v][u]==1 && !(discoverd[u])){
            discoverd[u]=true;
            q.push(u);
            childrenOf.push(u);
            tmp->addChild(*Tree::createTree(session,u));


        }
    }
    for(int k=0;k<tmp->getChildren().size();k++) {

    bfstree->addRealChid(BFS(session,tmp->getChildren()[k],childrenOf,discoverd));
        childrenOf.pop();
    }

    //bfstree->addChild(*BFS(session,tmp,q,discoverd));

return bfstree;

};

vector<int> Graph::getStatus()  {
    return status;
}

void Graph::setStatus(int node, int newStat) {
    status[node] = newStat;
}
