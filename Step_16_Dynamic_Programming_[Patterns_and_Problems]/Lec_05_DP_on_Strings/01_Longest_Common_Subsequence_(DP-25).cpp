# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
private:
    int solveDP(string text1, string text2, int i, int j, vector<vector<int>> &dp, int m, int n) {
        if(i == m || j == n) return 0;

        if(dp[i][j] != -1 )return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = 1 + solveDP(text1, text2, i + 1, j + 1, dp, m, n);
        else return dp[i][j] = max(solveDP(text1, text2, i + 1, j, dp, m, n), solveDP(text1, text2, i, j + 1, dp, m, n));
    }

    int solveTab(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }

    int solveSO(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<int> curr (n + 1, 0);
        vector<int> next (n + 1, 0);

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(text1[i] == text2[j]) curr[j] = 1 + next[j + 1];
                else curr[j] = max(next[j], curr[j + 1]);
            }
            next = curr;
        }
        return next[0];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        // DP Solulu

        /*
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveDP(text1, text2, 0, 0, dp, m, n);
        */


        // Tabulation Solulu

        // return solveTab(text1, text2);


        // Space Optimized SOlulu
        
        return solveSO(text1, text2);
    }
};