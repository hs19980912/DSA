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
 ***** LC: 687. Longest Univalue Path
 */
class Solution {
public:
    int length;
    
    int same_value(TreeNode* root, int value){
        if(root == nullptr) return 0;
        
        if(root->val == value){
            int leftAns = same_value(root->left);
            int rightAns = same_value(root->right);

            length = max(length, 1 + leftAns + rightAns);

            return 1 + max(leftAns, rightAns);
        }
        
        return 0;
    }
    
    void dfs(TreeNode* root){
        if(root == nullptr) return;
        
        length = max(length, same_value(root, root->val));
        
        dfs(root->left);
        dfs(root->right);
        
        return;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        length=0;
        
        dfs(root);  // this sets length(for non zero answers) as the number of nodes.
        
        return length==0 ? 0 : length-1;
    }
};