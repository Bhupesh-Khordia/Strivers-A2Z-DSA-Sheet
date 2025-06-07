# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/edit-distance/description/

class Solution {
private:
    int solveDP(string word1, string word2, int i, int j, vector<vector<int>> &dp, int m, int n) {
        if(i == m) return n - j;
        if(j == n) return m - i;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        if(word1[i] == word2[j]) ans = solveDP(word1, word2, i + 1, j + 1, dp, m, n);
        else {
            // Insert
            ans = min(ans, solveDP(word1, word2, i, j + 1, dp, m, n) + 1);
            // Replace
            ans = min(ans, solveDP(word1, word2, i + 1, j + 1, dp, m, n) + 1);
            // Delete
            ans = min(ans, solveDP(word1, word2, i + 1, j, dp, m, n) + 1);
        }
        return dp[i][j] = ans;
    }

    int solveTab(string word1, string word2, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));

        for(int j = 0; j <= n; j++) {
            dp[m][j] = n - j;
        }
        for(int i = 0; i <= m; i++) {
            dp[i][n] = m - i;
        }

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int ans = INT_MAX;
                if(word1[i] == word2[j]) ans = dp[i + 1][j + 1];
                else {
                    // Insert
                    ans = min(ans, dp[i][j + 1] + 1);
                    // Replace
                    ans = min(ans, dp[i + 1][j + 1] + 1);
                    // Delete
                    ans = min(ans, dp[i + 1][j] + 1);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveSO(string word1, string word2, int m, int n) {
        // vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        vector<int> curr (n + 1, 0);
        vector<int> next (n + 1, 0);

        for(int j = 0; j <= n; j++) {
            next[j] = n - j;
        }
        // for(int i = 0; i <= m; i++) {
        //     dp[i][n] = m - i;
        // }

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                // Base Case
                curr[n] = m - i;
                int ans = INT_MAX;
                if(word1[i] == word2[j]) ans = next[j + 1];
                else {
                    // Insert
                    ans = min(ans, curr[j + 1] + 1);
                    // Replace
                    ans = min(ans, next[j + 1] + 1);
                    // Delete
                    ans = min(ans, next[j] + 1);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if(m == 0) return n;
        if(n == 0) return m;


        // DP Solulu

        /*
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solveDP(word1, word2, 0, 0, dp, m, n);
        */

        // Tabulation Solulu

        // return solveTab(word1, word2, m, n);


        // Space Optimized Solulu

        return solveSO(word1, word2, m, n);
    }
};