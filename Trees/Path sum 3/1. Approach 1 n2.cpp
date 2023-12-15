/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
    Here we follow an O(n2) approach,
    from each node, we do a dfs traversal and find all the 
    count where the sum from that node is equal to target.
    We do this for all the nodes.
*/

class Solution {
public:
    int count;
    int target;

    void sum_from_root(TreeNode* root, long long int curSum){
        if(root == nullptr) return;

        curSum += root->val;

        if(curSum == target){
            count+=1;
        }

        sum_from_root(root->left, curSum);
        sum_from_root(root->right, curSum);

        return;
    }

    void dfs(TreeNode* root){
        if(root == nullptr) return;

        // Path sum starting from root
        sum_from_root(root, 0l);

        dfs(root->left);
        dfs(root->right);

        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        target = targetSum;

        dfs(root);

        return count;
    }
};
