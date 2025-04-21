Find minimum time to finish all jobs with given constraints

Given an array job[], where each element represents the time required to complete a specific job. 
There are k identical assignees available to complete these jobs, and each assignee takes t units of time to complete one unit of a job. 
The task is to determine the minimum time required to complete all jobs while following these constraints: 
    - Each assignee can only be assigned jobs that are contiguous in the given array. For example, an assignee can be assigned jobs (job[1], job[2], job[3]) but not (job[1], job[3]) (skipping job[2]).
    - A single job cannot be divided between two assignees. Each job must be assigned to exactly one assignee.

Input: job[] = {10, 7, 8, 12, 6, 8}, k = 4, t = 5
Output: 75
Explanation: The minimum time required to finish all the jobs is 75.
Assign {10} to the first assignee.
Assign {7, 8} to the second assignee.
Assign {12} to the third assignee.
Assign {6, 8} to the fourth assignee.
Maximum time taken by any assignee is (12 * 5) = 75.

==================================================================================================

NOTE: 

This problem is mainly a variation of Allocate Minimum Pages/ Split array in k subarrays such that largest sum is minimized.

===================================================================================================


int findWorkerForCurrentSum(vector<int>& nums, int maxSum){
    int worker = 1;
    int curSum = nums[0];

    int i=1;
    while(i<nums.size()){
        if(curSum>maxSum){
            return INT_MAX;
        }

        if(curSum+nums[i]<=maxSum){
            curSum+=nums[i];
        }
        else if(curSum+nums[i] > maxSum){
            curSum = nums[i];
            worker+=1;
        }
        i+=1;
    }

    return worker;
}

int findMinTime(vector<int>& nums, int k) {
    int sum = 0;
    for(int i=0; i<nums.size(); ++i){
        sum+=nums[i];
    }

    int l=0;
    int r=sum;
    int ans = INT_MAX;
    while(l<=r){
        int mid = (r-l)/2 +l;
        int workerReq = findWorkerForCurrentSum(nums, mid);
        if(workerReq>k){
            // Time limit given to each worker is very less,
            // hence larger workforce is required.
            // increase the time limit.
            l = mid+1;
        }else{
            // possible ans found.
            // reduce the time limit and see if it works?
            ans = min(ans, mid);
            r = mid - 1; 
        }
    }

    return ans; 
}