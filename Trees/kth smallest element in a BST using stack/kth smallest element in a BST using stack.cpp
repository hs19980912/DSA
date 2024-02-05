// 230. Kth Smallest Element in a BST

/*
     Here we are doing inorder traversal without recursion using stack.
IMP: We can also do reverse inorder traversal.
*/

class Solution {
public:

    void pushAllLeft(TreeNode* root, stack<TreeNode*>& s){
	if(root == nullptr)  return;
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
