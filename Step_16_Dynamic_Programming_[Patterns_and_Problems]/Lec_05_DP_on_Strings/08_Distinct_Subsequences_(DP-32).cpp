# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/distinct-subsequences/description/

class Solution {
private:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i - 1] == t[j - 1]) {
            int take = solve(s, t, i - 1, j - 1, dp);
            int notTake = solve(s, t, i - 1, j, dp);
            return dp[i][j] = take + notTake;
        } else {
            return dp[i][j] = solve(s, t, i - 1, j, dp);
        }
    }

    int solveTab(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long> (m + 1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    unsigned long long take = dp[i - 1][j - 1];
                    unsigned long long notTake = dp[i - 1][j];
                    dp[i][j] = take + notTake;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
public:
    int numDistinct(string s, string t) {
        // Use 1 based indexing

        // TLE 
        /*
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(s, t, n, m, dp);
        */

        // Bottom Up 

        return solveTab(s, t);

        // Space optimization is also possible.
    }
};