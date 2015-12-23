/*
 * ExampleUsage.h
 *
 *  Created on: Dec 23, 2015
 *      Author: 7
 */

#ifndef EXAMPLEUSAGE_H_
#define EXAMPLEUSAGE_H_

#include "UndirectedGraph.h"
#include <bits/stdc++.h>
using namespace std;

void exampleUsage() {

    cout << "Start of example. Check `exampleUsage()` function" << endl << endl;

    int N = 12;

    UndirectedGraph G(N);       // Creating a graph with 12 nodes.
    cout << "Initially, the graph no edges" << endl;
    G.printGraphStructure();    // Initially, no edges

    // Adding edges
    G.setEdgeBetween(7, 2);
    G.setEdgeBetween(7, 10);
    G.setEdgeBetween(2, 10);
    G.setEdgeBetween(6, 4);
    G.setEdgeBetween(6, 5);
    G.setEdgeBetween(5, 4);
    G.setEdgeBetween(5, 11);
    G.setEdgeBetween(11, 4);
    G.setEdgeBetween(8, 9);
    G.setEdgeBetween(0, 8);
    G.setEdgeBetween(1, 9);

    cout << "Graph after adding edges" << endl;
    G.printGraphStructure();            // Graph should match the picture `exampleGraph.png`
    cout << "Components' numbers of nodes. All initially in no component/not visited" << endl;
    G.printComponentNumbersOfNodes();   // All initially in no component/not visited.

    // This is an example of a correct solution. Note that there're other correct solutions.
    G.setComponentNumberOfNode(7, 0);
    G.setComponentNumberOfNode(2, 0);
    G.setComponentNumberOfNode(10, 0);

    G.setComponentNumberOfNode(3, 1);

    G.setComponentNumberOfNode(0, 2);
    G.setComponentNumberOfNode(9, 2);
    G.setComponentNumberOfNode(8, 2);
    G.setComponentNumberOfNode(1, 2);

    G.setComponentNumberOfNode(6, 3);
    G.setComponentNumberOfNode(5, 3);
    G.setComponentNumberOfNode(4, 3);
    G.setComponentNumberOfNode(11, 3);

    cout << "After setting components numbers correctly. That's what your code should do" << endl;
    G.printComponentNumbersOfNodes();   // Now, you'll find that all nodes of the same component have the same component number

    cout << "End of example" << endl << endl;
}


#endif /* EXAMPLEUSAGE_H_ */
