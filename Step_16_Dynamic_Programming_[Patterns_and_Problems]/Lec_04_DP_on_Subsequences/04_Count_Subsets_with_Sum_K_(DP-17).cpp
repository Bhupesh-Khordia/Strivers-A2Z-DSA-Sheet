# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution {
  private:
    void count(vector<int> &arr, int target, int index, int &cnt, int sum) {
        if(index == arr.size()) {
            if(sum == target)
                cnt++;
            return;
        }
        
        if(sum > target) return;
        
        // Include 
        count(arr, target, index + 1, cnt, sum + arr[index]);
        
        // Exclude
        count(arr, target, index + 1, cnt, sum);
    }
    
    // DP
    int countDP(vector<int> &arr, int target, int index, int sum, vector<vector<int>> &dp) {
        if(sum > target) return 0;
    
        if(index == arr.size()) {
            return (sum == target) ? 1 : 0;
        }
    
        if(dp[index][sum] != -1) return dp[index][sum];
    
        int take = countDP(arr, target, index + 1, sum + arr[index], dp);
        int notTake = countDP(arr, target, index + 1, sum, dp);
    
        return dp[index][sum] = take + notTake;
    }

    
  public:
    int perfectSum(vector<int>& arr, int target) {
        /*
        int cnt = 0;
        count(arr, target, 0, cnt, 0);
        return cnt;
        */
        
        vector<vector<int>> dp(arr.size() + 1, vector<int> (target + 1, -1));
        return countDP(arr, target, 0, 0, dp);
    }
};