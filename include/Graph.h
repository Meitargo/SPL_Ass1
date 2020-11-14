#ifndef GRAPH_H_
#define GRAPH_H_

#include <queue>
#include <vector>
#include "Tree.h"

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);

    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);

    //methods we add
    Tree* BFS (Session session,Tree *source);
    vector<std::vector<int>> getEdges();
    void addEdges(int a, int b);


private:
    std::vector<std::vector<int>> edges;
}

#endif