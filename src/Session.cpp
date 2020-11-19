//
// Created by spl211 on 08/11/2020.
//

#include "Session.h"



using json = nlohmann::json;
using namespace std;



// initialize
Session::Session(const std::string &path):g(vector<vector<int>>()),treeType(),agents(),infectedNodes(),infectedFinal(),currIteration(0){
    ifstream i(path);
    json j;
    i >> j;

    g=Graph(j["graph"]);

    //initialize treeType - check
    if(j["tree"]=="C")
        treeType = Cycle;
    else if(j["tree"]=="M")
        treeType = MaxRank;
    else if(j["tree"]=="R")
        treeType = Root;


    for(auto& agent:j["agents"])
    {
            Agent *agentTemp;

            if(agent[0]=="C")
                agentTemp = new ContactTracer();
            else
            {
                agentTemp = new Virus((int) agent[1]);
                g.getStatus()[(int)agent[1]] = 1;
            }

            agents.push_back(agentTemp);

    }



};

//ruleOf5
/*
Session::~Session() {
    for(int i=0; i<agents.size();i++)
    {
        if(agents[i]!=nullptr)
            delete agents[i];
    }
    //distructor

}


Session::Session(const Session &other, Graph g) : g(g) {
    //copy constructor

}

const Session & Session::operator=(const Session &other) {
    //copy assignment constructor
}

Session::Session(Session &&other, Graph g) : g(g) {
    //move constructor
}

const Session & Session::operator=(Session &&other) {
    //move assignment constructor
}

Session * Session::clone() const {
  //  Session *session = new Session(this->g, this->treeType, this->agents, this->infectedNodes, this->infectedFinal, this->currIteration);
    Session *session = new Session(this->path);
}
 */

void Session::simulate() {
    int HowManyInAgents=-1;

    while(HowManyInAgents!=0)
    {
        HowManyInAgents= agents.size();
        for(int i=0; i<agents.size(); i++)
        {
            agents[i]->act(*this);
        }
        HowManyInAgents=agents.size()-HowManyInAgents;
        currIteration++;
    }

    for(int i=0;i<g.getStatus().size();i++){
        if(g.getStatus()[i]==2)
            infectedFinal.push_back(i);
    }

    json j;
    j["graph"]=g.getEdges();
    j["infected"]=infectedFinal;
    std::ofstream i("./output.json");
    i<<j;

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
    g=graph;

}
//methods we added
const queue<int> &Session::getInfectedNodes() const {
    return infectedNodes;
}

const vector<Agent*>& Session::getAgents() const {
    return agents;
}

 Graph& Session::getGraph() {
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


/*
vector<int> Session::getStatus()  {
    return status;
}

void Session::setStatus(int node, int newStat) {
    status[node] = newStat;
}
*/

const int Session::getCurrIteration() const {
    return currIteration;
}






