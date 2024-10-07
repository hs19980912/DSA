297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 
Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:
Input: root = []
Output: []

============================================================================================

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            TreeNode* curNode = q.front();
            q.pop();

            if(curNode!=nullptr){
                ans.push_back(curNode->val);
                q.push(curNode->left);
                q.push(curNode->right);
            }else{
                ans.push_back('#');
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s.size()==0){
            return nullptr;
        }

        TreeNode* root = new TreeNode(s[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while(i<s.size()){
            TreeNode* curNode = q.front();
            q.pop();

            // for left child of curNode
            if(s[i]!='#'){
                TreeNode* leftNode = new TreeNode(s[i]);
                curNode->left = leftNode;
                q.push(leftNode);
            }
            i+=1;

            if(s[i]!='#'){
                TreeNode* rightNode = new TreeNode(s[i]);
                curNode->right = rightNode;
                q.push(rightNode);
            }
            i+=1;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));