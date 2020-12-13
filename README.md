#### Irfan Demetoglu - Neha Matthew - Dhea Ong - Onat Akca

<br>

### **Motivation**
This project analyses the Amazon Product Co-Purchasing Network. It is based on the _Customers Who Bought This Item Also Bought_ feature of the Amazon website. If a product B appears on the “frequently bought together” section of some product A, there will be a directed edge from A pointing at B. We chose this particular dataset to implement algorithms that help us better understand the relationship between products on Amazon. 

<br>

### **Features**
This project builds a directed unweighted graph from a given dataset. The dataset must be provided as two text files that contain lists of nodes and edges respectively. The nodes must have unique labels and must be formatted as one node label per line. The edges text file must be formatted as "_sourcevertexlabel_    _destinationvertexlabel_" with one edge per line. This project can run three algorithms on the graph: 

#### 1. DFS 
Runs a Depth First Search on the entire dataset.


#### 2. Dijkstra’s Algorithm 
Implements Dijkstra’s algorithm to find the shortest distances between the chosen vertex and all others. 


#### 3. PageRank 
Performs a page rank on the dataset to assign a "popularity value" between 0 and 1 (ie. a probability value) to each vertex.

<br>

### **Building the Project**
To build the project use the following command.
``` 
make  
```

This generates an executable named _main_. It is run with 4 command line arguments. The first three are required and the fourth is optional.
- The first argument is the text file containing the list of nodes. Enter the complete path of the text file in the correct format or enter _d_ to use the default file that contains data for the chosen dataset - the Amazon Product Co-Purchasing Network.
- The second argument is the text file containing the list of edges. Enter the complete path of the text file in the correct format or enter _d_ to use the default file that contains data for the chosen dataset - the Amazon Product Co-Purchasing Network. Please supply both files if the default is not being used. 
- The third argument decides which algorithm to run. Enter _dfs_ to run a depth first search, _dij_ to run dijkstra's algorithm and _pr_ to perform a pagerank.
- The fourth argument is used to tailor either dijkstra's algorithm or pagerank. While running the executable with _dij_, use this argument to enter the label of the vertex to start from. By default, it starts at the first vertex as stored by the graph class. While running the executable with _pr_, use this argument to enter the number of iterations. The default value is 10.

The following will run a dfs on the default dataset.
```
./main d d dfs
```

The following will run dijkstra's algorithm on the default dataset starting at node 12.
```
./main d d dij 12
```

The following will run a page rank on the default dataset with 10 iterations.
```
./main d d pr
```

The following will run dijkstra's algorithm on a custom dataset starting at a node present in the dataset with label _Google_.
```
./main tests/dataset_small_nodes.txt tests/dataset_small_edges.txt dij Google
```

### **Testing**
The tests are divided into 4 parts. 
- [part=1] contains tests for the graph class.
- [part=2] contains tests for the dfs algorithm.
- [part=3] contains tests for dijkstra's algorithm.
- [part=4] contains tests for the pagerank algorithm.

To run the tests for this project, use the following command.
```
make test
```
This generates an executable named _test_.

This executable can be run on individual parts - 
```
./test [part=1]
```
or on all tests at once -
```
./test
```


