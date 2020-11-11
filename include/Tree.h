#ifndef TREE_H_
#define TREE_H_

#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    ~Tree(); //destructor
    Tree(const Tree &other); //copy constructor
    const Tree& operator= (const Tree & other);//assignment copy constructor - check const

    void addChild(const Tree& child);
    const Tree& getChild(int) const;



    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;

    //methods we add
    virtual Tree* clone() const =0;
    int getNode();
private:
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