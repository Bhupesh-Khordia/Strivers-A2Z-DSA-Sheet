#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
private:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col) {
        int n = matrix.size();

        if (col < 0 || col >= n) return INT_MAX;
        if (row == n - 1) return matrix[row][col];
        if (dp[row][col] != -1) return dp[row][col];

        int down = solve(matrix, dp, row + 1, col);
        int leftDiag = solve(matrix, dp, row + 1, col - 1);
        int rightDiag = solve(matrix, dp, row + 1, col + 1);

        return dp[row][col] = matrix[row][col] + min({down, leftDiag, rightDiag});
    }

    int solveTab(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }

        for(int i = n - 2; i>= 0; i--) {
            for(int j = 0; j < n; j++) {
                int mini = INT_MAX;;

                if(j + 1 < n) mini = min(mini, dp[i + 1][j + 1]);
                mini = min(mini, dp[i + 1][j]);
                if(j - 1 >= 0) mini = min(mini, dp[i + 1][j - 1]);

                dp[i][j] = matrix[i][j] + mini;
            }
        }

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            ans = min(ans, dp[0][i]);
        }

        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Recursive Solution
        /*
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, solve(matrix, dp, 0, j));
        }
        return result;
        */

        // Tabulation Solution
        return solveTab(matrix);
    }
};