class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        unordered_map<int, int> m;  // sum -> count till now
        m[0] = 1;
        int count = 0;
        int curSum = 0;
        
        for(int i=0; i<nums.size(); ++i){
            curSum+=nums[i];
            
            // Do we have a target - curSum already found??
            if(m.find(curSum - target)!=m.end()){
                count+=m[curSum - target];
            }
            
            m[curSum]++;
        }
        
        return count;
    }
};