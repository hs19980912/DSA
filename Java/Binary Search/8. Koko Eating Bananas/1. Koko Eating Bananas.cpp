875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23

---------------------------------------------------------------------

Return the minimum integer k such that she can eat all the bananas within h hours.

k will have a range [0, some range]
For a given speed k in the range, 


======================================================================

class Solution {
public:

    int findHours(vector<int>& piles, int speedLimit){
        int hours = 0;
        for(int i=0; i<piles.size(); ++i){
            hours += piles[i]/speedLimit + (int)(piles[i]%speedLimit != 0);
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(int i=0; i<piles.size(); ++i){
            r = max(r, piles[i]);
        }

        int ans = -1;

        while(l <= r){
            int curSpeed = l + (r - l)/2;

            int hours = findHours(piles, curSpeed);
            
            if(hours > h){
                // curSpeed is less than required, hence the hours are more than limit. need to increase the speed and then find any answer.
                l = curSpeed + 1;
            }else{
                // curSpeed is sufficient, decrease the speed and try to find the optimal speed.
                ans = curSpeed;
                r = curSpeed - 1;
            }
        }

        return ans;
    }
};