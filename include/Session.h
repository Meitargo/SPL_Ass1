#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include <queue>

#include "Graph.h"
#include "Tree.h"
#include "Agent.h"

#include <iostream>
#include <fstream>
#include "json.hpp"




using namespace std;
class Agent;

enum TreeType{
    Cycle,
    MaxRank,
    Root
};

class Session{
public:
    Session(const string& path);
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);

    void enqueueInfected(int);
    int dequeueInfected();



    //methods we add
    const queue<int> &getInfectedNodes() const;

    const vector<Agent*> &getAgents() const;
    const int getCurrIteration() const ;

    TreeType getTreeType() const; //check if ours
    Graph getGraph() const;

    void removeEdges(Graph graph, int nodeToDelete);

  //  vector<int> getStatus() ;
  //  void setStatus(int node,int stat);


private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    std::queue<int> infectedNodes;
    //std::vector<int> status;
    vector<int> infectedFinal;
    int currIteration;
};

#endif