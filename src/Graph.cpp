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
    if(()) {

    }
}

//methods we add
vector<std::vector<int>> Graph::getEdges() {
    return edges;
}






Tree * Graph::BFS(int source) {
    int v = edges.size();//number of vertices
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }

    queue<int> *neighboors = new queue<int>;
    Tree *bfsTree = new Tree(source); // needs to apply virtual methods in tree
    visited[source] = true;
    neighboors->push(source);

    while (!neighboors->empty())
    {
        source = neighboors->front();
        neighboors->pop();
        for(int i=0 ; i<v; i++)
        {
            if(!visited[i] && edges[source][i]==1)
            {
                visited[i]= true;
                neighboors->push(i);
            }

        }
    }



}

