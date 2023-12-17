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
    unordered_map<int, unordered_set<int>> m;   // node -> {neighbours of that node}

    void dfs(TreeNode* root, TreeNode* parent){
        if(root == nullptr) return;

        if(parent!=nullptr){
            m[parent->val].insert(root->val);
            m[root->val].insert(parent->val);
        }

        dfs(root->left, root);
        dfs(root->right, root);

        return;
    }

    int amountOfTime(TreeNode* root, int start) {
        m.clear();
        dfs(root, nullptr);     // This prepares out unordered_map 'm'

        queue<int> q;
        unordered_set<int> visited;

        int ans = -1;

        q.push(start);
        visited.insert(start);

        int cur_time = 0;
        while(q.size()){
            // present 'cur_time' is being analyzed in this iteration
            int curSize = q.size();
            for(int i=0; i<curSize; ++i){
                int curNode = q.front();
                q.pop();
                auto it = m[curNode].begin();
                while(it!=m[curNode].end()){
                    if(visited.count(*it) == 0){
                        visited.insert(*it);
                        q.push(*it);
                    }
                    it++;
                }
            }

            if(q.size() == 0){
                ans = cur_time;
            }else{
                ++cur_time;
            }
        }

        return ans;
    }
};