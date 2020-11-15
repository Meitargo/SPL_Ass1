//
// Created by spl211 on 08/11/2020.
//yey

#include "Agent.h"
#include "Session.h"
#include "Tree.h"



Agent::Agent() {};

//contact tracer
ContactTracer::ContactTracer():Agent() {};

//methods
void ContactTracer::act(Session &session) {
    if (!session.getInfectedNodes().empty()){
        int source = session.dequeueInfected();
       Tree* tree = Tree::createTree(session,source); // take node from the infected node and create tree
       session.getGraph().BFS(session,tree);
       int node = tree->traceTree(); //check   - the node need to dis
       session.removeEdges(session.getGraph(),node);
       Virus *v = new Virus(node);
       ContactTracer *cT = new ContactTracer();
       session.addAgent(*cT);
       session.addAgent(*v);
    }
}

    Agent * ContactTracer::clone () {
    return new ContactTracer(*this);
}




//visrus
//constractor
Virus::Virus(int nodeInd):Agent(), nodeInd(nodeInd) {};

//methods
void Virus::act(Session &session) {

Tree* tree = Tree::createTree(session,nodeInd);
Virus *carryVirus = new Virus(session.getGraph().BFS(session,tree)->getChildren().front()->getNode());
session.addAgent(*carryVirus);

}

Agent* Virus::clone() {
    return new Virus(*this);
}