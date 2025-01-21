## Subarray sum equals to K

```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;  // sum -> count till now
    m[0] = 1;
    int count = 0;
    int curSum = 0;
    
    for(int i=0; i<nums.size(); ++i){
        curSum+=nums[i];
        
        // Do we have (k - curSum) already found??
        if(m.find(curSum - k)!=m.end()){
            count+=m[curSum - k];
        }
        
        m[curSum]++;
    }
    
    return count;
}
```