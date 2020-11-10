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
Session::Session(const std::string &path):g({}),treeType(),agents(),infectedNodes(){
    ifstream i(path);
    json j;
    j << i;
    g=Graph(j["graph"]);
    treeType= j["tree"];

    for(auto& agent:j["agents"])
    {
            Agent *agentTemp;

            if(agent[0]=="C")
                agentTemp = new ContactTracer();
            else
                agentTemp = new Virus((int) agent[1]);

            agents.push_back(agentTemp);

    }
   // infectedNodes = new queue<Tree>;      we should check if the initalize list is enough

};

//methods
void Session::addAgent(const Agent &agent) {
    agents.push_back(agent);
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

//methods we added
const queue<int> &Session::getInfectedNodes() const {
    return infectedNodes;
}



