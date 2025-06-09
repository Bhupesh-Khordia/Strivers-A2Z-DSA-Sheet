# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning-ii/description/

class Solution {
private:
    // Precompute palindrome table in O(n^2)
    vector<vector<bool>> computePalindromeTable(const string &s) {
        int n = s.length();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2) isPal[i][j] = true;
                    else isPal[i][j] = isPal[i + 1][j - 1];
                }
            }
        }
        return isPal;
    }

    // Top-down recursive helper
    int solveTopDown(const string &s, int i, vector<int> &dp, const vector<vector<bool>> &isPal) {
        if (i == s.length()) return -1;
        if (dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for (int j = i; j < s.length(); j++) {
            if (isPal[i][j]) {
                mini = min(mini, 1 + solveTopDown(s, j + 1, dp, isPal));
            }
        }

        return dp[i] = mini;
    }

    // Bottom-up tabulation
    int solveBottomUp(const string &s, const vector<vector<bool>> &isPal) {
        int n = s.length();
        vector<int> dp(n, 0); // dp[i] = min cuts for s[0..i]

        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = i;
                for (int j = 1; j <= i; j++) {
                    if (isPal[j][i]) {
                        dp[i] = min(dp[i], 1 + dp[j - 1]);
                    }
                }
            }
        }

        return dp[n - 1];
    }

public:
    int minCut(string s) {
        vector<vector<bool>> isPal = computePalindromeTable(s);
        
        // --------- Top-down recursive DP ------------
        // vector<int> dp(s.length(), -1);
        // return solveTopDown(s, 0, dp, isPal);
        
        // --------- Bottom-up DP ---------------------
        return solveBottomUp(s, isPal);
    }
};
