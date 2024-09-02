// https://www.codingninjas.com/studio/problems/maximum-path-sum-between-two-leaves_794950?leftPanelTabValue=PROBLEM


long long ans;
long long maxStartingFromThisRoot(TreeNode<int>* curRoot){
    if(curRoot == NULL){
        return 0;
    }

    long long leftAns = maxStartingFromThisRoot(curRoot->left);
    long long rightAns = maxStartingFromThisRoot(curRoot->right);

    long long curSum = curRoot->val;
    curSum+= leftAns;
    curSum+= rightAns;

    if(curRoot->left!=NULL && curRoot->right!=NULL)
        ans = max(ans, curSum);

    return curRoot->val + max(leftAns, rightAns);
}

long long int findMaxSumPath(TreeNode<int> *root)
{   
    ans = -1;
    maxStartingFromThisRoot(root);
    return ans;
}