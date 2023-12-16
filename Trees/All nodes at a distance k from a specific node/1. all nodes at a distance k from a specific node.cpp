/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

    LC: 863. All Nodes Distance K in Binary Tree

    WHY is it good??:   This question teachs the concept of making a graph
                        from a binary tree using a simple dfs traversal. 
*/

class Solution {
public:
    unordered_map<int, unordered_set<int>> m;   // node -> neighbours

    void dfs(TreeNode* root, TreeNode* parent){
        if(root == NULL)    return;

        if(parent!=NULL){
            m[parent->val].insert(root->val);
            m[root->val].insert(parent->val);
        }

        dfs(root->left, root);
        dfs(root->right, root);

        return;

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // This dfs call will help in converting the tree into a graph
        // unordered_map 'm' work as a sort of adjacency matrix.
        dfs(root, NULL);    

        vector<int> finalAns;
        vector<int> aux;

        queue<int> q;
        unordered_set<int> visited;
        q.push(target->val);
        visited.insert(target->val);
        
        

        for(int i=0; i<=k; ++i){
            int curSize = q.size();
            for(int j=0; j<curSize; ++j){
                int curRoot = q.front();
                q.pop();
                aux.push_back(curRoot);

                auto it = m[curRoot].begin();
                while(it!=m[curRoot].end()){
                    if(visited.count(*it) == 0){
                        visited.insert(*it);
                        q.push(*it);
                    }
                    it++;
                }
            }

            if(i == k){
                finalAns = aux;
            }
            aux.clear();
        }

        return finalAns;
    }
};