 ### pattern 1 - Interesting DFS application 
```cpp
pair<bool, int> helper(TreeNode* curNode, int target){
    if(curNode == nullptr){
        return {false, 0};
    }

    pair<bool, int> leftAns = helper(curNode->left, target);
    pair<bool, int> rightAns= helper(curNode->right, target);

    if(curNode->val == target){
        ans = max(ans, max(rightAns.second, leftAns.second));
        return {true, 1};
    }else{
        if(leftAns.first == false && rightAns.first == false){
            return {false, 1 + max(leftAns.second, rightAns.second)};
        }else{
            ans = max(ans, (rightAns.second + leftAns.second));
            return {true, 1+ (leftAns.first == true ? leftAns.second : rightAns.second) };
        }
    }

    return {false, 0};  // Arbitary result. Never used.
}
```
1. Nodes at a distance k from a given node.
2. Time Taken to infect the complete Binary Tree.
 
 ### pattern - Diameter of Tree
 1. Diameter of a Tree
 2. Maximum Path Sum
 ```cpp
    ************************* Maximum Path Sum *************************
    int ans;
    int maxSumStartingWithThisRoot(TreeNode* curRoot){
        if(curRoot == nullptr){
            return INT_MIN;
        }
        
        int leftAns  = max(maxSumStartingWithThisRoot(curRoot->left), 0);   // IMPORTANT
        int rightAns = max(maxSumStartingWithThisRoot(curRoot->right), 0);  // IMPORTANT
        
        ans = max(ans, curRoot->val + leftAns + rightAns);
        
        return curRoot->val + max(leftAns, rightAns);
    }
    
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxSumStartingWithThisRoot(root);
        return ans;
    }
```
