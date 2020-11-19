//
// Created by spl211 on 08/11/2020.
//yey

#include "Agent.h"

Agent::Agent() {};


//contact tracer
ContactTracer::ContactTracer() : Agent() {};


//methods
void ContactTracer::act(Session &session) {
    if (!session.getInfectedNodes().empty()) //if the queue of the infected is not empty
    {
        int source = session.dequeueInfected();
        Tree *tree = Tree::createTree(session, source); // take node from the infected node and create tree
        int node = session.getGraph().BFS(session,
                                          tree)->traceTree();//built bfs tree from source and do tracetree on thr bfs
        session.removeEdges(session.getGraph(), node);

    }
}


Agent *ContactTracer::clone() const {
    return new ContactTracer(*this);
}

//visrus

Virus::Virus(int nodeInd) : Agent(), nodeInd(nodeInd) {};

//methods
void Virus::act(Session &session) {
    Graph &g = session.getGraph();

    int i = 0;
    vector<int> &neigh = g.getEdges()[nodeInd];
    int indCarrVirus = -1;
    int size = neigh.size();
    while (indCarrVirus == -1 && i < size) {
        if (neigh[i] == 1 & g.getStatus()[i] == 0)
            indCarrVirus = i;
        i++;
    }


    if (indCarrVirus != -1) {
        Virus *carryVirus = new Virus(indCarrVirus);
        session.addAgent(*carryVirus);// add our new carry virus to the agents list
        g.setStatus(nodeInd,2);//change the status of nodeind from carry to sick
        session.enqueueInfected(nodeInd);//add the sick node to the infected list-----------------------------/16/11
        g.setStatus(carryVirus->nodeInd, 1);//change the new carry from health to carry
    }
}


Agent *Virus::clone() const {
    return new Virus(*this);
}