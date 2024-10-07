class Solution {
public:

    int findDays(vector<int>& weights, int curCap){
        int days = 1;
        int curSum = 0;
        for(int i=0; i<weights.size(); ++i){
            if(curSum + weights[i] <= curCap){
                curSum+=weights[i];
            }else{
                if(weights[i] > curCap){
                    // impossible for curCap 
                    return INT_MAX;
                }
                days+=1;
                curSum = weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxCap = INT_MAX;   // When only one weight is allowed
        int totalSum = 0;       // When all the luggage is allowed in one go

        for(int i=0; i<weights.size(); ++i){
            maxCap = min(maxCap, weights[i]);
            totalSum+=weights[i];
        }

        int ans = -1;

        int l = maxCap;
        int r = totalSum;

        while(l <= r){

            int curCap = l + (r - l)/2;

            // Check for the mid capacity 

            int curDays = findDays(weights, curCap);

            if(curDays > days){
                // required days is more, means the curCap is less than expected, increase the capacity and check.
                l = curCap + 1;
            }else if(curDays <= days){
                // required days is less/equal, means curCap suffices, but check for better option is possible by decreasing the curCap
                ans = curCap;
                r =  curCap - 1;
            }
        }

        return ans;
    }
};