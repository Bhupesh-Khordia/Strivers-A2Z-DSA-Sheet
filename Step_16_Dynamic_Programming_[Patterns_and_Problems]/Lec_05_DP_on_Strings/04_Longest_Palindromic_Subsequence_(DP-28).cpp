# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
private:
    int solveDP(string str1, string str2, int i, int j, vector<vector<int>> &dp, int m, int n) {
        if(i == m || j == n) return 0;

        if(dp[i][j] != -1 )return dp[i][j];

        if(str1[i] == str2[j]) return dp[i][j] = 1 + solveDP(str1, str2, i + 1, j + 1, dp, m, n);
        else return dp[i][j] = max(solveDP(str1, str2, i + 1, j, dp, m, n), solveDP(str1, str2, i, j + 1, dp, m, n));
    }

    int solveTab(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(str1[i] == str2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }

    int solveSO(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<int> curr (n + 1, 0);
        vector<int> next (n + 1, 0);

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(str1[i] == str2[j]) curr[j] = 1 + next[j + 1];
                else curr[j] = max(next[j], curr[j + 1]);
            }
            next = curr;
        }
        return next[0];
    }
public:
    int longestPalindromeSubseq(string s) {
        // Create a second string (reverse of s) and find longest common subsequence.
        string s2 = s;
        reverse(s2.begin(), s2.end());


        // DP Solulu

        /*
        int m = s.length();
        int n = s2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveDP(s, s2, 0, 0, dp, m, n);
        */


        // Tabulation Solulu

        // return solveTab(s, s2);


        // Space Optimized SOlulu
        
        return solveSO(s, s2);
    }
};