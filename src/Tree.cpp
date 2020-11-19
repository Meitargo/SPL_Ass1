//
// Created by spl211 on 08/11/2020.
//

# include "Tree.h"
# include "Session.h"

Tree::Tree(int rootLabel): node(rootLabel), children({}){};


void Tree::clear() {
    for(auto& children:children)
    {
        if(children!=nullptr)
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
           newTree = new CycleTree(rootLabel,session.getCurrIteration());
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
    int i=0;
    int ans;
    Tree *Node = this;// tree from ct the whole tree not just a node
    int currForfor=currCycle;
    while(currForfor!=0){
        vector<Tree*> tmp=Node->getChildren();
        if(!(tmp[i]->getChildren().empty()))
            Node=tmp[i];
        else{
            i=1;
            if(i<tmp.size()){
                while(tmp[i]->getChildren().empty())
                    i=i+1;
                Node=tmp[i];
            }
         }
        ans=tmp[i]->getNode();
        currForfor--;
    }
    return ans;
    }


//MaxRankTree constructor
MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {};

//MaxRankTreeMethods
Tree* MaxRankTree::clone() const {
    Tree *tree = new MaxRankTree(this->node);
    for(int i=0; i<tree->getChildren().size(); i++)
    {
        tree->getChildren().push_back(this->children[i]);
    }

    return tree;
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
    Tree *tree = new RootTree(this->node);
    for(int i=0; i<tree->getChildren().size(); i++)
    {
        tree->getChildren().push_back(this->children[i]);
    }

    return tree;
}

int RootTree::traceTree() {
    return node;
}










