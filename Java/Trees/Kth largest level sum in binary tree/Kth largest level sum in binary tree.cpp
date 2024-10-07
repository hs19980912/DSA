// 2583. Kth Largest Sum in a Binary Tree

class Solution {
public:
    int maxLevel;
    long long int m[100001] = {0l};  
    
    void dfs(TreeNode* root, int curLevel){
        if(root == nullptr) return;
        
        m[curLevel]+=root->val;
        maxLevel = max(maxLevel, curLevel);
        
        curLevel+=1;
        
        dfs(root->left, curLevel);
        dfs(root->right, curLevel);
        
        return;
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        maxLevel = 0;
        dfs(root, 0);   // considering root at level 1
        
        if(maxLevel+1 < k)    return -1;
        
        sort(m, m+maxLevel +1 , greater<long long int>());  // VERY VERY IMPORTANT 
                                                            // using greater<long long int>
        
        return m[k-1];
        
    }
};