#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/chocolates-pickup/1

class Solution {
  private:
    int solveDP(vector<vector<int>> &grid, int n, int m, int robo1, int robo2, int index, 
                vector<vector<vector<int>>> &dp) {
        if(index == n) return 0;
        
        if(robo1 < 0 || robo1 >= m || robo2 < 0 || robo2 >= m) return 0;
        
        if(dp[index][robo1][robo2] != -1) return dp[index][robo1][robo2];
        
        if(robo1 == robo2) return dp[index][robo1][robo2] = grid[index][robo1] + solveDP(grid, n, m, robo1, robo2, index + 1, dp);
        
        vector<int> direction = {-1, 0, 1};
        
        
        int maxi = INT_MIN;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                maxi = max(maxi, solveDP(grid, n, m, robo1 + direction[i], robo2 + direction[j], index + 1, dp));
            }
        }
        
        return dp[index][robo1][robo2] = grid[index][robo1] + grid[index][robo2] + maxi;
    }
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        // index, robo1, robo2
        return solveDP(grid, n, m, 0, m - 1, 0, dp);
    }
};