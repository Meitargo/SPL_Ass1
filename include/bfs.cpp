//
// Created by spl211 on 20/11/2020.
//

#include "bfs.h"
#include "Tree.h"
#include "Session.h"

using namespace std;
//q.push(source)
//visited=
Tree * Graph::bfs(Session session, Tree *bfstree,queue<int> q,vector<bool> discoverd) {
    if(q.empty())
        return;
    int v=q.front();
    q.pop();

    Tree *tmp=Tree::createTree(session,v);

    for(int u:edges[v]){
        if(!discoverd[u]){
            discoverd[u]=true;
            q.push(u);
            tmp->addChild(*Tree::createTree(session,u));
        }
    }


    bfs(session,tmp,q,discoverd);

};
