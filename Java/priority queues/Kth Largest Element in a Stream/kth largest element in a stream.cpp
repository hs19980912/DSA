// 703. Kth Largest Element in a Stream

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;  // min priority queue
    int reqSize;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0; i<nums.size(); ++i){
            if(pq.size() < k){
                pq.push(nums[i]);
            }else{
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        reqSize = k;
    }
    
    int add(int val) {
        if(pq.size() < reqSize){
            pq.push(val);
        }else{
            if(val > pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        
        return pq.top();
    }
};
