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
    int target;

    void path_sum(TreeNode* root, long long int curSum, unordered_map<long long int, int>& m){
        if(root == nullptr) return;

        curSum += root->val;
        if(m.find(curSum - target)!=m.end()){
            count+=m[curSum - target];
        }

        m[curSum]++;

        path_sum(root->left, curSum, m);
        path_sum(root->right, curSum ,m);
        
        m[curSum]--;
        
        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        target = targetSum;
        unordered_map<long long int, int> m;  // preFix sum -> count of that preFix sum found till now.
        m[0] = 1;
        path_sum(root, 0l, m);

        return count;
    }
};