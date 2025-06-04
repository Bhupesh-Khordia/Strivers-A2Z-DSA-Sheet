#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp, int m, int n) {
        if(i == m - 1 && j == n - 1) return grid[i][j];
        if(i >= m || j >= n) return INT_MAX;

        if(dp[i][j] != - 1) return dp[i][j];

        int right = solve(grid, i, j + 1, dp, m, n);
        int bottom = solve(grid, i + 1, j, dp, m, n);

        return dp[i][j] = grid[i][j] + min(right, bottom);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(grid, 0, 0, dp, m, n);
    }
};