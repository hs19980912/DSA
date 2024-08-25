239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.


Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]

===========================================================================

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans(nums.size()-k+1);
        int left = 0;
        int right = 0;

        deque<int> dq;

/*
        1. Remove any smaller element from deque
        2. Insert the element into the deque
        3. Slide the window to right
            a. remove left and increment left if needed
            b. increment right
*/
        
        while(right < nums.size()){
            // 1. Remove the smaller elements from dq
            while(dq.size()>0 && (nums[dq.front()]<=nums[right]) ){
                dq.pop_front();  
            }

            // 2. Insert the ele's index in dq
            dq.push_front(right);

            // 3.a. remove left and increment left if needed
            if(right-left+1 == k){
                while(dq.size() && dq.back()<left){
                    dq.pop_back();
                }
                ans[left] = (nums[dq.back()]);
                left+=1;
            }

            right+=1;

        }

        return ans;
    }
};