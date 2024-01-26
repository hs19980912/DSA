 ### pattern - Interesting DFS application
```cpp
    returns pair< bool found, int distance>
        2 Cases:
            1.found == true
              distance = distance from the target node.
            2.found == false
              distance = max depth from the curRoot
        
    Plus: in every call, UPDATE the GOLBAL variable ans. 
```

 1. Nodes at a distance k from a given node.
 2. Time Taken to infect the complete Binary Tree.
 
 