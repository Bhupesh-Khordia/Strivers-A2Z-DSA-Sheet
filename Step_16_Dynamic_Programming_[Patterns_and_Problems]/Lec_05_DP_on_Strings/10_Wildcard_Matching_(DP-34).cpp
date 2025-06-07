# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/wildcard-matching/description/

class Solution {
private:
    bool solveRec(string s, string p, int i, int j) {
        if(i == s.length() && j == p.length()) return true;

        if(j == p.length()) return false;
        // Check if the remaining pattern can be all '*'
        if (i == s.length()) {
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if(p[j] == '*') {
            // Include i in sequence
            bool option1 = solveRec(s, p, i + 1, j);
            // Dont Include i in sequence
            bool option2 = solveRec(s, p, i, j + 1);

            return option1 || option2;
        } else if (p[j] == '?' || s[i] == p[j]) {
            return solveRec(s, p, i + 1, j + 1);
        } else {
            return false;
        }
    }

    bool solveDP(string s, string p, int i, int j, vector<vector<int>> &dp) {
        if(i == s.length() && j == p.length()) return true;

        if(j == p.length()) return false;
        // Check if the remaining pattern can be all '*'
        if (i == s.length()) {
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == '*') {
            // Include i in sequence
            bool option1 = solveDP(s, p, i + 1, j, dp);
            // Dont Include i in sequence
            bool option2 = solveDP(s, p, i, j + 1, dp);

            return dp[i][j] = option1 || option2;
        } else if (p[j] == '?' || s[i] == p[j]) {
            return dp[i][j] = solveDP(s, p, i + 1, j + 1, dp);
        } else {
            return dp[i][j] = false;
        }
    }

    bool solveTab(string s, string p) {
        // If we start from end in DP solulu then...

        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];  // Match 1+ chars OR ignore '*'
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }

    bool solveSO(string s, string p) {
        int m = s.length(), n = p.length();
        vector<bool> prev(n + 1, false), curr(n + 1, false);

        prev[0] = true;

        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                prev[j] = prev[j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            curr[0] = false;
            
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[n];
    }
public:
    bool isMatch(string s, string p) {
        //Recursion Solulu

        // return solveRec(s, p, 0, 0);


        // DP solulu

        /*
        vector<vector<int>> dp(s.length(), vector<int> (p.length(), -1));
        return solveDP(s, p, 0, 0, dp);
        */


        // Tabulation Solulu

        // return solveTab(s, p);

        // Space Optimized SOlulu

        return solveSO(s, p);
    }
};