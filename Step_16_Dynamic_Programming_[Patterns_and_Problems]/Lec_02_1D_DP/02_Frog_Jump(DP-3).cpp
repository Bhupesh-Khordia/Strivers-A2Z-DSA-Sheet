#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/geek-jump/1

class Solution {
  private:
    int solve(vector<int> &height, vector<int> &dp, int index) {
        if(index >= height.size() - 1) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int oneJump = solve(height, dp, index + 1) + abs(height[index] - height[index + 1]);
        int twoJump = INT_MAX;
        if(index + 2 < height.size())
            twoJump = solve(height, dp, index + 2) + abs(height[index] - height[index + 2]);
    
        return dp[index] = min(oneJump, twoJump);
    }
  public:
    int minCost(vector<int>& height) {
        vector<int> dp (height.size(), -1);
        return solve(height, dp , 0);
    }
};