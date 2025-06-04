# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/geeks-training/1

class Solution {
  private:
    int solve(vector<vector<int>> &arr, vector<vector<int>> &dp, int index, int prev) {
        if(index == arr.size()) return 0;
        
        if(dp[index][prev] != -1) return dp[index][prev];
        
        int ans = INT_MIN;
        
        for(int i = 0; i < 3; i++) {
            if(i != prev) {
                ans = max(ans, arr[index][i] + solve(arr, dp, index + 1, i));
            }
        }
        
        return dp[index][prev] = ans;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int> (4, -1));
        return solve(arr, dp, 0, 3); // 3 to represent nothing is previously chosen
    }
};