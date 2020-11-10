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

Session::Session(const std::string &path) {
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

};

