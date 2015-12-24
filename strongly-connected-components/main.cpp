#include "DirectedGraph.h"
#include "Kosaraju.h"
#include "ExampleUsage.h"
#include <bits/stdc++.h>
using namespace std;

int main() {

    // Check this function for an example on how to use `DirectedGraph` and for what your code should do.
    directedGraphExampleUsage();

    // Check this function for an example on how to use Kosaraju Helper functions
    helperFunctionsExampleUsage();

    // Comment this line to take input from console.
    freopen("kosarajuInputExample.txt", "r", stdin);

    DirectedGraph G = inputGraph();

    Kosaraju(G);

    // If your code is correct, all nodes in the same component should have the same component number.
    // For now, since `Kosaraju(G)` does nothing, all nodes don't have a component yet.
    cout << "After running your code (which currently does nothing) on the input graph:" << endl;
    G.printComponentNumbersOfNodes();

    return 0;
}
