#ifndef KOSARAJU_H_
#define KOSARAJU_H_

#include "DirectedGraph.h"
#include "KosarajuHelperFunctions.h"
#include <bits/stdc++.h>
using namespace std;


void Kosaraju(DirectedGraph &G);
DirectedGraph getReversedGraph(DirectedGraph G);
vector<int> getNodeOrder(DirectedGraph G);
void markComponentsOfNodes(DirectedGraph &G, vector<int> visitOrder);


// Here, you'll fill/complete the functions' code.

// You'll return nothing.
// Just `setComponentNumberOfNode` correctly for each node in G such that all nodes in the same component should have the same component number.
// Note: With the code I've written in the function, you don't need to add/edit anything. But feel free to add/edit if you want.
void Kosaraju(DirectedGraph &G) {

    // 1. Get the reversed graph
    DirectedGraph reversedGraph = getReversedGraph(G);

    // 2. Get the order you should visit the nodes in from the reversed graph
    vector<int> order_I_Should_DFS_On_Nodes_With = getNodeOrder(reversedGraph);

    // 3. Visit/DFS on all the nodes in the ORIGINAL graph, much like in `ConnectedComponents`, but this time with the order gotten from getNodeOrder
    markComponentsOfNodes(G, order_I_Should_DFS_On_Nodes_With);
}


// Note: Since the graph is passed by value, it does NOT edit the original graph (which is what we want).
DirectedGraph getReversedGraph(DirectedGraph G) {
    return DirectedGraph(0); // i.e., just returns a dummy thing temporarily.
}


vector<int> getNodeOrder(DirectedGraph G) {

    // Hint: You'll probably want to use the helper function 'topologicalSort' here.
    // Another hint: You may want to use a `sort` on pair similar to in assignment-1. Ask me whenever you're stuck!

    return vector<int>(); // i.e., just returns a dummy thing temporarily.
}


void markComponentsOfNodes(DirectedGraph &G, vector<int> visitOrder) {

}

#endif /* KOSARAJU_H_ */
