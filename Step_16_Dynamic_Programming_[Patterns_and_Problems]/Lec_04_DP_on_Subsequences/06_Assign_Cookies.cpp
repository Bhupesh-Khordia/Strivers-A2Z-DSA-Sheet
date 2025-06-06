# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/assign-cookies/

class Solution {
private:
    int solve(vector<int>& g, vector<int>& s, int i, int j, vector<vector<int>> &dp) {
        if (i >= g.size() || j >= s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if (s[j] >= g[i]) {
            // Assign cookie j to child i and move both
            take = 1 + solve(g, s, i + 1, j + 1, dp);
        }

        // Try skipping cookie j (try to use it for someone else)
        int skip = solve(g, s, i, j + 1, dp);

        return dp[i][j] = max(take, skip);
    }
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Greedy Solution
        /*
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, ans = 0;
        while(i < g.size() && j < s.size()) {
            if(g[i] <= s[j]) {
                ans++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return ans;
        */


        // Can also be solved with DP, but that would be overkill (not recommended) (MLE on leetcode)
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        vector<vector<int>> dp(g.size() + 1, vector<int>(s.size() + 1, -1));

        return solve(g, s, 0, 0, dp);
    }
};