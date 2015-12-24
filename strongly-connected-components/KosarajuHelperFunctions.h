#ifndef KOSARAJUHELPERFUNCTIONS_H_
#define KOSARAJUHELPERFUNCTIONS_H_

#include "DirectedGraph.h"
#include <bits/stdc++.h>
using namespace std;


// DFSes from `startNode` and keeps setting component number of reachable nodes to be `componentNumber`.
// Note: If a `componentNumber` of a node has already been set, it doesn't pass through it. So, `startNode`'s component should be `NO_COMPONENT`.
void DFS(DirectedGraph &G, int startNode, int componentNumber);

DirectedGraph inputGraph();

// Returns vector<pair<int, int> >. For every i, v[i].first is the node number and v[i].second is "the after-visit time" in DFS.
// The "after-visit" time set after all the children/successors of a node are set.
// Thus, nodes with the biggest "after-visit" time are source nodes.
vector<pair<int, int> > topologicalSort(DirectedGraph G);



//========================================================================================
// You do NOT need to read the implementation! Just know how to call the helper functions!
//========================================================================================


void DFS(DirectedGraph &G, int currentNode, int componentNumber) {
    if (G.isNodeInComponentYet(currentNode))
        return;

    G.setComponentNumberOfNode(currentNode, componentNumber);

    vector<int> successors = G.getSuccessorsOf(currentNode);
    for (int i = 0; i < successors.size(); i++)
        DFS(G, successors[i], componentNumber);
}


DirectedGraph inputGraph() {
    int N;
    cin >> N;

    DirectedGraph G(N);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G.setEdgeFromTo(u, v);
    }

    return G;
}


int t;
vector<bool> visited;
vector<pair<int, int> > afterVisitTime;
void topSortDFS(int node, DirectedGraph &G);
vector<pair<int, int> > topologicalSort(DirectedGraph G) {
    t = 0;
    visited.clear();
    visited.resize(G.getN(), false);

    afterVisitTime.clear();

    for (int i = 0; i < G.getN(); i++)
        topSortDFS(i, G);

    return afterVisitTime;
}

// Note: It doesn't edit the graph. Just takes it by reference for performance/optimization.
void topSortDFS(int node, DirectedGraph &G) {
    if (visited[node])
        return;
    visited[node] = true;
    vector<int> successors = G.getSuccessorsOf(node);
    for (int i = 0; i < successors.size(); i++)
        topSortDFS(successors[i], G);

    afterVisitTime.push_back(make_pair(node, t));
    t++;
}

#endif /* KOSARAJUHELPERFUNCTIONS_H_ */
