---
comments: true
difficulty: Hard
edit_url: https://github.com/doocs/leetcode/edit/main/solution/0800-0899/0815.Bus%20Routes/README_EN.md
tags:
    - Breadth-First Search
    - Array
    - Hash Table
---

<!-- problem:start -->

# [815. Bus Routes](https://leetcode.com/problems/bus-routes)
> **Similar:** Airport Package delivery

## Description

<!-- description:start -->

<p>You are given an array <code>routes</code> representing bus routes where <code>routes[i]</code> is a bus route that the <code>i<sup>th</sup></code> bus repeats forever.</p>

<ul>
	<li>For example, if <code>routes[0] = [1, 5, 7]</code>, this means that the <code>0<sup>th</sup></code> bus travels in the sequence <code>1 -&gt; 5 -&gt; 7 -&gt; 1 -&gt; 5 -&gt; 7 -&gt; 1 -&gt; ...</code> forever.</li>
</ul>

<p>You will start at the bus stop <code>source</code> (You are not on any bus initially), and you want to go to the bus stop <code>target</code>. You can travel between bus stops by buses only.</p>

<p>Return <em>the least number of buses you must take to travel from </em><code>source</code><em> to </em><code>target</code>. Return <code>-1</code> if it is not possible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> routes = [[1,2,7],[3,6,7]], source = 1, target = 6
<strong>Output:</strong> 2
<strong>Explanation:</strong> The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= routes.length &lt;= 500</code>.</li>
	<li><code>1 &lt;= routes[i].length &lt;= 10<sup>5</sup></code></li>
	<li>All the values of <code>routes[i]</code> are <strong>unique</strong>.</li>
	<li><code>sum(routes[i].length) &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= routes[i][j] &lt; 10<sup>6</sup></code></li>
	<li><code>0 &lt;= source, target &lt; 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: BFS

First, we check if $\textit{source}$ and $\textit{target}$ are the same. If they are, we directly return $0$.

Next, we use a hash table $\textit{g}$ to build a mapping from stops to bus routes. For each bus route, we traverse all the stops it passes through and map each stop to that bus route, i.e., $\textit{g}[\textit{stop}]$ represents all bus routes passing through stop $\textit{stop}$.

Then, we check if $\textit{source}$ and $\textit{target}$ are in the stop mapping. If they are not, we return $-1$.

We use a queue $\textit{q}$ to perform a breadth-first search (BFS). Each element in the queue is a tuple $(\textit{stop}, \textit{busCount})$, representing the current stop $\textit{stop}$ and the number of buses taken to reach the current stop $\textit{busCount}$.

We initialize a set $\textit{visRoute}$ to record the bus routes that have been visited and a set $\textit{visStop}$ to record the stops that have been visited. Then, we add $\textit{source}$ to $\textit{visStop}$ and $(\textit{source}, 0)$ to the queue $\textit{q}$.

Next, we start the BFS. While the queue $\textit{q}$ is not empty, we take out the first element from the queue, which is the current stop $\textit{stop}$ and the number of buses taken to reach the current stop $\textit{busCount}$.

If the current stop $\textit{stop}$ is the target stop $\textit{target}$, we return the number of buses taken to reach the target stop $\textit{busCount}$.

Otherwise, we traverse all bus routes passing through the current stop. For each bus route, we traverse all stops on that route. If a stop $\textit{nextStop}$ has not been visited, we add it to $\textit{visStop}$ and add $(\textit{nextStop}, \textit{busCount} + 1)$ to the queue $\textit{q}$.

Finally, if we cannot reach the target stop, we return $-1$.

The time complexity is $O(L)$, and the space complexity is $O(L)$, where $L$ is the total number of stops on all bus routes.

<!-- tabs:start -->

#### C++

```cpp
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> g;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                g[stop].push_back(i);
            }
        }

        if (!g.contains(source) || !g.contains(target)) {
            return -1;
        }

        queue<pair<int, int>> q;
        unordered_set<int> visRoute;
        unordered_set<int> visStop;
        q.push({source, 0});
        visStop.insert(source);

        while (!q.empty()) {
            auto [stop, busCount] = q.front();
            q.pop();

            if (stop == target) {
                return busCount;
            }

            for (int route : g[stop]) {
                if (!visRoute.contains(route)) {
                    for (int nextStop : routes[route]) {
                        if (!visStop.contains(nextStop)) {
                            visRoute.insert(route);
                            visStop.insert(nextStop);
                            q.push({nextStop, busCount + 1});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->