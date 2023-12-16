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
class Solution {
public:
    int max_sum;

    int dfs(TreeNode* root){
        if(root == nullptr) return 0;

        int leftAns = max(dfs(root->left), 0);   // We only consider if gain from any side is greater than zero
        int rightAns = max(dfs(root->right), 0);

        max_sum = max(max_sum, root->val + leftAns + rightAns );

        return root->val + max(leftAns, rightAns);
    }

    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        dfs(root);

        return max_sum;
    }
};