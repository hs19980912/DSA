### Dijkstra's algorithm

#### What does it do?
-    It finds shortest paths from a single source node to all other reachable nodes in a weighted graph, provided that all edge weights are non-negative.
- It works on directed/undirected, Cyclic/Acyclic graphs.
- It has visited[node] concept.

#### Conditions required:
1. The weights of all the edges should be non-negative.

```cpp
// Class to represent a weighted graph
class Graph {
private:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list: (neighbor, weight)
    bool isDirected;

public:
    // Constructor
    Graph(int vertices, bool directed = false) : V(vertices), isDirected(directed) {
        adj.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
        
        // If the graph is undirected, add the edge in the opposite direction as well
        if (!isDirected) {
            adj[v].push_back(make_pair(u, weight));
        }
    }

    // Dijkstra's algorithm to find shortest paths from a source vertex
    vector<int> dijkstra(int src) {
        // Priority queue to store vertices that need to be processed
        // The priority queue is ordered by distance (min heap)
        // pair: (distance, vertex)
        priority_queue<pair<int, int>, 
                      vector<pair<int, int>>, 
                      greater<pair<int, int>>> pq;
        
        // Vector to store distances from src to all vertices
        vector<int> dist(V, numeric_limits<int>::max());
        
        // Vector to track if a vertex has been processed
        vector<bool> processed(V, false);
        
        // Vector to store the predecessor of each vertex in the shortest path
        vector<int> prev(V, -1);
        
        // Distance of source vertex from itself is always 0
        dist[src] = 0;
        
        // Insert source vertex into the priority queue
        pq.push(make_pair(0, src));
        
        // Process vertices
        while (!pq.empty()) {
            // Extract the vertex with the minimum distance
            int u = pq.top().second;
            pq.pop();
            
            // If this vertex has already been processed, skip it
            if (processed[u]) {
                continue;
            }
            
            // Mark vertex as processed
            processed[u] = true;
            
            // Update distances to adjacent vertices
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                // If there is a shorter path to v through u
                if (!processed[v] && dist[u] != numeric_limits<int>::max() 
                    && dist[u] + weight < dist[v]) {
                    // Update distance of v
                    dist[v] = dist[u] + weight;
                    // Update predecessor
                    prev[v] = u;
                    // Insert v into the priority queue
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        
        return dist;
    }
    
    // Function to find the shortest path from source to destination
    vector<int> getShortestPath(int src, int dest) {
        // Run Dijkstra's algorithm
        vector<int> dist = dijkstra(src);
        
        // If there's no path to the destination
        if (dist[dest] == numeric_limits<int>::max()) {
            return {};
        }
        
        // Reconstruct the path
        vector<int> path;
        int current = dest;
        
        // Store the distances for later reference
        vector<int> distances = dist;
        
        // Vector to store the predecessor of each vertex
        vector<int> prev(V, -1);
        
        // Recompute predecessors by running Dijkstra again (simplified for clarity)
        priority_queue<pair<int, int>, 
                     vector<pair<int, int>>, 
                     greater<pair<int, int>>> pq;
        
        dist.assign(V, numeric_limits<int>::max());
        dist[src] = 0;
        pq.push(make_pair(0, src));
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        
        // Reconstruct the path using the predecessor information
        for (current = dest; current != -1; current = prev[current]) {
            path.push_back(current);
        }
        
        // Reverse the path to get it from source to destination
        reverse(path.begin(), path.end());
        
        return path;
    }
    
    // Print the graph
    void printGraph() {
        cout << "Graph Structure:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": ";
            for (const auto& neighbor : adj[i]) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "UNDIRECTED GRAPH EXAMPLE" << endl;
    Graph undirectedGraph(6, false); // 6 vertices, undirected
    
    undirectedGraph.addEdge(0, 1, 2);
    undirectedGraph.addEdge(0, 2, 4);
    undirectedGraph.addEdge(1, 2, 1);
    undirectedGraph.addEdge(1, 3, 7);
    undirectedGraph.addEdge(2, 4, 3);
    undirectedGraph.addEdge(3, 4, 2);
    undirectedGraph.addEdge(3, 5, 1);
    undirectedGraph.addEdge(4, 5, 5);
    
    // Print the graph structure
    undirectedGraph.printGraph();
    
    // Source vertex
    int src = 0;
    
    // Find shortest distances
    vector<int> dist = undirectedGraph.dijkstra(src);
    
    // Print shortest distances
    cout << "\nShortest distances from vertex " << src << ":" << endl;
    for (int i = 0; i < dist.size(); ++i) {
        cout << "To vertex " << i << ": ";
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "Not reachable";
        } else {
            cout << dist[i];
        }
        cout << endl;
    }
    
    // Find shortest path from 0 to 5
    vector<int> path = undirectedGraph.getShortestPath(0, 5);
    cout << "\nShortest path from vertex 0 to vertex 5: ";
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << "\nTotal distance: " << dist[5] << endl;
    
    // Test with a directed graph with cycles
    cout << "\nDIRECTED CYCLIC GRAPH EXAMPLE" << endl;
    Graph directedGraph(6, true); // 6 vertices, directed
    
    directedGraph.addEdge(0, 1, 2);
    directedGraph.addEdge(0, 2, 4);
    directedGraph.addEdge(1, 2, 1);
    directedGraph.addEdge(1, 3, 7);
    directedGraph.addEdge(2, 4, 3);
    directedGraph.addEdge(3, 4, 2);
    directedGraph.addEdge(3, 5, 1);
    directedGraph.addEdge(4, 5, 5);
    directedGraph.addEdge(5, 0, 6); // Creating a cycle
    
    // Print the graph structure
    directedGraph.printGraph();
    
    // Find shortest distances for directed graph
    vector<int> directedDist = directedGraph.dijkstra(src);
    
    // Print shortest distances for directed graph
    cout << "\nShortest distances from vertex " << src << " in directed graph:" << endl;
    for (int i = 0; i < directedDist.size(); ++i) {
        cout << "To vertex " << i << ": ";
        if (directedDist[i] == numeric_limits<int>::max()) {
            cout << "Not reachable";
        } else {
            cout << directedDist[i];
        }
        cout << endl;
    }
    
    // Find shortest path from 0 to 5 in directed graph
    vector<int> directedPath = directedGraph.getShortestPath(0, 5);
    cout << "\nShortest path from vertex 0 to vertex 5 in directed graph: ";
    for (int vertex : directedPath) {
        cout << vertex << " ";
    }
    cout << "\nTotal distance: " << directedDist[5] << endl;
}
```