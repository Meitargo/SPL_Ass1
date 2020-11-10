//
// Created by spl211 on 08/11/2020.
//

# include "Tree.h"

Tree::Tree(int rootLabel): node(rootLabel), children(){};

Tree::~Tree() {
    //destructor
    for(auto& children:children)
    {
       delete children;
    }
}

Tree::Tree(const Tree &other) {
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        Tree *node1 = new Tree(other.node);
    }
}

int Tree::getNode() {
    return node;
}

void Tree::clone() const {



}

void Tree::addChild(const Tree &child) {
    children.push_back(&child);
}





