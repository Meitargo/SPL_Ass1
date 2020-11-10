//
// Created by spl211 on 08/11/2020.
//

# include "Tree.h"

Tree::Tree(int rootLabel): node(rootLabel), children(){};

Tree::~Tree() {
    if(node) delete &node;
}

Tree::Tree(const Tree &other) {

}

void Tree::addChild(const Tree &child) {
    children.push_back(child);
}





