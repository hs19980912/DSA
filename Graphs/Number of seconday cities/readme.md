## Problem: Find secondary cities

A country of hackerland can be represented as a tree of g_nodes, numbered from 1 to g_nodes where the ith edge represents a road that connects the cities g_from[i] and g_to[i].

A city is considered primary if it lies on the direct path between two cities, u and v, where the distance between u and v is the greatest amount all possible city pairs. All other cities are classified as secondary. Find the sum of indices of all the secondary cities.

Since it is a tree, number of edges will always g_nodes-1

```
Example 1:
g_nodes = 4
g_from = [1, 1, 2]
g_to = [2, 3, 4]

here there are 3 edges, 

Egde 1: 1 to 2
Edge 2: 1 to 3
Edge 3: 2 to 4

The maximum distance between any nodes is 3, from node 3 to node 4. All the cities on the path 3->1->2->4 are primary.
Hence there is no seconday city. Answer is 0.
```

```
Example 2:
g_nodes = 6
g_from = [1, 1, 1, 2, 3]
g_to = [2, 3, 4, 5, 6]

The maximum distance between any two nodes is 4, from node 5 to 6. The cities on the path are 5, 2, 1, 3, 6, these are our primary cities. Hence secondary city is node 4, hence the answer is 4.
```

```
Example 3:
g_nodes = 5
g_from = [1, 1, 2, 2]
g_to = [2, 3, 4, 5]
All the nodes, take any path from 2 leaf nodes, they are all of the same length 3. So no secondary city. Answer is 0.
```
Complete:
long function(int g_nodes, vector<int> g_from, vector<int> g_to)


## Solution

To find the sum of indices of all secondary cities, we first need to identify primary cities. A city is primary if it lies on any direct path that represents the diameter (greatest distance) of the tree.

The solution involves these main steps:

1.  **Tree Representation**: Build an adjacency list for the tree from `g_from` and `g_to`. Node indices are 1 to `g_nodes`.

2.  **Calculate Path Lengths (Dynamic Programming on Trees)**:
    We need three types of path lengths for each node `u`:
    * `dp_down1[u]`: The length of the longest path starting at `u` and going downwards into its subtree (formed during a DFS traversal).
    * `dp_down2[u]`: The length of the second longest path starting at `u` and going downwards into a *different* subtree branch than the one for `dp_down1[u]`.
    * `dp_up[u]`: The length of the longest path starting at `u`, going upwards to its parent, and then continuing away from `u`'s original subtree.

    These can be calculated using two DFS traversals:
    * **DFS1 (Post-order traversal, e.g., `dfs1_calc_down_paths(u, parent)`)**:
        * For each node `u`, initialize `dp_down1[u] = 0` and `dp_down2[u] = 0`. These values represent the length of the path starting *from* `u`.
        * Recursively call DFS1 for all children `v` of `u`.
        * After children calls return, consider paths from `u` through each child `v`. Such a path has length `1 + dp_down1[v]`.
        * Update `dp_down1[u]` with the largest such length found, and `dp_down2[u]` with the second largest.
        * Keep track of which child (`child1_node[u]`) led to `dp_down1[u]`; this is needed for DFS2.

    * **DFS2 (Pre-order traversal, e.g., `dfs2_calc_up_paths(u, parent)`)**:
        * For the root of the DFS, `dp_up[root] = 0`.
        * For any other node `u` with parent `p`:
            * One possibility for `dp_up[u]` is to go `u -> p` and then follow the `dp_up[p]` path from `p`. Length: `1 + dp_up[p]`.
            * Another possibility is to go `u -> p` and then down another branch from `p` (a sibling branch of `u`).
                * If `u` was the child that contributed to `dp_down1[p]` (i.e., `u == child1_node[p]`), then this path from `p` must use `p`'s second longest downward branch, `dp_down2[p]`. Length: `1 + dp_down2[p]`.
                * Otherwise, it can use `p`'s longest downward branch, `dp_down1[p]`. Length: `1 + dp_down1[p]`.
            * `dp_up[u]` is the maximum of these possibilities.
        * Recursively call DFS2 for children.

3.  **Determine the Diameter**:
    The diameter `D` of the tree is the maximum path length. It can be found by:
    `D = max(dp_down1[i] + dp_up[i])` for all nodes `i`.
    It can also be `D = max(dp_down1[i] + dp_down2[i])` for all nodes `i`.
    To be safe, the diameter is the maximum of all such computed values over all nodes `i`.

4.  **Identify Primary Cities**:
    A node `i` is primary if it lies on any diameter path. This condition is met if:
    * The path formed by `dp_down1[i]` (downwards from `i`) and `dp_up[i]` (upwards from `i` and away) has length equal to the diameter `D`. That is, `dp_down1[i] + dp_up[i] == D`.
    * OR, the path formed by `dp_down1[i]` and `dp_down2[i]` (two distinct downward branches from `i`) has length equal to `D`. That is, `dp_down1[i] + dp_down2[i] == D`.
    Any node satisfying either of these conditions is primary.

5.  **Sum Secondary City Indices**:
    Iterate through all nodes from 1 to `g_nodes`. If a node is not primary, add its index to a running sum. This sum is the final answer.

The overall time complexity will be O(g_nodes) because each DFS traversal visits each node and edge once. Space complexity will also be O(g_nodes) for adjacency lists and DP arrays.

```cpp
#include <vector>
#include <algorithm> // For std::max

// Namespace to hold tree-related variables and functions to avoid global pollution
namespace HackerLandTree {

std::vector<std::vector<int>> adj_list;
std::vector<int> dp_down1_vals; // Longest path downwards from u, starting at u
std::vector<int> dp_down2_vals; // Second longest path downwards from u, starting at u
std::vector<int> dp_up_vals;    // Longest path starting at u, going via parent, then away
std::vector<int> child1_node;   // Child node that forms the dp_down1_vals path for its parent

// DFS to compute dp_down1_vals and dp_down2_vals
void dfs1_calc_down_paths(int u, int p) {
    // Initialize path lengths starting from u to 0 (e.g., if u is a leaf)
    dp_down1_vals[u] = 0;
    dp_down2_vals[u] = 0;
    child1_node[u] = 0; // 0 indicates no child contributing yet or leaf

    for (int v : adj_list[u]) {
        if (v == p) continue;
        dfs1_calc_down_paths(v, u);
        
        // Length of path starting from u, going through v, then down from v
        int path_len_from_u_via_v = 1 + dp_down1_vals[v]; 

        if (path_len_from_u_via_v > dp_down1_vals[u]) {
            dp_down2_vals[u] = dp_down1_vals[u]; // Old best becomes second best
            dp_down1_vals[u] = path_len_from_u_via_v;
            child1_node[u] = v;
        } else if (path_len_from_u_via_v > dp_down2_vals[u]) {
            dp_down2_vals[u] = path_len_from_u_via_v;
        }
    }
}

// DFS to compute dp_up_vals
void dfs2_calc_up_paths(int u, int p) {
    if (p == 0) { // u is the root of this DFS traversal
        dp_up_vals[u] = 0;
    } else {
        // Option 1: Path goes u -> p -> then follows dp_up_vals[p] path from p
        int path_via_p_upwards = 1 + dp_up_vals[p];

        // Option 2: Path goes u -> p -> then downwards from p into a sibling branch of u
        int path_via_p_sideways;
        if (child1_node[p] == u) { 
            // If u was on the longest downward path from p (length dp_down1_vals[p]),
            // path from p must use its second longest downward branch (length dp_down2_vals[p]).
            path_via_p_sideways = 1 + dp_down2_vals[p];
        } else { 
            // u was not on p's longest downward path.
            // Path from p can use its longest downward branch (length dp_down1_vals[p]).
            path_via_p_sideways = 1 + dp_down1_vals[p];
        }
        dp_up_vals[u] = std::max(path_via_p_upwards, path_via_p_sideways);
    }

    for (int v : adj_list[u]) {
        if (v == p) continue;
        dfs2_calc_up_paths(v, u);
    }
}

} // namespace HackerLandTree


long function(int g_nodes, std::vector<int> g_from, std::vector<int> g_to) {
    if (g_nodes == 0) {
        return 0;
    }
    if (g_nodes == 1 && g_from.empty()) { // Single node is primary
        return 0;
    }

    HackerLandTree::adj_list.assign(g_nodes + 1, std::vector<int>());
    HackerLandTree::dp_down1_vals.assign(g_nodes + 1, 0);
    HackerLandTree::dp_down2_vals.assign(g_nodes + 1, 0);
    HackerLandTree::dp_up_vals.assign(g_nodes + 1, 0);
    HackerLandTree::child1_node.assign(g_nodes + 1, 0);

    for (size_t i = 0; i < g_from.size(); ++i) {
        HackerLandTree::adj_list[g_from[i]].push_back(g_to[i]);
        HackerLandTree::adj_list[g_to[i]].push_back(g_from[i]);
    }
    
    // Start DFS from node 1 (arbitrary root), with 0 as dummy parent
    HackerLandTree::dfs1_calc_down_paths(1, 0); 
    HackerLandTree::dfs2_calc_up_paths(1, 0);

    int diameter = 0;
    for (int i = 1; i <= g_nodes; ++i) {
        // Diameter can be formed by a path going down from i and up from i
        diameter = std::max(diameter, HackerLandTree::dp_down1_vals[i] + HackerLandTree::dp_up_vals[i]);
        // Diameter can also be formed by two distinct downward paths from i
        diameter = std::max(diameter, HackerLandTree::dp_down1_vals[i] + HackerLandTree::dp_down2_vals[i]);
    }

    long sum_of_secondary_indices = 0;
    for (int i = 1; i <= g_nodes; ++i) {
        bool is_node_primary = false;
        if ((HackerLandTree::dp_down1_vals[i] + HackerLandTree::dp_up_vals[i] == diameter) || 
            (HackerLandTree::dp_down1_vals[i] + HackerLandTree::dp_down2_vals[i] == diameter)) {
            is_node_primary = true;
        }
        
        if (!is_node_primary) {
            sum_of_secondary_indices += i;
        }
    }

    return sum_of_secondary_indices;
}

```