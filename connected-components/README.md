# Connected Components

**Goal**: To make writing Strongly-Connected Components easier.

**Assumption**: Students have already written DFS, so I'm writing it for them.

## Representation

The graph has **N** nodes named/numbered from **0** to **N - 1**.
Beside node number/name, each node has a *component number* with it. A *component number* is like a name for a component. So, all nodes in the same component should have the same *component number*.

You can set *component number* of a node by using the function **UndirectedGraph::setComponentNumberOfNode(int u, int componentNumber)**. Check **ExampleUsage.h** for more.

Also, initially, component number of all nodes is -1 indicating that they're not in a component yet.

**Hint**: You can use component number as a visited/explored array. If a node is not in a component yet (i.e., its component number is -1), it's not visited yet.

## Input/Output

The input to your code/function will be an undirected graph. The output should be the same graph after component numbers of nodes have been set.
Component numbers must be set such that all nodes in the same component have the same component number.

Check the 2 pictures for an example.

## Files

- **ConnectedComponents.h**: The only place you'll need to write code. You should complete a function there.
- **UndirectedGraph.h**: A class for representing graphs. Also, you can use it to label the nodes with their component numbers.
- **ExampleUsage.h**: To show you an example usage of *UndirectedGraph* class and how to set the component number of each node. Also, shows you what your code should do to the graph. Call it and check the output.
- **inputExample.txt**: An example input. Same example used in *ExampleUsage.h*
- **exampleGraph.png**: Picture of the graph used in the above example.
- **exampleGraphAfterSettingComponentNumbers.png**: After setting component numbers. This is an example of how your code should set the component numbers of the nodes.
- **main.cpp**: Calls the *exampleUsage()* function. Also, takes input from *inputExample.txt*, calls your code and prints the output.
