#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimal-cost/1

class Solution {
  private:
    int solve(vector<int> &height, vector<int> &dp, int index, int k) {
        if(index >= height.size() - 1) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int mini = INT_MAX;
        
        for(int jump = 1; jump <= k; jump++) {
            int cost = INT_MAX;
            if(index + jump < height.size())
                cost = solve(height, dp, index + jump, k) + abs(height[index] - height[index + jump]);
            
            mini = min(mini, cost);
        }
    
        return dp[index] = mini;
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        vector<int> dp (arr.size(), -1);
        return solve(arr, dp , 0, k);
    }
};