Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.


Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

-----------------------------------------------------------------

Finding cycle detection directed graph

class Solution {
    public:
    
        // Cycle detection in a uni-directional graph
    
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
    
        bool canFinish(int numCourses, vector<vector<int>>& prereq) {
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
                        return false;
                    }
                }
            }
    
            // no cycle in the graph
            return true;
        }
    };