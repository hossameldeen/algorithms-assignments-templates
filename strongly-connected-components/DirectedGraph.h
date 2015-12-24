#ifndef DIRECTEDGRAPH_H_
#define DIRECTEDGRAPH_H_

#include <bits/stdc++.h>
using namespace std;


/**
 * A directed graph with N nodes numbered from 0 to N -1.
 */
class DirectedGraph {
public:
    DirectedGraph(int N);
    int getN();

    // Instead of dealing with `adjacency matrix` directly, use these following functions:
    void setEdgeFromTo(int u, int v);           // sets edge from Node u to Node v. Same as saying `adjMat[u][v] = true`
    bool isThereEdgeFromTo(int u, int v);       // Is there an edge from Node u to Node v?. Same as saying `adjMat[u][v]`
    vector<int> getSuccessorsOf(int u);         // Returns successors of Node u (i.e., nodes that Node u point to).


    // Component number Can be anything other than -1. "-1" indicates that node is not in a component yet.
    void setComponentNumberOfNode(int u, int componentNumber);
    int getComponentNumberOfNode(int u);        // Returns the component number or DirectedGraph.NO_COMPONENT if component hasn't been set yet.
    bool isNodeInComponentYet(int u);           // Tells you if you set the component number of a node or no.
                                                // You can also think of it as "visited" or not yet.
    static const int NO_COMPONENT = -1;         // A special value to indicate that the node has no component yet.


    // Helper functions for tracing/debugging
    void printGraphStructure();
    void printComponentNumbersOfNodes();

private:
    // private members are prefixed with "_"

    int _N;                                     // number of nodes
    vector<vector<bool> > _adjMat;              // adjacency matrix
    vector<int> _componentNumberOfNode;         // component number of node.
    void _makeSureNodeNumberIsValid(int u);     // To help catch bugs. All nodes must be from 0 to N - 1
};



//========================================================================================
// You do NOT need to read the implementation! Just know how to call the public functions!
//========================================================================================


DirectedGraph::DirectedGraph(int N) {
    assert(N >= 0);

    _N = N;

    // Initialize the adjacency matrix
    _adjMat.resize(_N);
    for (int i = 0; i < _N; i++)
        _adjMat[i].resize(_N, false);   // i.e., graph with no edges initially.

    // Initialize the component number of the nodes
    _componentNumberOfNode.resize(N, NO_COMPONENT);
}


int DirectedGraph::getN() {
    return _N;
}


void DirectedGraph::setEdgeFromTo(int u, int v) {
    _makeSureNodeNumberIsValid(u);
    _makeSureNodeNumberIsValid(v);

    _adjMat[u][v] = true;
}


bool DirectedGraph::isThereEdgeFromTo(int u, int v) {
    _makeSureNodeNumberIsValid(u);
    _makeSureNodeNumberIsValid(v);

    return _adjMat[u][v];
}


vector<int> DirectedGraph::getSuccessorsOf(int u) {
    _makeSureNodeNumberIsValid(u);

    vector<int> successors;
    for (int i = 0; i < _N; i++)
        if (_adjMat[u][i])
            successors.push_back(i);
    return successors;
}


void DirectedGraph::_makeSureNodeNumberIsValid(int u) {
    assert(u >= 0);
    assert(u <= _N - 1);
}


void DirectedGraph::setComponentNumberOfNode(int u, int componentNumber) {
    assert(componentNumber != NO_COMPONENT);

    _componentNumberOfNode[u] = componentNumber;
}


int DirectedGraph::getComponentNumberOfNode(int u) {
    return _componentNumberOfNode[u];
}


bool DirectedGraph::isNodeInComponentYet(int u) {
    if (_componentNumberOfNode[u] == NO_COMPONENT)
        return false;
    else
        return true;
}


void DirectedGraph::printGraphStructure() {
    cout << "Graph has " << _N << " nodes number from 0 to " << _N - 1 << endl;

    for (int i = 0; i < _N; i++) {
        cout << "Successors (i.e., neighbours in directed graph) of " << i << ":";
        for (int j = 0; j < _N; j++)
            if (_adjMat[i][j])
                cout << " " << j;
        cout << endl;
    }
    cout << "End of graph structure printing" << endl << endl;
}


void DirectedGraph::printComponentNumbersOfNodes() {
    cout << "Each node and its component:" << endl;

    for (int i = 0; i < _N; ++i) {
        cout << "Node " << i << " is in component " << _componentNumberOfNode[i];
        if (_componentNumberOfNode[i] == NO_COMPONENT)
            cout << " (i.e, its component hasn't been set)";
        cout << endl;
    }
    cout << "End of printing components' numbers" << endl << endl;
}

#endif /* DIRECTEDGRAPH_H_ */
