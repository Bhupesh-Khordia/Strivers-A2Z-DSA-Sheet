# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-common-supersequence/description/

// Watch https://www.youtube.com/watch?v=xElxAuBcvsU for better understanding.

class Solution {
private:
    // Returns array Longest common subsequence length
    vector<vector<int>> solveTab(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1]; // 1 bases indexing
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp = solveTab(str1, str2);

        int m = str1.length();
        int n = str2.length();

        int i = m;
        int j = n;

        string ans = "";

        while(i > 0 && j > 0) { // 1 based indexing
            if(str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            } else if(dp[i][j - 1] > dp[i - 1][j]) {
                ans += str2[j - 1];
                j--;
            } else {
                ans += str1[i - 1];
                i--;
            }
        }

        while(i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while(j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};