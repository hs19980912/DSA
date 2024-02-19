int findPart(vector<int>& boards, int curLen){
    int parts = 1; // painters needed when limit is set to curLen
    int curSum = 0; 
    for(int i=0; i<boards.size(); ++i){
        if(curSum + boards[i] <= curLen){
            curSum+=boards[i];
        }else{
            if(boards[i] > curLen){
                // It wont be possible at all to paint all the boards with this curLen, painters required will be infinity
                return INT_MAX;
            }
            parts+=1;
            curSum = boards[i];
        }
    }

    return parts;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int maxLen = INT_MIN;
    long long sumLen = 0;
    for(int i=0; i<boards.size(); ++i){
        maxLen = max(maxLen, boards[i]);
        sumLen+=boards[i];
    }

    long long ans = -1;

    long long l = maxLen;
    long long r = sumLen;

    while(l <= r){
        long long midLen = l + (r - l)/2;

        int curAns = findPart(boards, midLen);

        if(curAns > k){
            // A lot more painters are needed, try to increase the length and search for the case of lesser painters
            l = midLen + 1;
        }else{
            // midLen is sufficiently large such that the job can be done with less than/equal to k painters, update the answer and decrease the length to find other optimal answer.
            ans = midLen;
            r = midLen - 1;
        }
    }

    return ans;

}