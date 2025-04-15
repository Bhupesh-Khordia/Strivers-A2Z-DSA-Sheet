// https://leetcode.com/problems/merge-intervals/

class Solution {
private:
    static bool cmp (vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Extra Space - O(n)
        /*
        sort(intervals.begin(), intervals.end(), cmp);

        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> ans;
        int n = intervals.size();

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] > end) {
                // No overlap
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                // Overlap
                end = max(end, intervals[i][1]);
            }
        }
        ans.push_back({start, end});
        return ans;
        */


        // No extra space
        sort(intervals.begin(), intervals.end());
        int k = 0; // Index for
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[k][1] >= intervals[i][0]) { // Overlap detected
                intervals[k][1] = max(intervals[k][1], intervals[i][1]); 
            } else {
                k++;
                intervals[k] = intervals[i]; // Replace in-place
            }
        }
        
        intervals.resize(k + 1); 
        return intervals;
    }
};
