#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber/description/

// Maximum non adjacent subarray sum

class Solution {
private:

    // Recursive DP
    int solveDP(vector<int> &nums, int index, vector<int> &dp) {
        if(index >= nums.size()) return 0;

        if(dp[index] != -1) return dp[index];
        
        // Include 
        int ans1 = solveDP(nums, index + 2, dp) + nums[index];

        // Exclude 
        int ans2 = solveDP(nums, index + 1, dp);

        return dp[index] = max(ans1, ans2);
    }

    // Tabulation
    int solveTab(vector<int> &nums) {
        vector<int> dp(nums.size() + 5, -1);

        dp[0] = 0;

        // In the first iteration negative index is accessed but no error. Why ?
        /*

        if vector is initialized with defined size then it will give zero 
        vector<int> temp(10)
        temp[-1]  will give zero
        vector<int> temp(10,-1)
        temp[-1] will give zero
        vector<int> temp
        temp[-1] will give segmentation falult

        */
        for(int i = 1; i <= nums.size(); i++) {
            dp[i] = max(dp[i-2] + nums[i - 1], dp[i-1]);
        }
        return dp[nums.size()];

    }

    // Space Optimized - O(1)
    int solveSO(vector<int> &nums) {
        int prev1 = 0, prev2 = 0;

        for(int i = 1; i <= nums.size(); i++) {
            int ans = max(prev1 + nums[i - 1], prev2);
            prev1 = prev2;
            prev2 = ans;
        }
        return prev2;

    }

public:
    int rob(vector<int>& nums) {
    // Recursive DP approach


    // vector<int> dp(nums.size() + 1, -1);
    // return solveDP(nums, 0, dp);



    // Tabulation Approach

    // return solveTab(nums);


    // Space Optimized

    return solveSO(nums);
    }
};