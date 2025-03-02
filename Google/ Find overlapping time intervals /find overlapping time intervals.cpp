Write a code for the following:

Start time and end time is given for many people, eg
Person1 : 4, 7
Person2 : 6, 8
Person3 : 9,10
Output
4, 6: P1
6, 7: P1, P2
7, 8: P2
9,10:P3 

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
using namespace::std;
/* 
1. Input list to Event list
2. Sort the Event list - On basis of time
3. Form FinalAns
*/

vector<tuple<int, int, set<int>>> findIntervals(vector<pair<int, int>>& input){
    vector<tuple<int, string, int>> events;
    for(int i=0; i<input.size(); ++i){
    	auto cur = input[i];	// pair<begin, end> time
    	events.push_back({cur.first, "start", i+1});
    	events.push_back({cur.second, "end", i+1});
    }

    sort(events.begin(), events.end());

    vector<tuple<int, int, set<int>>> finalAns;
    set<int> curSet;
    int curTime = -1;

    for(auto &event: events){
    	int eventTime = get<0>(event);
    	string type = get<1>(event);
    	int id = get<2>(event);

    	if(curSet.size()>0 && curTime!=eventTime){
    		finalAns.push_back({curTime, eventTime, curSet});
    	}

    	if(type == "start"){
    		curSet.insert(id);
    	}else{
    		curSet.erase(id);
    	}

    	curTime = eventTime;
    }

    return finalAns;
}

int main(){
    vector<pair<int, int>> input = {{1,4}, {3,5}, {4,7}, {6,7}, {6,8}, {9,12}, {10,11}};
    vector< tuple< int, int, set<int> > > finalAns = findIntervals(input);
    
    cout << "\nComputed Intervals:\n";
    for (const auto& interval : finalAns) {
        int start = get<0>(interval);
        int end = get<1>(interval);
        set<int> people = get<2>(interval);

        cout << start << " - " << end << ": { ";
        for (int p : people) {
            cout << "P" << p << " ";
        }
        cout << "}\n";
    }
    cout << endl;
    
    return 0;
}