// 101. Symmetric Tree

// Here we use 2 stacks, one for the left half and one for the right half.
// left half one inserts the nodes from left to right fashion.
// right half one inserts the node in right to left fashion.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> leftQueue;
        queue<TreeNode*> rightQueue;
        
        leftQueue.push(root->left);
        rightQueue.push(root->right);
        
        while(leftQueue.size() && rightQueue.size()){
            TreeNode* l = leftQueue.front();
            TreeNode* r = rightQueue.front();
            leftQueue.pop();
            rightQueue.pop();
            if(l!=nullptr && r==nullptr){
                return false;
            }else if(l==nullptr && r!=nullptr){
                return false;
            }else if(l == nullptr && r==nullptr){
                continue;
            }
            
            if(l->val != r->val)    return false;
            
            leftQueue.push(l->left);
            leftQueue.push(l->right);
            
            rightQueue.push(r->right);
            rightQueue.push(r->left);
        }
        
        return true;
    }
};