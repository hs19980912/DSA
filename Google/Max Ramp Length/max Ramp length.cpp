int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
    vector<int> maxFromRight(n);
    maxFromRight[n-1] = nums[n-1];

    for(int i=n-2; i>=0; --i){
        maxFromRight[i] = max(maxFromRight[i+1], nums[i]);
    }

    int finalAns = 0;

    int i=0;
    int j=0;

    while(i<n && j<n){
        while(j<n && nums[i]<=maxFromRight[j]){
            j+=1;
        }
        finalAns = max(finalAns, j-1-i);
        i+=1;
    }

    return finalAns;
}