// 219. Contains Duplicate II

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        k = k+1;
        if(k > nums.size()){
            for(int i=0; i<nums.size(); ++i){
                s.insert(nums[i]);
            }
            
            if(s.size()!=nums.size()){
                return true;    // There exists some duplicate
            }else{
                // All are unique elements
                return false;
            }
        }
        
        int l=0;
        int r=k-1;
        
        for(int i=0; i<k; ++i){
            s.insert(nums[i]);
        }
        
        while(r < nums.size()){
            // will analyze bw [l, r]
            // all the elements are already present in s;
            
            if(s.size()!=k){
                return true;
            }else{
                s.erase(nums[l]);
                if(r+1 < nums.size()){
                    s.insert(nums[r+1]);
                }
            }
            
            l+=1;
            r+=1;
        }
        
        return false;
    }
};