//
// Created by spl211 on 08/11/2020.
//

# include "Tree.h"

//ruleOf5
Tree::Tree(int rootLabel): node(rootLabel), children(){};

Tree::~Tree() {
    //destructor
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


void Tree::addChild(const Tree &child) {

    Tree* tempChild = child.clone();
    children.push_back(tempChild);
}

Tree* CycleTree::clone() const {
    return new CycleTree(*this);
}

Tree* MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}

Tree* RootTree::clone() const {
    return new RootTree(*this);
}







