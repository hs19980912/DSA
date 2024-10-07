// 897. Increasing Order Search Tree
class Solution {
public:
    
    pair<TreeNode*, TreeNode*> BSTtoList(TreeNode* root){
        if(root == nullptr){
            return make_pair(nullptr, nullptr);
        }
        
        if(root->left == nullptr && root->right == nullptr){
            return make_pair(root, root);
        }
        
        pair<TreeNode*, TreeNode*> leftSide = BSTtoList(root->left);
        pair<TreeNode*, TreeNode*> rightSide = BSTtoList(root->right);
        
        TreeNode* leftAns;
        // setting left of ans
        if(leftSide.second == nullptr){
            leftAns = root;
        }else{
            leftAns = leftSide.first;
            leftSide.second->right = root;
            root->left = nullptr;       // *** IMPORTANT STEP ***
        }
        
        TreeNode* rightAns;
        // setting right of ans
        if(rightSide.first == nullptr){
            rightAns = root;
            root->right = nullptr;      // *** IMPORTANT STEP ***
        }else{
            rightAns = rightSide.second;
            root->right = rightSide.first;
        }
        
        return make_pair(leftAns, rightAns);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        pair<TreeNode*, TreeNode*> ans = BSTtoList(root);
        return ans.first;
    }
};