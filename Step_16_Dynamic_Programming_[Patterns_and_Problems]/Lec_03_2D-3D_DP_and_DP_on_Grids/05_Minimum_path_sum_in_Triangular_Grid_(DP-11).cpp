#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/triangle/description/

class Solution {
private:
    int solve(vector<vector<int>>& triangle, vector<vector<int>> &dp, int index, int prevIdx) {
        if(index == triangle.size()) return 0;

        if(prevIdx == -1) return triangle[index][0] + solve(triangle, dp, index + 1, 0);

        if(dp[index][prevIdx] != -1) return dp[index][prevIdx];

        int choice1 = triangle[index][prevIdx] + solve(triangle, dp, index + 1, prevIdx);
        int choice2 = triangle[index][prevIdx + 1] + solve(triangle, dp, index + 1, prevIdx + 1);

        return dp[index][prevIdx] = min(choice1, choice2);
    }

    int solveTab(vector<vector<int>>& triangle) {
        vector<int> next(triangle.size() + 1, 0);
        vector<int> curr(triangle.size() + 1, -1);
        for(int i = triangle.size() - 1; i >= 0; i--) {
            for(int col = triangle[i].size() - 1; col >= 0; col--) {
                curr[col] = min(next[col], next[col + 1]) + triangle[i][col];
            }
            next = curr;
        }
        return next[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return solve(triangle, dp, 0, -1);
    
        return solveTab(triangle);
    }
};