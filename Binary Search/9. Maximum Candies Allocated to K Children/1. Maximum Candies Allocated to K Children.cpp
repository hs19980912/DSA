2226. Maximum Candies Allocated to K Children
You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can take at most one pile of candies and some piles of candies may go unused.

Return the maximum number of candies each child can get.

 

Example 1:

Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
Example 2:

Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.

------------------------------------------------------------------------

How many children can we form??

let x be the number of candies all the children are getting.
x can be in the range of [0, some_range]
For all the x in the range, find the number of childer we can feed.

If we can feed more/equal to 'k' children, then it is a possible answer. increase the x and find any other optimal answer.

========================================================================

class Solution {
public:

	long long findChilds(vector<int>& candies, int numCandy){
		// numCandy is given to all the children, How many children can we form??
		long long childs = 0;
		for(int i=0; i<candies.size(); ++i){
			childs += candies/numCandy;
		}

		return childs;
	}

    int maximumCandies(vector<int>& candies, long long k) {
    	int l = 0;
    	int r = 0;
    	for(int i=0; i<candies.size(); ++i){
    		r = max(r, candies[i]);
    	}

    	int ans = 0;

    	while(l <= r){
    		int mid = l + (r - l)/2;

    		int childs = findChilds(candies, mid);

    		if(childs < k){
    			r = mid - 1;
    		}else{
    			ans = mid;
    			l = mid + 1;
    		}
    	}

    	return ans;
    }
};