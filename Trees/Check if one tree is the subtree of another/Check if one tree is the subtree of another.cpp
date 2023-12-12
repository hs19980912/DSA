/*
iven the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

572. Subtree of Another Tree
GFG. Check if subtree

*/

class Solution {
public:
    
    bool are_same(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr || subRoot==nullptr){
            return root == subRoot;
        }
        
        if(root->val != subRoot->val)
            return false;
        
        bool leftAns = are_same(root->left, subRoot->left);
        bool rightAns = are_same(root->right, subRoot->right);
        
        return leftAns && rightAns;
    }
    
    bool helper(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr || subRoot==nullptr){
            return root == subRoot;
        }
        
        if(root->val == subRoot->val){
            bool same = are_same(root, subRoot);
            if(same == true){
                return true;
            }
        }
        
        bool leftAns = helper(root->left, subRoot);
        if(leftAns == true) return true;
        
        bool rightAns = helper(root->right, subRoot);
        if(rightAns == true) return true;
        
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root, subRoot);
    }
};