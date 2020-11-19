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

    //ruleOf5
    /*virtual ~Session(); //destructor
    Session(const Session &other, Graph g); //copy constructor
    const Session& operator= (const Session & other);//assignment operator - check const
    Session(Session &&other, Graph g); // move constructor
    const Session& operator = (Session && other); //move assignment operator - check const
    Session* clone() const;*/

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
    Graph& getGraph();

    void removeEdges(Graph &graph, int nodeToDelete);



private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    std::queue<int> infectedNodes;
    vector<int> infectedFinal;
    int currIteration;
};

#endif