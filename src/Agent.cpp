//
// Created by spl211 on 08/11/2020.
//yey

#include "Agent.h"

Agent::Agent() {};
 Agent::~Agent() {};

//contact tracer
ContactTracer::ContactTracer() : Agent() {};
ContactTracer::~ContactTracer() {};

//methods
void ContactTracer::act(Session &session) {
    if (!session.getInfectedNodes().empty()) //if the queue of the infected is not empty
    {
        int source = session.dequeueInfected();
        Tree *tree = Tree::createTree(session, source); // take node from the infected node and create tree
        queue<int> q;
        q.push(source);
        vector<bool> visited;
        for(int i=0;i<session.getGraph().getEdges().size();i++)
            visited.push_back(false);
        visited[source]=true;
        Tree *bfsTree=session.getGraph().BFS(session,tree,q,visited);
        int nodeToDel = bfsTree->traceTree();//built bfs tree from source and do tracetree on thr bfs
        if(nodeToDel!=-1)
        session.removeEdges(session.getGraph(), nodeToDel);

    }
}
//Agent::~Agent() {};

Agent *ContactTracer::clone() const {
    return new ContactTracer(*this);
}

//visrus

Virus::Virus(int nodeInd) : Agent(), nodeInd(nodeInd) {};
 Virus::~Virus() {};

//methods
void Virus::act(Session &session) {
    Graph &g = session.getGraph();
    int i = 0;
    vector<int> &neigh = g.getEdges()[nodeInd];

    int indCarrVirus = -1;
    int size = neigh.size();
    while (indCarrVirus == -1 && i < size) {
        if ((neigh[i] == 1) & (g.getStatus()[i] == 0))
            indCarrVirus = i;
        i++;
    }


    if (indCarrVirus != -1) {
        Virus *carryVirus = new Virus(indCarrVirus);
        session.addAgent(*carryVirus);// add our new carry virus to the agents list
        g.setStatus(indCarrVirus, 1);//change the new carry from health to carry
    }
    else {
        g.getStatus()[nodeInd] = 2;
    }
    if(!(g.getStatus()[nodeInd]==2)) {
        g.setStatus(nodeInd, 2);//change the status of nodeind from carry to sick
        session.enqueueInfected(nodeInd);//add the sick node to the infected list-----------------------------/16/11
    }
}


Agent *Virus::clone() const {
    return new Virus(*this);
}