# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

class Solution {
  private:
    int solve(vector<int> &arr, int index, int target, vector<vector<int>> &dp) {
        // if (index == 0) {
        //     if (target == 0 && arr[0] == 0) return 2;  // choose or not choose 0
        //     if (target == 0 || target == arr[0]) return 1;
        //     return 0;
        // }
        
        // OR use this one
        
        if(index == -1) return target == 0;

        if (dp[index][target] != -1) return dp[index][target];

        int notTake = solve(arr, index - 1, target, dp);
        int take = 0;
        if (arr[index] <= target)
            take = solve(arr, index - 1, target - arr[index], dp);

        return dp[index][target] = (take + notTake);
    }
    
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Recursive Solution
        
        /*
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if (totalSum < d || (totalSum + d) % 2 != 0) return 0;
        
        // sum1 - sum2 = d
        // sum1 - (totalSum - sum1) = d
        // sum1 = (totalSum + d) / 2
        int target = (totalSum + d) / 2;
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));

        return solve(arr, arr.size() - 1, target, dp);
        */
        
        
        
        // Tabulation Solution
        
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // Check if it's possible to form required subset sum
        if (totalSum < d || (totalSum + d) % 2 != 0) return 0;
        
        int target = (totalSum + d) / 2;
        
        vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, 0));
        
        // Base case: 1 way to make sum 0 (by choosing nothing)
        for(int i = 0; i <= arr.size(); i++) dp[i][0] = 1;

        for (int i = 1; i <= arr.size(); i++) {
            for (int sum = 0; sum <= target; sum++) {
                if (sum >= arr[i - 1])
                    dp[i][sum] = dp[i - 1][sum] + dp[i - 1][sum - arr[i - 1]];
                else
                    dp[i][sum] = dp[i - 1][sum];
            }
        }

        return dp[arr.size()][target];
    }
};