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



    //methods we add
    const queue<int> &getInfectedNodes() const;
    const vector<Agent*> getAgents() const;
    TreeType getTreeType() const; //check if ours
    void removeEdges(Graph graph, int nodeToDelete);
    Graph getGraph() const;


private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    std::queue<int> infectedNodes;
};

#endif