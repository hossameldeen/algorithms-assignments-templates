#ifndef CONNECTEDCOMPONENTS_H_
#define CONNECTEDCOMPONENTS_H_

#include "UndirectedGraph.h"
#include <bits/stdc++.h>
using namespace std;

// The function you'll write.
// You'll return nothing.
// Just `setComponentNumberOfNode` correctly for each node in G such that all nodes in the same component should have the same component number.
void marksComponentsOfNodes(UndirectedGraph &G) {

}


// Helper functions:

// DFSes from `startNode` and keeps setting component number of reachable nodes to be `componentNumber`.
// Note: If a `componentNumber` of a node has already been set, it doesn't pass through it. So, `startNode`'s component should be `NO_COMPONENT`.
void DFS(UndirectedGraph &G, int startNode, int componentNumber);



// Helper functions implementation:

void DFS(UndirectedGraph &G, int currentNode, int componentNumber) {
    if (G.isNodeInComponentYet(currentNode))
        return;

    G.setComponentNumberOfNode(currentNode, componentNumber);

    vector<int> neighbours = G.getNeighboursOf(currentNode);
    for (int i = 0; i < neighbours.size(); i++)
        DFS(G, neighbours[i], componentNumber);
}

#endif /* CONNECTEDCOMPONENTS_H_ */
