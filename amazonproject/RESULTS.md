# RESULTS

## THE DATASET
For our project, we chose a dataset from the Stanford Large Network Dataset collection to process. The dataset was originally obtained from crawling the Amazon website using its ‘Customers Who Bought This Item Also Bought’ feature. If a product B appears on the “frequently bought together” section of some product A, there will be a directed edge from A pointing at B.
	
## DFS
The three algorithms we ran on our chosen dataset were depth-first search, Dijkstra’s algorithm, and PageRank. The first algorithm, DFS, chooses an arbitrary root node and proceeds from there to traverse the whole graph to search all of its vertices and backtrack if necessary. The original dataset contains 262111 nodes, and we chose a subset of 1000 nodes from it to run DFS on. The algorithm traverses the whole graph in a depth-first manner and prints all of the nodes it visits into a text file in order.
	
## DIJKSTRA
The next algorithm we implemented is Dijkstra’s algorithm, which is mainly used to find the shortest possible path from a specified source to a destination. The algorithm finds all the distances from a specified source to every other node in the graph. We found that from the subset of 1000 nodes we selected from the original dataset, a majority of products are accessible to each other. The program prints the maximum unsigned integer (4294967295) to show the user which nodes are unreachable from the specified node. From here we can assume that most of the products the dataset contains have some form of relevancy to each other, with only a few being inaccessible from certain other products. Though this particular dataset does not include the specific products the nodes refer to (vertex names are given as numbers), this algorithm would come in handy to see just which products are connected to each other in some way.

## PAGERANK
Finally, we implemented and ran PageRank on the dataset. PageRank is generally used to identify the pages that are most relevant to a given enquiry. On the Amazon website’s dataset, this means that we can use the algorithm to determine the products that are most popular. It would be reasonable to classify a product popular/important if it is bought with lots of other items, and if those items are popular/important themselves. The pagerank algorithm accomplishes exactly this. By running it on our subset of nodes, we discovered that while a lot of products or nodes are connected to each other, there are only a few that are substantially more popular than others, with most nodes having close values. For example, running the algorithm with 10 iterations would give us a lot of nodes with a probability value of less than 0.005 while only a few have probabilities above 0.01. Thus, it can be assumed from our results that most items are bought alongside with a constant number of other items, with only a few exceptions.