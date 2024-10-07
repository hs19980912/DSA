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

	void pushAllLeft(TreeNode* root, stack<TreeNode*>& s){
		if(root == nullptr)	return;

		s.push(root);

		return pushAllLeft(root->left, s);
	}

    int kthSmallest(TreeNode* root, int k) {
        int ans;
        stack<TreeNode*> s;
        pushAllLeft(root, s);
        for(int i=0; i<k; ++i){
        	TreeNode* curNode = s.top();
        	// this s.top is the current minimum
            s.pop();
        	ans = curNode->val;
        	if(curNode->right!=nullptr){
        		pushAllLeft(curNode->right, s);
        	}
        }

        return ans;
    }
};