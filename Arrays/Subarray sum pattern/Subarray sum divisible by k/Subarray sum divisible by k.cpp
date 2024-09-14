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
public:
    int subarraysDivByK(std::vector<int>& A, int K) {
        std::unordered_map<int, int> map;
        map[0] = 1; // Initialize with remainder 0 having one count
        int runningSum = 0;
        int count = 0;
        
        for (int i = 0; i < A.size(); ++i) {
            runningSum += A[i];
            int remainder = runningSum % K;

            // Handle negative remainders to ensure correct modulus behavior
            if (remainder < 0) remainder += K;

            // If the remainder is already in the map, it means there are subarrays
            // whose sum is divisible by K
            if (map.find(remainder) != map.end()) {
                count += map[remainder];
            }

            // Update the frequency of the current remainder
            map[remainder]++;
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    std::vector<int> A = {4, 5, 0, -2, -3, 1};
    int K = 5;
    int result = solution.subarraysDivByK(A, K);
    std::cout << "Number of subarrays divisible by " << K << ": " << result << std::endl;
    return 0;
}
