// https://leetcode.com/problems/non-overlapping-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkOverlap(vector<int>& a, vector<int>& b) {
        return !(a[0] >= b[1] || b[0] >= a[1]);
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (checkOverlap(prev, intervals[i])) {
                cnt++;
                
                // Keep interval with smaller end time
                if (prev[1] > intervals[i][1]) {
                    prev = intervals[i];
                }
                // else: keep prev as is
            } else {
                prev = intervals[i]; // No overlap: move prev forward
            }
        }

        return cnt;
    }
};
