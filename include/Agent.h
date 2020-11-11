#ifndef AGENT_H_
#define AGENT_H_

#include <vector>

class Agent{
public:
    Agent();

    //methods
    virtual void act(Session& session)=0;

    //methods we add:
    virtual Agent* clone() =0;
};


class ContactTracer: public Agent {
public:
    ContactTracer();
    //methods
    virtual void act(Session &session);

    //methods we add
    virtual Agent *clone();
};



class Virus: public Agent{
public:
    //methods
    Virus(int nodeInd);
    virtual void act(Session& session);


    //methods we add
    virtual Agent* clone() ;

private:
    const int nodeInd;
};

#endif