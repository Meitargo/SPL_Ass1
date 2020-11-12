//
// Created by spl211 on 08/11/2020.
//

#include "Agent.h"
#include "Session.h"
#include "Tree.h"


Agent::Agent() {};

//contact tracer
ContactTracer::ContactTracer() {};

//methods
void ContactTracer::act(Session &session) {
    if (!session.getInfectedNodes().empty()){
       Tree* tree = createTree(session,session.dequeueInfected()); //check
       tree->traceTree(); //check   - the node need to disconnect
       session.removeEdges(session.getGraph(),tree->traceTree());
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
Virus::Virus(int nodeInd): nodeInd(nodeInd) {};

//methods
void Virus::act(int &session) {


}

Agent* Virus::clone() const{
    return new Virus(*this);
}