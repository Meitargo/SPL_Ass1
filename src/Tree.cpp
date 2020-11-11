//
// Created by spl211 on 08/11/2020.
//

# include "Tree.h"

//ruleOf5
Tree::Tree(int rootLabel): node(rootLabel), children(){};

//destructor
Tree::~Tree() {
    for(auto& children:children)
    {
       delete children;
    }
}

//copy constructor
 Tree::Tree(const Tree &other) {
    Tree* temp = other.clone();
}

//assignment operator
const Tree & Tree::operator=(const Tree &other) {
    Tree* temp = other.clone();
    return *this;
}

// move constructor
Tree::Tree(Tree &&other) {
    Tree* temp = other.clone();
}

//move assignment operator
const Tree & Tree::operator=(Tree &&other) {
    Tree* temp = other.clone();
    return *this;
}

int Tree::getNode() {
    return node;
}
//--------------------------------------------------------------end ruleOf5
//Methods-Tree

void Tree::addChild(const Tree &child) {
     Tree* tempChild = child.clone();
     children.push_back(tempChild);
}

Tree * Tree::createTree(const Session &session, int rootLabel) {

}
//-------------------------------------------------------------endTreeMethods

//CycleTree constructor
CycleTree::CycleTree(int rootLabel, int currCycle):Tree(rootLabel), currCycle(currCycle) {};

//CycleTreeMethods
Tree* CycleTree::clone() const {
    return new CycleTree(*this);
}

//MaxRankTree constructor
MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {};

//MaxRankTreeMethods
Tree* MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}

//RootTree constructor
RootTree::RootTree(int rootLabel):Tree(rootLabel) {}

//RootTreeMethods
Tree* RootTree::clone() const {
    return new RootTree(*this);
}










