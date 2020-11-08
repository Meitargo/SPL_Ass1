//
// Created by spl211 on 08/11/2020.
//

#include "Agent.h"

Agent::Agent(){};

virtual void act(Session& session)=0;

ContactTracer::ContactTracer(){};

virtual void act(Session& session);

Virus(int nodeInt):nodeInt(nodeInt){}


virtual void act(Session& session);