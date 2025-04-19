Given a node in a Binary Search Tree (BST), find the next largest (inorder successor) and next smallest (inorder predecessor) node. It is guaranteed that these nodes always exist (i.e the input node will never be the smallest or largest node in the BST).

The structure of every node is following:

struct Node {
    int value;
    Node* left_child;
    Node* right_child;
    Node* parent;
};
only the current Node is given to you as the input.

==========================================================

ALGORITHM:

Inorder Successor (Next Larger element)
- If the node has a right subtree, the successor is the leftmost node in the right subtree
- If there is no right subtree, we need to move up the tree until we find a parent whose left child is in our path

Inorder Predecessor (Next Smaller element)
- If the node has a left subtree, the predecessor is the rightmost node in the left subtree
- If there is no left subtree, we need to move up the tree until we find a parent whose right child is in our path

==========================================================

Way 1: 
Node* findSuccessor(Node* curNode){
    // first priority: find the succesor in the right side.
    Node* ans = nullptr
    if(curNode->right!=nullptr){
        ans = curNode->right;
        while(ans->left){
            ans = ans->left;
        }
    }
    else{
    // second priority: start finding the root till the parent->val < curNode
        ans = curNode->parent;
        while(ans->val < curNode->val){
            ans = ans->parent;
        }
    }

    return ans;
}

Way 2:
Node* findSuccessor(Node* curNode){
    // first priority: find the succesor in the right side.
    Node* ans = nullptr
    if(curNode->right!=nullptr){
        ans = curNode->right;
        while(ans->left){
            ans = ans->left;
        }
        return ans;
    }
    
    // second priority: When no right subtree, we need to move up the tree until we find a parent whose left child is in our path
    Node* successor  = curNode->parent;
    Node* pre = curNode;

    while(successor !=nullptr && successor ->right == pre){
        pre = successor ;
        successor  = successor ->parent;
    }
    return successor ;
}