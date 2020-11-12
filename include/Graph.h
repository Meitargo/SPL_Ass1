#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include "Tree.h"

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);

    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);

    //methods we add
    Tree* BFS (int source, Graph currGraph);
    vector<std::vector<int>> getEdges();

private:
    std::vector<std::vector<int>> edges;
}

#endif