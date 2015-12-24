#ifndef EXAMPLEUSAGE_H_
#define EXAMPLEUSAGE_H_

#include "DirectedGraph.h"
#include "KosarajuHelperFunctions.h"
#include <bits/stdc++.h>
using namespace std;


void helperFunctionsExampleUsage() {

    cout << "Start of example. Check `helperFunctionsExampleUsage()` function" << endl << endl;

    // Creating a graph to work with

    int N = 14;

    DirectedGraph G(N);       // Creating a graph with 14 nodes.

    // Adding edges
    G.setEdgeFromTo(6, 5);
    G.setEdgeFromTo(5, 6);
    G.setEdgeFromTo(12, 7);
    G.setEdgeFromTo(7, 11);
    G.setEdgeFromTo(11, 12);
    G.setEdgeFromTo(11, 1);
    G.setEdgeFromTo(1, 12);
    G.setEdgeFromTo(6, 12);
    G.setEdgeFromTo(6, 3);
    G.setEdgeFromTo(3, 4);
    G.setEdgeFromTo(4, 13);
    G.setEdgeFromTo(13, 3);
    G.setEdgeFromTo(13, 2);
    G.setEdgeFromTo(11, 2);
    G.setEdgeFromTo(8, 9);
    G.setEdgeFromTo(10, 0);
    G.setEdgeFromTo(0, 10);

    cout << "You can find the graph I'm working with in strongly-connected-components/KosarjuExampleGraph.PNG" << endl;

    cout << "Trying out `topologicalSort` helper function" << endl;
    vector<pair<int, int> > afterVisitTime = topologicalSort(G);
    for (int i = 0; i < G.getN(); i++) {
        cout << "Current pair = (" << afterVisitTime[i].first << ", " << afterVisitTime[i].second << ")." << endl;
        cout << "So, node " << afterVisitTime[i].first << " all its successors/children were visited in time " << afterVisitTime[i].second << endl;
    }

    cout << endl << "For `DFS` and `inputGraph`, they're the same as in ConnectedComponentsProblem. But of course, on directed graph instead of undirected." << endl << endl;

    cout << "End of helper functions example" << endl << endl;
}


void directedGraphExampleUsage() {

    cout << "Start of example. Check `directedGraphExampleUsage()` function" << endl << endl;

    int N = 14;

    DirectedGraph G(N);       // Creating a graph with 14 nodes.
    cout << "Initially, the graph no edges" << endl;
    G.printGraphStructure();    // Initially, no edges

    // Adding edges
    G.setEdgeFromTo(6, 5);
    G.setEdgeFromTo(5, 6);
    G.setEdgeFromTo(12, 7);
    G.setEdgeFromTo(7, 11);
    G.setEdgeFromTo(11, 12);
    G.setEdgeFromTo(11, 1);
    G.setEdgeFromTo(1, 12);
    G.setEdgeFromTo(6, 12);
    G.setEdgeFromTo(6, 3);
    G.setEdgeFromTo(3, 4);
    G.setEdgeFromTo(4, 13);
    G.setEdgeFromTo(13, 3);
    G.setEdgeFromTo(13, 2);
    G.setEdgeFromTo(11, 2);
    G.setEdgeFromTo(8, 9);
    G.setEdgeFromTo(10, 0);
    G.setEdgeFromTo(0, 10);

    cout << "Graph after adding edges" << endl;
    G.printGraphStructure();            // Graph should match the picture `exampleGraph.png`
    cout << "Components' numbers of nodes. All initially in no component/not visited" << endl;
    G.printComponentNumbersOfNodes();   // All initially in no component/not visited.

    // This is an example of a correct solution. Note that there're other correct solutions.
    G.setComponentNumberOfNode(6, 0);
    G.setComponentNumberOfNode(5, 0);

    G.setComponentNumberOfNode(10, 1);
    G.setComponentNumberOfNode(0, 1);

    G.setComponentNumberOfNode(8, 2);

    G.setComponentNumberOfNode(4, 3);
    G.setComponentNumberOfNode(3, 3);
    G.setComponentNumberOfNode(13, 3);

    G.setComponentNumberOfNode(2, 4);

    G.setComponentNumberOfNode(9, 5);

    G.setComponentNumberOfNode(7, 6);
    G.setComponentNumberOfNode(12, 6);
    G.setComponentNumberOfNode(11, 6);
    G.setComponentNumberOfNode(1, 6);

    cout << "After setting components numbers correctly. That's what your code should do" << endl;
    G.printComponentNumbersOfNodes();   // Now, you'll find that all nodes of the same component have the same component number

    cout << "End of directed graph example" << endl << endl;
}


#endif /* EXAMPLEUSAGE_H_ */
