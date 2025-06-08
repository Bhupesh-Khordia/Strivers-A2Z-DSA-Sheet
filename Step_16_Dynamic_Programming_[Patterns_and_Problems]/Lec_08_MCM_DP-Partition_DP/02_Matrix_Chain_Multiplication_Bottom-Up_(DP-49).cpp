#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
  private:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        if(j == i) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k = i; k <= j - 1; k++) {
            // Partition at k
            int multiplications = arr[i - 1] * arr[k] * arr[j];
            mini = min(mini, multiplications + solve(arr, i, k, dp) + solve(arr, k + 1, j, dp));
        }
        
        return dp[i][j] = mini;
    }
    
    int solveTab(vector<int> &arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                int mini = INT_MAX;
                for(int k = i; k <= j - 1; k++) {
                    // Partition at k
                    int multiplications = arr[i - 1] * arr[k] * arr[j];
                    mini = min(mini, multiplications + dp[i][k] + dp[k + 1][j]);
                }
                
                dp[i][j] = mini;
            }
        }
        
        return dp[1][n -1];
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // Top Down
        /*
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(arr, 1, n - 1, dp);
        */
        
        // Bottom Up
        
        return solveTab(arr);
    }
};