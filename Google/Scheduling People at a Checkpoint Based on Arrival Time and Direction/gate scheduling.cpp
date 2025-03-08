Problem Statement: Scheduling People at a Checkpoint Based on Arrival Time and Direction

Problem Overview

You are given a list of people arriving at a checkpoint. Each person has a unique ID, an arrival time, and a direction (either “L” for Left or “R” for Right). The checkpoint processes one person at a time, and there is a scheduling algorithm that determines the order in which people are processed.

The objective is to simulate how people are processed based on their arrival time and the previous direction of processing, following a rule similar to the SCAN (Elevator) scheduling algorithm.

Input Format

You are given a list of N tuples, where each tuple represents a person with the following attributes:
	•	ID (int): A unique identifier for the person.
	•	Time (int): The timestamp when the person arrives at the checkpoint.
	•	Direction (string): The direction they want to go in (“L” for Left, “R” for Right).

Example input:

vector<tuple<int, int, string>> input = {
    {1, 1, "R"}, {2, 1, "L"}, {3, 2, "L"},
    {4, 2, "L"}, {5, 2, "R"}, {6, 3, "R"},
    {7, 3, "R"}, {8, 12, "L"}, {9, 13, "R"},
    {10, 12, "R"}, {11, 13, "L"}, {12, 8, "R"}
};

Processing Rules
	1.	Sorting the People
	•	People are sorted based on arrival time (time).
	•	If two people have the same arrival time, they are processed in increasing order of their ID.
	2.	Dividing People into Two Groups
	•	People moving Left (“L”) are separated from people moving Right (“R”).
	3.	Processing Order (SCAN-like behavior)
	•	The checkpoint maintains a current time (curTime).
	•	It starts processing based on previously processed direction (preDirection):
	•	If both “L” and “R” people are waiting at the same time, the previous direction determines who is processed first.
	•	If one group has no people available at curTime, the checkpoint switches direction and jumps to the next available time.
	4.	Handling Remaining People
	•	If one group is completely processed but the other still has people left, they are processed based on their arrival time.
	•	The checkpoint may have to wait (increase curTime) if the next person hasn’t arrived yet.

Output Format

The program outputs a list of people processed in order, along with the time they were processed.

Example output:

Sorted Output:
time: 1, ID: 2, Time: 1, Direction: L
time: 2, ID: 1, Time: 1, Direction: R
time: 3, ID: 3, Time: 2, Direction: L
time: 4, ID: 4, Time: 2, Direction: L
time: 5, ID: 5, Time: 2, Direction: R
time: 6, ID: 6, Time: 3, Direction: R
time: 7, ID: 7, Time: 3, Direction: R
...

Constraints
	•	1 ≤ N ≤ 10^5 (Number of people)
	•	1 ≤ ID ≤ 10^5
	•	1 ≤ Time ≤ 10^9
	•	Direction ∈ {“L”, “R”}

Example Walkthrough

Given Input:

ID	Time	Direction
1	1	R
2	1	L
3	2	L
4	2	L
5	2	R

Sorted Order:

The people are first sorted by time, and IDs are used as a secondary sort.

(2, 1, "L"), (1, 1, "R"), (3, 2, "L"), (4, 2, "L"), (5, 2, "R")

Processing Order:
	1.	Since both ID 2 (“L”) and ID 1 (“R”) arrive at the same time, we prioritize “L” first.
	2.	Then, ID 1 (“R”) is processed.
	3.	At curTime = 2, both ID 3 (“L”) and ID 4 (“L”) are available → process them.
	4.	Finally, ID 5 (“R”) is processed.

Use Cases & Applications

This algorithm can be applied to:
	•	Elevator Scheduling (Lift Algorithm): Deciding the order in which passengers board and exit based on their floor requests.
	•	Toll Booth / Checkpoint Processing: Managing the order in which vehicles or people pass through a toll/checkpoint based on arrival time.
	•	Network Packet Scheduling: Prioritizing packets based on arrival time and direction in a router.
	•	Traffic Management at an Intersection: Handling cars moving in different directions at a signal.

Summary

This problem simulates scheduling people at a checkpoint based on arrival time and direction, following a behavior similar to the SCAN algorithm. It ensures that people are processed in a fair and efficient manner while respecting priority based on previous direction. 🚀

=================================================================================================================

Code :
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class Compare {
public:
    bool operator()(const tuple<int, int, string>& a, const tuple<int, int, string>& b) const {
        if (get<1>(a) == get<1>(b)) {
            return get<0>(a) < get<0>(b);
        }
        return get<1>(a) < get<1>(b);
    }
};

vector<pair<int, tuple<int, int, string>>> findTiming(vector<tuple<int, int, string>>& input) {
    sort(input.begin(), input.end(), Compare());
    vector<tuple<int, int, string>> left, right;
    for(const auto& event : input) {
        if(get<2>(event) == "L") {
            left.push_back(event);
        } else {
            right.push_back(event);
        }
    }
    vector<pair<int, tuple<int, int, string>>> finalAns;    // < time, person >
    string preDirection = "L";
    int curTime = 0;
    int l = 0;
    int r = 0;
    // CASE 1: Both the events are present
    while(l < left.size() && r < right.size()) {
        tuple<int, int, string> leftEvent = left[l];
        tuple<int, int, string> rightEvent = right[r];
        
        // case 1: both have time <= curTime
        if(get<1>(leftEvent) <= curTime && get<1>(rightEvent) <= curTime) {
            if(preDirection == "L") {
                finalAns.push_back({curTime, leftEvent});
                l += 1;
            } else {
                finalAns.push_back({curTime, rightEvent});
                r += 1;
            }
            curTime += 1;
            // no change in the preDirection
        }
        // case 2: both have time > curTime
        else if(get<1>(leftEvent) > curTime && get<1>(rightEvent) > curTime) {
            preDirection = "L";
            curTime = min(get<1>(leftEvent), get<1>(rightEvent));
        }
        // case 3: only left has valid time
        else if(get<1>(leftEvent) <= curTime && get<1>(rightEvent) > curTime) {
            preDirection = "L";
            finalAns.push_back({curTime, leftEvent});
            l += 1;
            curTime += 1;
        }
        // case 4: only right has valid time
        else if(get<1>(leftEvent) > curTime && get<1>(rightEvent) <= curTime) {
            preDirection = "R";
            finalAns.push_back({curTime, rightEvent});
            r += 1;
            curTime += 1;
        }
    }
    // IF left is remaining
    while(l < left.size()) {
        auto leftEvent = left[l];
        if(get<1>(leftEvent) <= curTime) {
            finalAns.push_back({curTime, leftEvent});
            l += 1;
            curTime += 1;
        } else {
            curTime = get<1>(leftEvent);
            finalAns.push_back({curTime, leftEvent});
            l += 1;
            curTime += 1;
        }
    }
    // if right is remaining
    while(r < right.size()) {
        auto rightEvent = right[r];
        if(get<1>(rightEvent) <= curTime) {
            finalAns.push_back({curTime, rightEvent});
            r += 1;
            curTime += 1;
        } else {
            curTime = get<1>(rightEvent);
            finalAns.push_back({curTime, rightEvent});
            r += 1;
            curTime += 1;
        }
    }
    return finalAns;
}

int main() {
    vector<tuple<int, int, string>> input;    //  tuple {id, time, direction}
    input.push_back({1, 1, "R"});
    input.push_back({2, 1, "L"});
    input.push_back({3, 2, "L"});
    input.push_back({4, 2, "L"});
    input.push_back({5, 2, "R"});
    input.push_back({6, 3, "R"});
    input.push_back({7, 3, "R"});
    input.push_back({8, 12, "L"});
    input.push_back({9, 13, "R"});
    input.push_back({10, 12, "R"});
    input.push_back({11, 13, "L"});
    input.push_back({12, 8, "R"});
    vector<pair<int, tuple<int, int, string>>> ans = findTiming(input);
    cout << "Sorted Output:\n";
    for (const auto& p : ans) {
        int index = p.first;
        tuple<int, int, string> tup = p.second;
        cout << "time: " << index << ", ID: " << get<0>(tup)
             << ", Time: " << get<1>(tup)
             << ", Direction: " << get<2>(tup) << endl;
    }
    return 0;
}


