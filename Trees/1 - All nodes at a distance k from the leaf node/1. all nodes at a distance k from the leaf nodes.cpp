// GFG: https://practice.geeksforgeeks.org/problems/node-at-distance/1
//Node Structure
/*struct Node
{
    int k;
    Node *left, *right;
};*/


//Function to return count of nodes at a given distance from leaf nodes.
int count;
int distance;
unordered_set<Node*> s;

void dfs(Node* root, vector<Node*> curVec){
    if(root == NULL)    return 0;

    curVec.push_back(root);

    if(root->left == NULL && root->right == NULL){
        // We are at the leaf node
        if(curVec.size() >= distance + 1){
            s.insert(curVec[curVec.size() - 1 - distance]);
        }
        return;
    }

    dfs(root->left, curVec);
    dfs(root->right, curVec);

    return;
}

int printKDistantfromLeaf(Node* root, int k)
{
    //Add your code here. 
    count = 0;
    distance = k;
    s.erase();

    dfs(root, {});

    return s.size();
    
}