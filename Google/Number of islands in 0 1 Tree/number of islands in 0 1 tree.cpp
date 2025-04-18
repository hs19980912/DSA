link:
https://leetcode.com/discuss/post/4580178/google-phone-screen-by-anonymous_user-fghs/
https://leetcode.com/discuss/post/6275124/google-phone-screen-number-of-islands-in-lan4/


Given a Binary tree having nodes with value 0 and 1. write a function to return the number of islands ?

Follow Up Questions-

Return the sizes of unique islands

===========================================================
the number of islands code:

int count;

void numIslands(TreeNode* curNode, int pre=0){
    if(curNode == nullptr){
        return;
    }

    if(curNode->val == 1 && pre==0){
        // this is a root from where an island begins
        count+=1;
    }

    numIslands(curNode->left, curNode->val);
    numIslands(curNode->right, curNode->val);

    return;
}

===============================================================
Sizes of unique islands

vector<int> sizes;

/*
it returns the size taking curNode as root if it is 1
*/
int numIslands(TreeNode* curNode, int pre=0){
    if(curNode==nullptr){
        return 0;
    }

    int leftAns = numIslands(curNode->left, curNode->val);
    int rightAns = numIslands(curNode->right, curNode->val);

    int ans=0;

    if(curNode->val == 1 && pre == 0){
        ans+=(1 + leftAns + rightAns);
        sizes.push_back(ans);
    }
    else if(curNode->val==1 && pre==1){
        ans+=(1 + leftAns + rightAns);
    }
    else{
        ans = 0;
    }

    return ans;
}