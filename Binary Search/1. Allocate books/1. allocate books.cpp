Problem statement
Ayush is studying for ninjatest which will be held after 'N' days, And to score good marks he has to study 'M' chapters and the ith chapter requires TIME[i] seconds to study. The day in Ayush’s world has 100^100 seconds. There are some rules that are followed by Ayush while studying.

1. He reads the chapter in a sequential order, i.e. he studies i+1th chapter only after he studies ith chapter.

2. If he starts some chapter on a particular day he completes it that day itself.

3. He wants to distribute his workload over 'N' days, so he wants to minimize the maximum amount of time he studies in a day.

Your task is to find out the minimal value of the maximum amount of time for which Ayush studies in a day, in order to complete all the 'M' chapters in no more than 'N' days.

For example

if Ayush want to study 6 chapters in 3 days and the time that each chapter requires is as follows:
Chapter 1 = 30
Chapter 2 = 20
Chapter 3 = 10
Chapter 4 = 40
Chapter 5 = 5
Chapter 6 = 45

Then he will study the chapters in the following order 

| day 1 : 1 , 2 | day 2 : 3 , 4 | day 3 : 5 , 6 |
Here we can see that he study chapters in sequential order and the maximum time to study on a day is 50, which is the minimum possible in this case.


==========================================================================================

#include <bits/stdc++.h> 
int calculateDays(vector<int>& arr, long long curTimeSlot){
    int part = 1;
    long long curSum = 0;
    for(int i=0; i<arr.size(); ++i){
        if(curSum + arr[i] <= curTimeSlot){
            curSum+=arr[i];
        }else{
            if(arr[i] > curTimeSlot){
                return INT_MAX;
            }
            part = part + 1;
            curSum = arr[i];
        }
    }

    return part;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{   
    // Write your code here.
    long long totalTime = 0;
    int minTime = INT_MAX;

    for(int i=0; i<time.size(); ++i){
        minTime = min(minTime, time[i]);
        totalTime+=time[i];
    }

    long long ans = -1;

    // binary search for the answer between minTime and totalTime
    long long l = minTime;
    long long r = totalTime;

    while(l <= r){
        
        long long curTimeSlot = l + (r - l)/2;

        int days = calculateDays(time, curTimeSlot);

        if(days > n){
            // time slot is too small, increase the time slot
            l = curTimeSlot + 1;
        }else if(days == n){
            // time slot fits out need, update the ans and 
            // try to find a smaller timeslot
            ans = curTimeSlot;
            r = curTimeSlot - 1;
        }else{ // days < n
            // time slot is too huge, decrease the slot and try again
            ans = curTimeSlot;
            r = curTimeSlot - 1;
        }
    }

    return ans;
}