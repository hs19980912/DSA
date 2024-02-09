/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    int ans;
    
    int maxheight(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int leftAns = maxheight(root->left);
        int rightAns = maxheight(root->right);
        
        ans = max(ans, 1 + leftAns + rightAns);
        
        return 1 + max(leftAns, rightAns);
    }
    
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        ans = 0;
        maxheight(root);
        return ans;
    }
};
