#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include <queue>
#include "Graph.h"
#include "Tree.h"

using namespace std;
class Agent;

enum TreeType{
    Cycle,
    MaxRank,
    Root
};

class Session{
public:
    Session(const std::string& path);

    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);


    void enqueueInfected(int);
    int dequeueInfected();
    TreeType getTreeType() const;


    //methods we add
    const queue<int> &getInfectedNodes() const;


private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    std::queue<int> infectedNodes;
};

#endif