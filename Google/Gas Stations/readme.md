## Gas Stations
- Gas stations follows a **greedy approach**, at a current window [i, j], when a window is not possible at j, then we directly shift entire window after j, ie, in the new Window, i starts from j+1. It is impossible for a better window to lie inbetween [i,j].

- Bank Transaction follows a **Sliding Window**, at a current window [i, j], when a window fails at j, we start moving i to the right step by step to find a prospective window.

- Why the difference? It basically arises due to the behaviour/allowance of negative values in Bank transaction. whereas in Gas station, there can never be a total value which is currently negative.  
"Total value" in the case of Gas station is the value of pre, i.e, the gas present in the car at any moment of time. whereas total value is the curSum present in bank at any moment of time.


- ```cpp
    class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = gas.size();
            gas.resize(2 * n);
            cost.resize(2 * n);
            for(int i=0; i<n; ++i){
                gas[n + i] = gas[i];
                cost[n + i] = cost[i];
            }

            int pre = 0;
            int i = 0;
            int j = 0;

            // Current window starts at i,
            // Can we add j in our current window,
            while(j < 2*n){
                if(pre + gas[j] < cost[j]){ 
                    i=j+1;
                    j=i;
                    pre = 0;
                }
                else{
                    pre += gas[j] - cost[j];
                    if(j-i+1 == n){
                        return i;
                    }
                    j+=1;
                }
            }

            return -1;
        }
    };
    ```