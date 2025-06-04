#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/description/

class Solution {
private:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>> &dp, int m, int n) {
        if(i == m - 1 && j == n - 1) return 1;
        if(i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;

        if(dp[i][j] != - 1) return dp[i][j];

        int right = solve(obstacleGrid, i, j + 1, dp, m, n);
        int bottom = solve(obstacleGrid, i + 1, j, dp, m, n);

        return dp[i][j] = right + bottom;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m -1][n -1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(obstacleGrid, 0, 0, dp, m, n);
    }
};