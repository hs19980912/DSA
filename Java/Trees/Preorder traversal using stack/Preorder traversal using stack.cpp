/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

Added an example to elaborate how stack works in the preorder traversal.
Let's have a tree like below:

          1
     /        \
   2            3
 /   \         /   \
4     5       6     7
The right preorder sequence will be:

1  2  4  5  3  6  7
From the code we use a stack to simulate the process:

we push 1 to the stack.
we pop 1 out, add 1 into result; Add the children of 1 into stack. The value in the stack will be 3, 2 and 2 at the top position;
we pop 2 out and add it to result; Then we add children of 2 into stack. So the stack will be like 3, 5, 4 and with 4 at the top.
we pop 4 and 5 out of stack since they are leaf node. Currently result will be like 1, 2, 4, 5.
we pop 3 out and add its children into stack. The stack is like 7, 6 with 6 at the top.
we pop 6 and 7 out and the stack becomes empty.
So the final result will be 1, 2, 4, 5, 3, 6, 7

*/


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> arr;
        stack<Node*> s;
        
        if(root == nullptr) return arr;
        
        s.push(root);
        
        while(s.size()>0){    
            Node* curNode = s.top();
            s.pop();
            arr.push_back(curNode->val);
            for(int i=curNode->children.size()-1; i>=0; --i){
                s.push(curNode->children[i]);
            }
        }
        
        return arr;
    }
};