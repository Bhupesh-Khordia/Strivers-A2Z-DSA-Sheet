#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
  private:
    // DP
    bool countDP(vector<int> &arr, int target, int index, int sum, vector<vector<int>> &dp) {
        if(sum > target) return false;
    
        if(index == arr.size()) {
            return (sum == target) ? true : false;
        }
    
        if(dp[index][sum] != -1) return dp[index][sum];
    
        int take = countDP(arr, target, index + 1, sum + arr[index], dp);
        int notTake = countDP(arr, target, index + 1, sum, dp);
    
        return dp[index][sum] = take | notTake;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp(arr.size() + 1, vector<int> (sum + 1, -1));
        return countDP(arr, sum, 0, 0, dp);
    }
};