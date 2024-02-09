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
    int diameter;

    int dfs(TreeNode* root){
        if(root == nullptr) return 0;

        int leftAns = dfs(root->left);
        int rightAns = dfs(root->right);

        diameter = max(diameter, 1 + leftAns + rightAns);

        return 1 + max(leftAns, rightAns);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        dfs(root);
        return diameter == 0 ? 0 : diameter - 1;    
    }
};