#ifndef UNDIRECTEDGRAPH_H_
#define UNDIRECTEDGRAPH_H_

#include <bits/stdc++.h>
using namespace std;


/**
 * An undirected graph with N nodes numbered from 0 to N -1.
 */
class UndirectedGraph {
public:
    UndirectedGraph(int N);
    int getN();

    // Instead of dealing with `adjacency matrix` directly, use these following functions:
    void setEdgeBetween(int u, int v);			// sets edge between Node u and Node v.
    bool isThereEdgeBetween(int u, int v);	    // Is there an edge between Node u and Node v?. Same as saying `adjMat[u][v]`
    vector<int> getNeighboursOf(int u);	        // Returns neighbours of Node u.


    // Component number Can be anything other than -1. "-1" indicates that node is not in a component yet.
    void setComponentNumberOfNode(int u, int componentNumber);
    int getComponentNumberOfNode(int u);        // Returns the component number or UndirectedGraph.NO_COMPONENT if component hasn't been set yet.
    bool isNodeInComponentYet(int u);           // Tells you if you set the component number of a node or no.
                                                // You can also think of it as "visited" or not yet.
    static const int NO_COMPONENT = -1;         // A special value to indicate that the node has no component yet.


    // Helper functions for tracing/debugging
    void printGraphStructure();
    void printComponentNumbersOfNodes();

private:
    // private members are prefixed with "_"

    int _N;							            // number of nodes
    vector<vector<bool> > _adjMat;	            // adjacency matrix
    vector<int> _componentNumberOfNode;         // component number of node.
    void _makeSureNodeNumberIsValid(int u);     // To help catch bugs. All nodes must be from 0 to N - 1
};



UndirectedGraph::UndirectedGraph(int N) {
    assert(N >= 0);

    _N = N;

    // Initialize the adjacency matrix
    _adjMat.resize(_N);
    for (int i = 0; i < _N; i++)
        _adjMat[i].resize(_N, false);	// i.e., graph with no edges initially.

    // Initialize the component number of the nodes
    _componentNumberOfNode.resize(N, NO_COMPONENT);
}


int UndirectedGraph::getN() {
    return _N;
}


void UndirectedGraph::setEdgeBetween(int u, int v) {
    _makeSureNodeNumberIsValid(u);
    _makeSureNodeNumberIsValid(v);

    _adjMat[u][v] = true;
    _adjMat[v][u] = true;	// since it's an undirected graph
}


bool UndirectedGraph::isThereEdgeBetween(int u, int v) {
    _makeSureNodeNumberIsValid(u);
    _makeSureNodeNumberIsValid(v);

    return _adjMat[u][v];
}


vector<int> UndirectedGraph::getNeighboursOf(int u) {
    _makeSureNodeNumberIsValid(u);

    vector<int> neighbours;
    for (int i = 0; i < _N; i++)
        if (_adjMat[u][i])
            neighbours.push_back(i);
    return neighbours;
}


void UndirectedGraph::_makeSureNodeNumberIsValid(int u) {
    assert(u >= 0);
    assert(u <= _N - 1);
}


void UndirectedGraph::setComponentNumberOfNode(int u, int componentNumber) {
    assert(componentNumber != NO_COMPONENT);

    _componentNumberOfNode[u] = componentNumber;
}


int UndirectedGraph::getComponentNumberOfNode(int u) {
    return _componentNumberOfNode[u];
}


bool UndirectedGraph::isNodeInComponentYet(int u) {
    if (_componentNumberOfNode[u] == NO_COMPONENT)
        return false;
    else
        return true;
}


void UndirectedGraph::printGraphStructure() {
    cout << "Graph has " << _N << " nodes number from 0 to " << _N - 1 << endl;

    for (int i = 0; i < _N; i++) {
        cout << "Neighbours of " << i << ":";
        for (int j = 0; j < _N; j++)
            if (_adjMat[i][j])
                cout << " " << j;
        cout << endl;
    }
    cout << "End of graph structure printing" << endl << endl;
}


void UndirectedGraph::printComponentNumbersOfNodes() {
    cout << "Each node and its component:" << endl;

    for (int i = 0; i < _N; ++i) {
        cout << "Node " << i << " is in component " << _componentNumberOfNode[i];
        if (_componentNumberOfNode[i] == NO_COMPONENT)
            cout << " (i.e, its component hasn't been set)";
        cout << endl;
    }
    cout << "End of printing components' numbers" << endl << endl;
}

#endif /* UNDIRECTEDGRAPH_H_ */
