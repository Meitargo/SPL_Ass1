#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent();

    //methods
    virtual void act(Session& session)=0;

    //methods we add:
    virtual Agent* clone() const =0;
};


class ContactTracer: public Agent {
public:
    ContactTracer();
    //methods
    virtual void act(Session &session);

    //methods we add
    virtual Agent *clone() const;
};



class Virus: public Agent{
public:
    //methods
    Virus(int nodeInd);
    virtual void act(Session& session);


    //methods we add
    virtual Agent* clone() const;

private:
    const int nodeInd;
};

#endif