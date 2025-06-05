#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
  private:
    // DP
    bool countDP(vector<int> &arr, int target, int index, int sum, vector<vector<bool>> &dp) {
        if(sum > target) return false;
    
        if(index == arr.size()) {
            return (sum == target) ? true : false;
        }
    
        if(dp[index][sum] != -1) return dp[index][sum];
    
        bool take = countDP(arr, target, index + 1, sum + arr[index], dp);
        bool notTake = countDP(arr, target, index + 1, sum, dp);
    
        return dp[index][sum] = take | notTake;
    }
    
    bool solveTab(vector<int> &arr, int target) {
        int n = arr.size();
        
        vector<vector<bool>> dp(n + 1, vector<bool> (target + 1, false));
        
        for (int i = 0; i <= n; i++) dp[i][target] = true;
        
        for (int index = n - 1; index >= 0; index--) {
            for(int sum = target; sum >= 0; sum--) {
                bool take = false;
                if(sum + arr[index] <= target)
                    take = dp[index + 1][sum + arr[index]];
                bool notTake = dp[index + 1][sum];
                dp[index][sum] = take | notTake;
            }
        }
        
        return dp[0][0];
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // Recursive Memoization solution
        /*
        vector<vector<bool>> dp(arr.size() + 1, vector<bool> (sum + 1, -1));
        return countDP(arr, sum, 0, 0, dp);
        */
        
        
        // Tabulation Solution
        return solveTab(arr, sum);
    }
};