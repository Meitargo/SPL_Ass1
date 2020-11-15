//
// Created by spl211 on 08/11/2020.
//

#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Session.h"
#include "Agent.h"
#include "Tree.h"
#include "Graph.h"


using json = nlohmann::json;
using namespace std;

// initialize
Session::Session(const std::string &path):g({}),treeType(),agents(),infectedNodes(), status(){
    ifstream i(path);
    json j;
    j << i;
    g=Graph(j["graph"]);

    //initialize treeType - check
    if(j["tree"]=="C")
        treeType = Cycle;
    else if(j["tree"]=="M")
        treeType = MaxRank;
    else if(j["tree"]=="R")
        treeType = Root;

    for(int i=0; i<g.getEdges().size(); i++)
    {
        status[i] = 0;
    }

    for(auto& agent:j["agents"])
    {
            Agent *agentTemp;

            if(agent[0]=="C")
                agentTemp = new ContactTracer();
            else
            {
                agentTemp = new Virus((int) agent[1]);
                status[(int)agent[1]] = 1;
            }

            agents.push_back(agentTemp);

    }


   // infectedNodes = new queue<Tree>;      we should check if the initalize list is enough

};

void Session::simulate() {
    while()
    {
        for(int i=0; i<agents.size(); i++)
        {
            agents[i]->act(*this);
        }
    }

    for(int i=0; i<status.size(); i++)
    {
        if(status[i] == 2)
        {
            for(int i=0; i<status.size(); i++)
            {
                for(int j=0; j<status.size(); j++
                {
                    if(getGraph().getEdges()[i][j] == 1 & status[j] ==2) {
                    }

                }
            }
        }
    }

}
//methods
void Session::addAgent(const Agent &agent) {
    agents.push_back(agent.clone());
}

void Session::enqueueInfected(int nodeInd) {
    infectedNodes.push(nodeInd);
}


int Session::dequeueInfected() {
    int first = infectedNodes.front();
    infectedNodes.pop();
    return first;
}


TreeType Session::getTreeType() const {
    return treeType;
}

void Session::setGraph(const Graph &graph) {

}
//methods we added
const queue<int> &Session::getInfectedNodes() const {
    return infectedNodes;
}

const vector<Agent*> Session::getAgents() const {
    return agents;
}

 Graph Session::getGraph() const {
    return g;
}

void Session::removeEdges(Graph graph, int nodeToDelete) {
    vector<std::vector<int>> tempEdges = graph.getEdges();
   for(int i=0; i<tempEdges.size(); i++)
   {
       tempEdges[nodeToDelete][i] = 0;
       tempEdges[i][nodeToDelete] = 0;
   }

}

vector<int> Session::getStatus()  {
    return status;
}

void Session::setStatus(int node, int newStat) {
    status[node] = newStat;
}





