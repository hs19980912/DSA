#include <iostream>
#include <vector>

class Tree {
    int V; // Number of vertices (nodes)
    std::vector<std::vector<int>> adj; // Adjacency list
    std::vector<int> eulerTour; // Stores the Euler tour
    std::vector<int> firstOccurrence; // Stores the first occurrence of each node in the Euler tour
    std::vector<int> height; // Stores the height of each node

public:
    Tree(int V);
    void addEdge(int u, int v);
    void eulerTourDFS(int node, int h);
    void printEulerTour();
};

Tree::Tree(int V) : V(V), adj(V), firstOccurrence(V, -1), height(V) {}

void Tree::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Tree::eulerTourDFS(int node, int h) {
    // Record the current node in the Euler tour
    eulerTour.push_back(node);
    height[node] = h;

    // If it's the first occurrence of this node, record it
    if (firstOccurrence[node] == -1) {
        firstOccurrence[node] = eulerTour.size() - 1;
    }

    // Traverse the adjacent nodes (children)
    for (int v : adj[node]) {
        if (firstOccurrence[v] == -1) { // Check if the node has already been visited
            eulerTourDFS(v, h + 1);

            // After visiting a child, record the parent again (for backtracking)
            eulerTour.push_back(node);
        }
    }
}

void Tree::printEulerTour() {
    for (int node : eulerTour) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Create a tree with 7 nodes
    Tree tree(7);

    // Add edges
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(1, 3);
    tree.addEdge(1, 4);
    tree.addEdge(2, 5);
    tree.addEdge(2, 6);

    // Generate the Euler tour starting from the root node (0) with height 0
    tree.eulerTourDFS(0, 0);

    // Print the Euler tour
    tree.printEulerTour();

    return 0;
}

===============================================================================

Output:

For the tree in the example:
       0
      / \
     1   2
    / \ / \
   3  4 5  6


The output Euler tour would be:
0 1 3 1 4 1 0 2 5 2 6 2 0
