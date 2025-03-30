1004. Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

=============================================================================

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m; 
        int i = 0;
        int j = 0;
        int ans = 0;
        int n = s.size();

        while(j<n){
            m[s[j]]+=1;
            while(m[s[j]]>1 && i<=j){
                m[s[i]]-=1;
                i+=1;
            }

            ans = max(j-i+1, ans);
            j+=1;
        }

        return ans;
    }

=============================================================================

    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        
        int left = 0;
        int right = 0;
        int zeros = 0;
        
        /*
        I have to include right, my window at any point in the loop WILL end at right.
        Now, what shall I do to make the window valid.
        */
        
        while(right<nums.size()){
            int curNum = nums[right];
            if(curNum == 1){
                // Do nothing
            }else{
                // curNum is 0
                if(zeros+1 <= k){
                    zeros+=1;
                }else{
                    while(left<right && nums[left]==1){
                        left+=1;
                    }
                    left+=1;
                }
            }
            
            ans = max(ans, right-left+1);
            right+=1;
        }
        
        return ans;
    }