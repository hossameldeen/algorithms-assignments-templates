#include "ConnectedComponents.h"
#include "UndirectedGraph.h"
#include "ExampleUsage.h"
#include <bits/stdc++.h>
using namespace std;

int main() {

    // Check this function for an example on how to use `UndirectedGraph` and for what your code should do.
    // exampleUsage();

    // Comment this line to take input from console.
    freopen("inputExample.txt", "r", stdin);

    UndirectedGraph G = inputGraph();

    markComponentsOfNodes(G);

    // If you code is correct, all nodes in the same component should have the same component number.
    // For now, since `markComponentsOfNodes` does nothing, all nodes don't have a component yet.
    cout << "After running your code on the input:" << endl;
    G.printComponentNumbersOfNodes();

    return 0;
}
