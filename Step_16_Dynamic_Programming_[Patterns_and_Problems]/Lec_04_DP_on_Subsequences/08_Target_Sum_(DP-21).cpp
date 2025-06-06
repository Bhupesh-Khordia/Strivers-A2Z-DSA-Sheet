# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/target-sum/description/

class Solution {
private:
    int solve(vector<int>& nums, int target, int index, vector<vector<int>> &dp) {
        if(index == 0) {
            if(nums[0] == 0 && target == 0) return 2;
            if(target - nums[0] == 0 || target + nums[0] == 0) return 1;
            return 0;
        }

        if(dp[index][target] != -1) return dp[index][target];

        int option1 = solve(nums, target + nums[index], index - 1, dp);
        int option2 = solve(nums, target - nums[index], index - 1, dp);

        return dp[index][target] = option1 + option2;
    }

    int solveDP(vector<int> &arr, int index, int target, vector<vector<int>> &dp) {
        // if (index == 0) {
        //     if (target == 0 && arr[0] == 0) return 2;  // choose or not choose 0
        //     if (target == 0 || target == arr[0]) return 1;
        //     return 0;
        // }
        
        // OR use this one
        
        if(index == -1) return target == 0;

        if (dp[index][target] != -1) return dp[index][target];

        int notTake = solveDP(arr, index - 1, target, dp);
        int take = 0;
        if (arr[index] <= target)
            take = solveDP(arr, index - 1, target - arr[index], dp);

        return dp[index][target] = (take + notTake);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // This does not work because target's index in dp array can be negative as well.
        /*
        vector<vector<int>> dp(nums.size() + 1, vector<int> (1001, -1));
        return solve(nums, target, nums.size() - 1, dp);
        */


        //2. 
        // Get no. of possible pairs of subsets with difference = target.
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum < abs(target) || (totalSum + target) % 2 != 0) return 0;

        // sum1 - sum2 = d (d is the required difference)
        // sum1 - (totalSum - sum1) = d
        // sum1 = (totalSum + d) / 2
        int subsetSum = (totalSum + target) / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(subsetSum + 1, -1));
        return solveDP(nums, nums.size() - 1, subsetSum, dp);
    }
};