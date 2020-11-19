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


Session::~Session() {
    //distructor
    for(int i=0; i<agents.size();i++)
    {
        if(agents[i]!=nullptr)
            delete agents[i];
    }


}


Session::Session(const Session &other) : g(other.g),treeType(other.treeType),agents(),infectedNodes(other.infectedNodes),infectedFinal(other.infectedFinal),currIteration(other.currIteration)  {
    //copy constructor
    for(int i=0 ;i <other.agents.size();i++)
    {
        Agent* newAgent =(other.agents[i])->clone();
        agents.push_back(newAgent);
    }

}

const Session & Session::operator=(const Session &other) {
    //copy assignment constructor
    for(int i=0 ;i <other.agents.size();i++)
    {
        Agent* newAgent =(other.agents[i])->clone();
        agents.push_back(newAgent);
    }
    return *this;

}

Session::Session(Session &&other) :g(other.g),treeType(other.treeType),agents(),infectedNodes(other.infectedNodes),infectedFinal(other.infectedFinal),currIteration(other.currIteration) {
    //move constructor
    for(int i=0 ;i <other.agents.size();i++)
    {
        Agent* newAgent =(other.agents[i])->clone();
        agents.push_back(newAgent);
    }
}

const Session & Session::operator=(Session &&other) {
    //move assignment constructor
    for(int i=0 ;i <other.agents.size();i++)
    {
        Agent* newAgent =(other.agents[i])->clone();
        agents.push_back(newAgent);
    }
    return *this;
}



void Session::simulate() {
    int HowManyInAgents=-1;

    while(HowManyInAgents!=0)
    {
        HowManyInAgents= agents.size();
        int size = agents.size();
        for(int i=0; i<size; i++)
        {
            agents[i]->act(*this);
            size = agents.size();
        }
        HowManyInAgents=size-HowManyInAgents;
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

void Session::removeEdges(Graph &graph, int nodeToDelete) {
    //vector<std::vector<int>> tempEdges = graph.getEdges();
    int size = graph.getEdges().size();
   for(int i=0; i<size; i++)
   {
       graph.getEdges()[nodeToDelete][i] = 0;
       graph.getEdges()[i][nodeToDelete] = 0;
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






