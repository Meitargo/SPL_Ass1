#ifndef GRAPH_H_
#define GRAPH_H_

//#include <queue>
#include <vector>
#include "Tree.h"
//#include "Session.h"
//#include "iostream"

class Session;
class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);

    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);

    //methods we add
    Tree* BFS (Session session,Tree* source);
    std::vector<std::vector<int>> getEdges();

    //////////////////////////////////////////////////////17/11
    std::vector<int> getStatus() ;
    void setStatus(int node,int stat);


private:
    std::vector<std::vector<int>> edges;

///////////////////////////////////////////////////////////17/11
    std::vector<int> status;
};

#endif