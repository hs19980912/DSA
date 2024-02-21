IMP: It involves both Binary search and Greedy.

Ninja bought chocolate consisting of some chunks. The sweetness of each chunk is given in an array ‘ARR’. Ninja has ‘K’ friends, and he wishes to divide the chocolate into 'K' + 1 cut with some consecutive chunks. He wants to divide the chocolate into chunks under the condition that he will take the piece that has the minimum total sweetness.

He is very busy doing other stuff. Can you help him to maximize the total sweetness of the part that you will get under the given condition?

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1<= T <= 10
1 <= N <= 50000
0 <= K < N
1 <= ARR[i] <= 10000

Where 'ARR[i]' is the sweetness of the 'i_th' chunk.

Time Limit: 1 sec
Sample Input 1:
2
9 3
5 6 7 8 9 10 11 12 13
3 2
2 2 2
Sample Output 1:
17
2
Explanation for Sample Input 1:
In the first test case, the sweetness of the chunks are [5, 6, 7, 8, 9, 10, 11, 12, 13] and Ninja has 3 friends. So, it is to be divided among 4 people including Ninja himself. In order to maximize the total sweetness of Ninja, one possible division is [5, 6, 7], [8, 9], [10, 11], [12, 13]. The minimum sweetness of one part is 17. So, the answer is 17.

In the second test case, the sweetness of the chunks are [2, 2, 2] and Ninja has 2 friends. So, it is to be divided among 3 people, and there are only 3 chunks. So, all three friends will be getting one chunk each. So, the total sweetness that Ninja will get is 2. So, the answer is 2.
Sample Input 2:
2
3 2
5 6 7
10 4
2 3 2 3 2 3 2 3 2 3
Sample Output 2:
5
5


=================================
# WORKING SOLUTION: COPIED from other

#include <bits/stdc++.h> 
bool check(vector<int> &a, int mid, int k) {
    long long ans=0, sum=0;
    for(auto x: a) {
        sum += x;
        if(sum>=mid) {
            sum=0;
            ans++;
        }
    }
    return ans>k;
}
int getMaximumSweetness(vector<int> &a, int k) {
    long long lo=0, hi=0, mid, ans=0;
    for(auto x: a) hi += x;
    while(lo<=hi) {
        mid=(lo+hi)>>1;
        if(check(a, mid, k)) {
            ans=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    return ans;
}

======================================================

#include <bits/stdc++.h> 

int findParts(vector<int>& arr, int sumLimit){
    int parts = 0;
    int curSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if(curSum + arr[i]<sumLimit){
            curSum+=arr[i];
        }else if(curSum + arr[i] == sumLimit){
            curSum = 0;
            parts+=1;
        }else{
            // curSum + arr[i] > sumLimit
            curSum = 0;
            parts+=1;
        }
    }

    return parts;
}

int getMaximumSweetness(vector<int> &arr, int k)
{
    // Write your code here.
    int l = 0;
    int r = 0;
    for(int i=0; i<arr.size(); ++i){
        r+=arr[i];
    }    

    int ans = -1;

    // curMinSum at each iteration signifies the minimum amount of 
    // sweetness a part can have.
    // While calculating no of parts in findParts, as soon as we reach curMinSum, start new part. This is the GREEDY part of the question - IMP.
    while(l <= r){
        int curMinSum = l + (r - l)/2;

        int parts = findParts(arr, curMinSum);

        //cout << "for curMinSum:" << curMinSum << "  parts:" << parts << endl;

        if(parts < k + 1){
            // curMinSum is too large, we were not able to cut the in k peices, the pieces fell short. decrease curMinSum and try to find a suitable ans.
            r = curMinSum - 1;
        }else{  // parts >= k + 1
            // curMinSum was sufficient enough to divide in k/more than k parts. curMinSum is a possible answer but try to find a more optimal ans. Increase the curMinSum.
            ans = curMinSum;
            l = curMinSum + 1; 
        }
    }

    return ans;
}