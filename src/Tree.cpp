//
// Created by spl211 on 08/11/2020.
//

# include "Tree.h"

Tree::Tree(int rootLabel): node(rootLabel), children(){};

Tree::~Tree() {
    //destructor
    if(node) delete &node;
}

Tree::Tree(const Tree &other) {

}

int Tree::getNode() {
    return node;
}

void Tree::clone() const {
  if (node == nullptr)
  {
      return nullptr;
  }
  else
  {
      Tree *node = new Tree(getNode());

  }


}

void Tree::addChild(const Tree &child) {
    children.push_back(child);
}





