Middle of the linked list
Given a singly linked list, the task is to find the middle of the linked list. If the number of nodes are even, then there would be two middle nodes, so return the second middle node.

Input: linked list: 1->2->3->4->5
Output: 3 
Explanation: There are 5 nodes in the linked list and there is one middle node whose value is 3.

Input: linked list = 10 -> 20 -> 30 -> 40 -> 50 -> 60
Output: 40
Explanation: There are 6 nodes in the linked list, so we have two middle nodes: 30 and 40, but we will return the second middle node which is 40.

[Expected Approach] By Tortoise and Hare Algorithm – O(n) time and O(1) space:
We can use the Hare and Tortoise Algorithm to find the middle of the linked list. Traverse linked list using a slow pointer (slow_ptr) and a fast pointer (fast_ptr ). Move the slow pointer to the next node(one node forward) and the fast pointer to the next of the next node(two nodes forward). When the fast pointer reaches the last node or NULL, then the slow pointer will reach the middle of the linked list.

In case of odd number of nodes in the linked list, slow_ptr will reach the middle node when fast_ptr will reach the last node and in case of even number of nodes in the linked list, slow_ptr will reach the middle node when fast_ptr will become NULL.

==================================================================

int getMiddle(Node* head) {
  
    // Initialize the slow and fast pointer to the head of
    // the linked list
    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    // Return the slow pointer which is currenlty pointing
    // to the middle node of the linked list
    return slow_ptr->data;
}