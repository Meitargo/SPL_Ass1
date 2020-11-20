//
// Created by spl211 on 20/11/2020.
//

#ifndef ASS1_BFS_H
#define ASS1_BFS_H


class bfs {

};


#endif //ASS1_BFS_H
// ha bfs hamekori
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