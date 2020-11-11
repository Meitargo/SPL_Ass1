//
// Created by spl211 on 08/11/2020.
//
#include "iostream"
#include "Graph.h"
#include <vector>
#include "Session.h"

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

