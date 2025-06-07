# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution {
  private:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp, int &maxLen) {
        // Base case
        if (i < 0 || j < 0)
            return 0;

        // Memoization check
        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match, increment length
        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1, dp, maxLen);
            maxLen = max(maxLen, dp[i][j]); // update global max
        } else {
            dp[i][j] = 0;
        }
        
        // Explore all paths
        solve(s1, s2, i - 1, j, dp, maxLen);
        solve(s1, s2, i, j - 1, dp, maxLen);
        
        return dp[i][j];
    }
    
    int solveTab(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        int maxLen = 0;
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // If characters match, increment length
                if (s1[i] == s2[j]) {
                    if(i - 1 >= 0 && j - 1 >= 0)
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else 
                        dp[i][j] = 1 + 0;
                    maxLen = max(maxLen, dp[i][j]); // update global max
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return maxLen;
    }
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // Top Down
        
        /*
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int ans = 0;
        solve(s1, s2, m - 1, n - 1, dp, ans);
        return ans;
        */
        
        
        // Bottom Up
        
        return solveTab(s1, s2);
    }
};