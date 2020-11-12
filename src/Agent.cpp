//
// Created by spl211 on 08/11/2020.
//

#include "Agent.h"
#include "Session.h"
#include "Tree.h"


Agent::Agent() {};

//contact tracer
ContactTracer::ContactTracer():Agent() {};

//methods
void ContactTracer::act(Session &session) {
    if (!session.getInfectedNodes().empty()){
       Tree* tree = Tree::createTree(session,session.dequeueInfected()); // take node from the infected node and create tree
       int node = tree->traceTree(); //check   - the node need to dis
       session.removeEdges(session.getGraph(),node);
       Virus *v = new Virus(node);
       ContactTracer *cT = new ContactTracer();
       session.addAgent(*cT);
       session.addAgent(*v);
       // createTree By treeType from the session
       //tree.maxRankTree();
       //l1: we should build max rank tree
       //l2: we should delete the graph edges of the return l2
       // add to agents list
    }
}

Agent* ContactTracer::clone() const{
    return new ContactTracer(*this);
}


//visrus
//constractor
Virus::Virus(int nodeInd):Agent(), nodeInd(nodeInd) {};

//methods
void Virus::act(int &session) {


}

Agent* Virus::clone() const{
    return new Virus(*this);
}