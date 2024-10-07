class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;  // sum-> number of occurances
        m[0] = 1;
        int totalSum = 0;
        int right = 0;
        
        /*
            at every iteration the subarray ends at right th index.
            How many subarrays can be formed which ends at this right th index satisfying the condition??
        */
        
        while(right < nums.size()){
            totalSum+=nums[right];
            if(m.find(totalSum - k)!=m.end()){
                ans+=m[totalSum - k];
            }
            m[totalSum]+=1;
            right+=1;
        }
        
        return ans;
    }
};