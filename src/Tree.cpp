//
// Created by spl211 on 08/11/2020.
//

# include "Tree.h"
# include "Session.h"
#include "Graph.h"



Tree::Tree(int rootLabel): node(rootLabel), children(){};


void Tree::clear() {
    for(auto& children:children)
    {
        delete children;
    }
}
//ruleOf5

//destructor
Tree::~Tree() {
   clear();
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


//--------------------------------------------------------------end ruleOf5
//Methods-Tree

void Tree::addChild(const Tree &child) {
     Tree* tempChild = child.clone();
     children.push_back(tempChild);
}

Tree * Tree::createTree(const Session &session, int rootLabel) {
    Tree* newTree;
      if(session.getTreeType() == Cycle)
           newTree = new CycleTree(rootLabel,1); //change currCycle
      else if(session.getTreeType() == MaxRank)
           newTree = new MaxRankTree(rootLabel);
      else if(session.getTreeType() == Root)
           newTree = new RootTree(rootLabel);

      return newTree;

}


//methods we add
int Tree::getNode() {
    return node;
}

vector<Tree*> Tree::getChildren() {
    return children;
}
//-------------------------------------------------------------endTreeMethods



//CycleTree constructor
CycleTree::CycleTree(int rootLabel, int currCycle):Tree(rootLabel), currCycle(currCycle) {};

//CycleTreeMethods
Tree* CycleTree::clone() const {
    Tree *tree = new CycleTree(this->node,this->currCycle);
    for(int i=0; i<tree->getChildren().size(); i++)
    {
        tree->getChildren().push_back(this->children[i]);
    }

    return tree;
}

int CycleTree::traceTree() {
    Tree *tempNode = this;
    int childrenSize ;
    queue<Tree> *nodes = new queue<Tree>;
    nodes->push(*tempNode);

    while(currCycle+1!=0)
    {
        tempNode = &nodes->front();
        childrenSize = tempNode->getChildren().size();

        while(childrenSize+1>0)
        {
              tempNode = &nodes->front();
              nodes->pop();
              for(int i=0; i<tempNode->getChildren().size();i++)
              {
                  //insertChildrenToQueue
                  nodes->push(*tempNode->getChildren()[i]);
              }
              childrenSize--;
         }
            currCycle--;
    }
    return nodes->front().getNode();
}



//MaxRankTree constructor
MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {};

//MaxRankTreeMethods
Tree* MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}

int MaxRankTree::traceTree() {
    int sizeChild=0;
    int maxChild=0;
    for (int i = 0; i < children.size(); i++) {
        if(children[i]->getChildren().size() > sizeChild)
        {
            sizeChild = children[i]->getNode();
            maxChild=i;
        }
    }
    return maxChild;
}

//RootTree constructor
RootTree::RootTree(int rootLabel):Tree(rootLabel) {}

//RootTreeMethods
Tree* RootTree::clone() const {
    return new RootTree(*this);
}

int RootTree::traceTree() {
    return node;
}










