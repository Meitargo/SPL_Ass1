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
    if (!session.getInfectedNodes().empty()) //if the queue of the infected is not empty
    {
       int source = session.dequeueInfected();
       Tree* tree = Tree::createTree(session,source); // take node from the infected node and create tree
       session.getGraph().BFS(session,tree); //built bfs tree from source
       int node = tree->traceTree(); //check   - the node need to dis
       session.removeEdges(session.getGraph(),node);
       Virus *v = new Virus(node);
       ContactTracer *cT = new ContactTracer();
       session.addAgent(*cT);
       session.addAgent(*v);
    }
}


    Agent*  ContactTracer::clone () const {
    return new ContactTracer(*this) ;
}




//visrus

Virus::Virus(int nodeInd):Agent(), nodeInd(nodeInd) {};

//methods
void Virus::act(Session &session) {
     Tree* tree = Tree::createTree(session,nodeInd);
     int indCarrrVirus=session.getGraph().BFS(session,tree)->getChildren().front()->getNode();//check about root of bfs
     Virus *carryVirus = new Virus(indCarrrVirus);
     session.addAgent(*carryVirus);// add our new carry virus to the agents list
     session.setStatus(nodeInd, 2);//change the status of nodeind from carry to sick
     session.setStatus(carryVirus->nodeInd,1);//change the new carry from health to carry
}


Agent* Virus::clone() const{
    return new Virus(*this);
}