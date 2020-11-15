//
// Created by spl211 on 08/11/2020.
//
#include "iostream"
#include "Graph.h"
#include <vector>
#include "Session.h"
#include <queue>
#include "Tree.h"

using namespace std;

Graph::Graph(std::vector<std::vector<int>> matrix) :edges({}){

    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            edges[i][j] = matrix[i][j];
        }
    }

}

bool Graph::isInfected(int nodeInd) {
    return (Session::getStatus()[nodeInd] == 2);

}


//methods we add
vector<std::vector<int>> Graph::getEdges() {
    return edges;
}



Tree * Graph::BFS(Session session,Tree *source) {
    int v = edges.size();//number of vertices
    vector<bool> *visited = new vector<bool>;
    queue<Tree> *neighboors = new queue<Tree>;

    visited->assign(v,false);

    Tree *bfsTree =  Tree::createTree(session,source->getNode());// needs to apply virtual methods in tree
    visited->at(source->getNode()) = true;
    neighboors->push(*source);

    while (!neighboors->empty())
    {
        source = &neighboors->front();
        neighboors->pop();
        for(int i=0 ; i<v; i++)
        {
            if(!(&visited[i]) && edges[source->getNode()][i]==1)
            {
                visited->at(i) = true;//check if this how we change value in vector
                Tree *temp =Tree::createTree(session,i);
                neighboors->push (*temp);
                bfsTree->addChild(*temp);

            }

        }
    }



}

