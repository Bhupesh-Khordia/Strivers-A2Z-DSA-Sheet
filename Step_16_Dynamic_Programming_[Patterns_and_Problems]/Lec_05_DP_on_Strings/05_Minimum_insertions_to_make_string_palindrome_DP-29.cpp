# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

class Solution {
private:
    int solve(string s, int i, int j, vector<vector<int>> &dp) {
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = solve(s, i + 1, j - 1, dp);
        else {
            // Insert left side which would be equal to s[j]
            int option1 = solve(s, i, j - 1, dp);

            // Insert right side which would be equal to s[i]
            int option2 = solve(s, i + 1, j, dp);

            return dp[i][j] = 1 + min(option1, option2);
        }
    }

    int solveTab(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else {
                    // Insert left side which would be equal to s[j]
                    int option1 = dp[i][j - 1];

                    // Insert right side which would be equal to s[i]
                    int option2 = dp[i + 1][j];

                    dp[i][j] = 1 + min(option1, option2);
                }
            }
        }

        return dp[0][n - 1];
    }
public:
    int minInsertions(string s) {
        // Top down DP (Gives MLE)
        /*
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(s, 0, n - 1, dp);
        */


        // Bottom Up DP
        return solveTab(s);
    }
};