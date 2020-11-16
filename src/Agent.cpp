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
       int node = session.getGraph().BFS(session,tree)->traceTree();//built bfs tree from source and do tracetree on thr bfs
       session.removeEdges(session.getGraph(),node);


       Virus *v = new Virus(node);// check - i think its not true// we need to delete it metar


       ContactTracer *cT = new ContactTracer();
       session.addAgent(*cT);

       session.addAgent(*v);//we need to deldet it to it hapend in act of virud
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
     int indCarrVirus=session.getGraph().BFS(session,tree)->getChildren().front()->getNode();//check about root of bfs
     Virus *carryVirus = new Virus(indCarrVirus);
     session.addAgent(*carryVirus);// add our new carry virus to the agents list
     session.setStatus(nodeInd, 2);//change the status of nodeind from carry to sick
     session.enqueueInfected(nodeInd);//add the sick node to the infected list-----------------------------/16/11
     session.setStatus(carryVirus->nodeInd,1);//change the new carry from health to carry
}


Agent* Virus::clone() const{
    return new Virus(*this);
}