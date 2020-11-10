//
// Created by spl211 on 08/11/2020.
//

#include "Agent.h"
#include "Session.h"



Agent::Agent() {};


//contact tracer
ContactTracer::ContactTracer() {};

//methods
void ContactTracer::act(Session &session) {
    if (!session.getInfectedNodes().empty()){
       session.dequeueInfected();
       //l1: we should build max rank tree
       //l2: we should delete the graph edges of the return l2
       // add to agents list
    }
}

Agent * ContactTracer::clone() const {
    return new ContactTracer(*this);
}


//visrus
//constractor
Virus::Virus(int nodeInd): nodeInd(nodeInd) {};

//mwthods
void Virus::act(int &session) {


}
Agent* Virus::clone() const {
    return new Virus(*this);
}