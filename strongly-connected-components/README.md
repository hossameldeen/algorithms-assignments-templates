# Strongly-Connected Components (Kosaraju)

**Goal**: Learning how to break a complex algorithm into small steps. Each function you'll write or I already wrote is only a few lines of code.

## Representation

Same as connected-components problem.

## Input/Output

Same as connected-components problem but on a directed graph instead.

Check the 2 pictures for an example.

## Files

- **Kosaraju.h**: The only place you'll need to write code. You should complete a few functions there.
- **KosarajuHelperFunctions.h**: Some helper functions I'm giving you.
- **DirectedGraph.h**: A class for representing graphs. Also, you can use it to label the nodes with their component numbers.
- **ExampleUsage.h**: Shows example on (1) how to use `DirectedGraph`, (2) what your code should do, and (2) how to use the helper functions.
- **kosarajuInputExample.txt**: An example input. Same example used in *ExampleUsage.h*
- **KosarjuExampleGraph.png**: Picture of the graph used in the above example.
- **ComponentsOfKosarjuExampleGraph.png**: These are the correct components of the example graph. Feel free to give them any component numbers as long as all nodes in the same component have the same component number.
- **main.cpp**: Calls the *exampleUsage()* function. Also, takes input from *inputExample.txt*, calls your code and prints the output.
