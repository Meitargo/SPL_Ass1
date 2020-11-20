//
// Created by spl211 on 08/11/2020.
//

#include "Graph.h"
#include "Session.h"

using namespace std;



Graph::Graph(std::vector<std::vector<int>> matrix) :edges(matrix),status(vector<int>()){ //we initialize the edges to be empty


        if(edges.size()>0)
             status.assign(edges.size(),0);

}//now our edges initialize to be the matrix


//Graph methods
bool Graph::isInfected(int nodeInd) {
        return (getStatus()[nodeInd] == 2);

}


void Graph::infectNode(int nodeInd) {
getStatus()[nodeInd]=2;

}


//methods we add
vector<vector<int>>& Graph::getEdges() {
    return edges;
}

Tree* Graph::Bfs(Session session,Tree* source) {
    int v = edges.size();//number of vertices
    vector<bool> visited;
    queue<Tree *> neighboors;

    for (int i = 0; i < v; i++) {
        visited.push_back(false);
    }

    Tree *bfsTree ;//= Tree::createTree(session, source->getNode());// needs to apply virtual methods in tree
    visited[source->getNode()] = true;
    neighboors.push(source);


    int counter = 0;
    while (!neighboors.empty()) {

        if (counter == 0) {
            source = neighboors.front();
            neighboors.pop();

            for (int i = 0; i < v; i++) {

                if (!(visited[i]) && edges[source->getNode()][i] == 1) {

                    visited[i] = true;
                    Tree *temp = Tree::createTree(session, i);
                    neighboors.push(temp);
                    source->addChild(*temp);

                }

            }
            bfsTree=source;
        }
        else {
            for (int k = 0; k < bfsTree->getChildren().size(); k++) {
                source = neighboors.front();
                neighboors.pop();

                for (int i = 0; i < v; i++) {

                    if (!(visited[i]) && edges[source->getNode()][i] == 1) {

                        visited[i] = true;
                        Tree *temp = Tree::createTree(session, i);
                        neighboors.push(temp);
                        source->addChild(*temp);


                    }

                }


                for (int m = 0; m < source->getChildren().size(); m++)
                    bfsTree->getChildren()[k]->addChild(*source->getChildren()[m]);
            }
        }

        counter++;
    }




    return bfsTree;
}

vector<int> Graph::getStatus()  {
    return status;
}

void Graph::setStatus(int node, int newStat) {
    status[node] = newStat;
}
