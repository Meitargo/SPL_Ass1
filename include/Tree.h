#ifndef TREE_H_
#define TREE_H_

#include <vector>
//#include "Graph.h"
#include <queue>

using namespace std;
class Session;

class Tree{
public:

    Tree(int rootLabel);

    //ruleOf5
    virtual ~Tree(); //destructor
    Tree(const Tree &other); //copy constructor
    const Tree& operator= (const Tree & other);//assignment operator - check const
    Tree(Tree && other); // move constructor
    const Tree& operator = (Tree && other); //move assignment operator - check const

    void addChild(const Tree& child);



    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;

    //methods we add
    virtual Tree* clone() const=0 ;////////18/11
    int getNode();
    std::vector<Tree*> getChildren();
    void clear();
    void addRealChid(Tree* child);

protected:
    int node;
    std::vector<Tree*> children;


};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();

    //methods we add
    virtual Tree* clone() const;

private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();

    //methods we add
    virtual Tree* clone() const;
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();

    //methods we add
    virtual Tree* clone() const;
};

#endif