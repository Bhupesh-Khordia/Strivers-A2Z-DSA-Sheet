# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/burst-balloons/description/

class Solution {
private:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if(j <= i + 1) return 0; // No element in between

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;

        for(int ind = i + 1; ind < j; ind++) { // This baloon will be last to burst in this interval
            int coins = nums[i] * nums[ind] * nums[j];
            maxi = max(maxi, coins + solve(i, ind, nums, dp) + solve(ind, j, nums, dp));
        }

        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        vector<vector<int>> dp(nums.size() + 1, vector<int> (nums.size() + 1, -1));
        return solve(0, nums.size() - 1, nums, dp);
    }
};