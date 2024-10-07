// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201


class Solution{
public:
    
    int startFromThisIndex(int val[], int wt[], int size, int W, int index){
        if(index >= size){
            return 0;
        }
        
        int take = 0;
        int notTake = 0;
        
        if(wt[index] <= W){
            take = val[index] + startFromThisIndex(val, wt, size, W, index);
        }
        notTake = startFromThisIndex(val, wr, size, W, index+1);

        int ans = max(take, notTake);

        return ans;
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        return startFromThisIndex(val, wt, N, W, 0);
    }
};