### Cycle in directed Graph

1.  Depth-First Search (DFS) with Color Marking
2.  Kahn's Algorithm (Topological Sort Based)
3.  Detecting Back Edges (DFS Variation)
--

#### 1. Depth-First Search with Color marking
*Position of visited[curNode] = true is VERY CRUCIAL.*  
*It should be placed after the dfs recursion is complete in isCycle().*

```cpp
bool isCycle(int curNode, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& curVisited){
    if(curVisited[curNode] == true){
        return true;
    }

    curVisited[curNode] = true;

    for(int i=0; i<visited.size(); ++i){
        if(adj[curNode][i] == 1 && visited[i]==false){
            bool cycleDetect = isCycle(i, adj, visited, curVisited);
            if(cycleDetect == true){
                return true;
            }
        }
    }

    visited[curNode] = true;
    curVisited[curNode] = false;
    return false;
}

bool findCycleInDirectedGraph(int numCourses, vector<vector<int>>& prereq) {
    vector<vector<int>> adj(numCourses, vector<int>(numCourses, 0));
    for(int i=0; i<prereq.size(); ++i){
        adj[prereq[i][0]][prereq[i][1]] = 1;
    }

    vector<bool> visited(numCourses, false);
    vector<bool> curVisited(numCourses, false);
    for(int i=0; i<numCourses; ++i){
        if(visited[i] == false){
            bool cycleExists = isCycle(i, adj, visited, curVisited);
            if(cycleExists){
                return true;
            }
        }
    }

    return false;
}
```