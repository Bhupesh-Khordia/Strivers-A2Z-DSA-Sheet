# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // dp[i][j] = number of squares possible whose bottom right is (i, j);
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            ans += dp[i][0];
        }
        
        for (int j = 1; j < m; j++) {
            dp[0][j] = matrix[0][j];
            ans += dp[0][j];
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 1) {
                    // For each cell, check the minimum value among:
                    // 1. Left cell (dp[i][j-1])
                    // 2. Top cell (dp[i-1][j])
                    // 3. Top-left diagonal cell (dp[i-1][j-1])
                    // Add 1 to this minimum value
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
                ans += dp[i][j];
            }
        }
        
        return ans;
    }
};