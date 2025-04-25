link: https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

You are given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. A single person can perform only one activity at a time, meaning no two activities can overlap. Your task is to determine the maximum number of activities that a person can complete in a day.

Examples:

Input: start[] = [1, 3, 0, 5, 8, 5], finish[] = [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: A person can perform at most four activities. The maximum set of activities that can be executed is {0, 1, 3, 4}

Input: start[] = [10, 12, 20], finish[] = [20, 25, 30]
Output: 1
Explanation: A person can perform at most one activity.

Input: start[] = [1, 3, 2, 5], finish[] = [2, 4, 3, 6]
Output: 3
Explanation: A person can perform activities 0, 1 and 3.


-----------------------------------------------------------------------------


int maxActivities(vector<int>& start, vector<int>& finish) {
    // Error checking
    if (start.size() != finish.size() || start.empty()) {
        return 0;
    }

    // Create events vector
    vector<tuple<int, string, int>> events;
    for (int i = 0; i < start.size(); ++i) {
        events.push_back({start[i], "start", i});
        events.push_back({finish[i], "finish", i});
    }
    
    // Sort events by timestamp
    sort(events.begin(), events.end());
    
    set<int> currentActivities;  // Track ongoing activities
    set<int> completedActivities;  // Track completed activities
    int maxActivitiesCount = 0;
    int lastFinishTime = -1;
    
    for (const auto& event : events) {
        int time = get<0>(event);
        string eventType = get<1>(event);
        int activityId = get<2>(event);
        
        if (eventType == "start") {
            // Only consider this activity if we're not already doing something
            if (lastFinishTime <= start[activityId]) {
                currentActivities.insert(activityId);
            }
        } else { // eventType == "finish"
            // If we were doing this activity, mark it as done
            if (currentActivities.find(activityId) != currentActivities.end()) {
                currentActivities.erase(activityId);
                completedActivities.insert(activityId);
                maxActivitiesCount++;
                lastFinishTime = time;
            }
        }
    }
    
    return maxActivitiesCount;
}

// However, the above approach is unnecessarily complex for this problem.
// Here's a more standard and efficient solution:
int maxActivitiesGreedy(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    if (n == 0) return 0;
    
    // Create pairs of (finish time, start time)
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++) {
        activities.push_back({finish[i], start[i]});
    }
    
    // Sort by finish time
    sort(activities.begin(), activities.end());
    
    int count = 1;  // We can always pick the first activity
    int lastFinish = activities[0].first;
    
    for (int i = 1; i < n; i++) {
        if (activities[i].second >= lastFinish) {
            // This activity starts after the finish of the previously selected activity
            count++;
            lastFinish = activities[i].first;
        }
    }
    
    return count;
}