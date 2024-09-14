You are given an array of positive and/or negative integers and a value K . The task is to find count of all sub-arrays whose sum is divisible by K?

Examples : 
Input  : arr[] = {4, 5, 0, -2, -3, 1}, 
         K = 5
Output : 7
// there are 7 sub-arrays whose sum is divisible by K
// {4, 5, 0, -2, -3, 1}
// {5}
// {5, 0}
// {5, 0, -2, -3}
// {0}
// {0, -2, -3}
// {-2, -3}

https://www.youtube.com/watch?v=ufXxc8Vty9A

===============================================================================

class Solution {
    public int subarraysDivByK(int[] A, int K) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        map.put(0,1);
        int runningSum = 0;
        int count = 0 ;
        for(int i=0;i<A.length;i++){
            runningSum += A[i];
            int remainder = runningSum % K;
            if(remainder < 0) remainder +=K;
            if(map.containsKey(remainder)) {
                count += map.get(remainder);      
            }
             map.put(remainder, map.getOrDefault(remainder,0)+1);  
        }
        
         return count;
    }            
}