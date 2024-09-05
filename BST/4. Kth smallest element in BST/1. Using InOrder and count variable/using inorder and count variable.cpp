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
    int count;
    int n;
    int ans;
    bool found = false;

    void helper(TreeNode* curNode){
        if(curNode == nullptr)  return;

        helper(curNode->left);

        count+=1;

        if(count == n){
            ans = curNode->val;
            found = true;
            return;
        }
        
        if(!found)
            helper(curNode->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        n = k;
        count = 0;
        helper(root);
        return ans;
    }
};