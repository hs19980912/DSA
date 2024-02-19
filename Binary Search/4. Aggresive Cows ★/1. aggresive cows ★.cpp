Problem statement
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.

You are also given an integer 'k' which denotes the number of aggressive cows.

You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.

Print the maximum possible minimum distance.

Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.

Sample Input 2 :
5 2
4 2 1 3 6

Sample Output 2 :
5

Expected time complexity:
Can you solve this in O(n * log(n)) time complexity?

===================================================================================

int findCows(vector<int>& stalls, int curLen){
    int cows = 1;
    int curSum = 0;

    for(int i=0; i<stalls.size()-1; ++i){
        if(curSum + stalls[i+1] - stalls[i] < curLen){
            curSum += stalls[i+1] - stalls[i];
        }else{
            cows+=1;
            curSum=0;            
        }
    }

    return cows;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    
    sort(begin(stalls), end(stalls));

    int minLen = INT_MAX;
    int maxLen = INT_MIN;

    for(int i=0; i<stalls.size(); ++i){
        minLen = min(minLen, stalls[i]);
        maxLen = max(maxLen, stalls[i]);
    }

    int ans = -1;
    int l = 1;
    int r = maxLen - minLen;

    while(l <= r){

        int curLen = l + (r - l)/2;

        int curCows = findCows(stalls, curLen);

        if(curCows < k){
            // Less cows can be fitted, more cows are to be fitted,
            // decrease the curLen
            r = curLen - 1;
        }else{
            // more or Equal no of cows can be fitted,
            // Increase the curLen to check for other options.
            ans = curLen;
            l = curLen + 1;
        }

    }


    return ans;
}