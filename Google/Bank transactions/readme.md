## Bank Transactions - max people bank can serve
- Consider a bank with some intial amount of money. Consider an array which represents list of transactions which are going to come through customers. + means deposit - means withdrawl. Bank can choose from which customer they want to start serving the customers and they can refuse any number of customers. But once they start they have to serve till the time its impossible to serve the customers. Maximize the total customers bank can serve.

    **Example** :  
    Bank has 1 unit of money intially.  
    Customer transactions : [1, -3, 5, -2, 1]  
    answer = 3

    Bank starts with customer with deposit of 5
    1+ 5 = 6  
    6 - 2 = 4  
    4 + 1 =5  

    If bank starts at in index 0 can only serve 1 customer  
    1+1 =2  
    2-3 = -1 not possible

    [Link](https://leetcode.com/discuss/post/4874329/google-onsite-interview-question-by-anon-wcrh/)


### Approach:
    1. Keep track of current Balance, start and end of transactions served
    2. Add each transaction to your current balance (curBalance += transactions[end])
    3. If your current balance goes negative,
        - keep releasing the earlier transactions until, (curBalance -= transactions[start]; start += 1)
        - either your current balance becomes non negative, or (curBalance >= 0)
        - you have no more transactions to release (start > end)
    4. move on to next transaction (end += 1)
    5. check the number of transactions you have served (maxServed = max(maxServed, end - start))

```cpp
int maxCustomers(std::vector<int>& transact, int startingSum) {
    int n = transact.size();
    int i = 0;
    int j = 0;
    int curSum = startingSum;
    int maxAns = 0;

    // with start at i, is j possible?
    // if yes, update maxAns,
    // else, try to bring i to a better position 
    while(j<n && i<n){
        if(curSum + transact[j] >= 0){
            curSum+=transact[j];
            maxAns = std::max(j-i+1, maxAns);
            j+=1;
        }else{
            if(i == j){
                i+=1;
                j=i;
            }
            else{
                curSum-=transact[i];
                i+=1;
            }
        }
    }

    return maxAns;
} 
```