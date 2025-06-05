# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
private :
    // Recursion Solulu
    bool solveRec(vector<int>& nums, int index, int target, int n) {
        // Base cases
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(index >= n) return 0;

        // Include 
        bool include = solveRec(nums, index + 1, target - nums[index], n);

        // Exclude
        bool exclude = solveRec(nums, index + 1, target - 0, n);

        return include || exclude ; // Logical OR
    }


    // DP Solulu
    bool solveDP(vector<int>& nums, int index, int target, int n, vector<vector<int>> &dp) {
        // Base cases
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(index >= n) return 0;

        if(dp[index][target] != -1) return dp[target][index];

        // Include 
        bool include = solveDP(nums, index + 1, target - nums[index], n, dp);

        // Exclude
        bool exclude = solveDP(nums, index + 1, target - 0, n, dp);

        return dp[index][target] = include || exclude ; // Logical OR
    }

    // Tabultation Solulu

    bool solveTab(vector<int> &nums, int n, int totalSum) {
        vector<vector<int>> dp (n + 1, vector<int> ((totalSum / 2) + 1, 0));

        // Base Case
        for(int i = 0; i < dp.size(); i++) {
            dp[i][0] = 1;
        }

        for(int index = n - 1; index >= 0; index--) {
            for(int target = 0; target <= totalSum / 2; target++) {
                // Include 
                bool include = 0;
                if(target - nums[index] >= 0)
                    include = dp[index + 1][target - nums[index]];

                // Exclude
                bool exclude = dp[index + 1][target - 0];

                dp[index][target] = include || exclude ; // Logical OR
            }
        }

        return dp[0][totalSum/2];
    }

    // Space Optimized Solulu
    bool solveSO(vector<int> &nums, int n, int totalSum) {
        // vector<vector<int>> dp (n + 1, vector<int> ((totalSum / 2) + 1, 0));
        vector<int> curr (totalSum/2 + 1, 0);
        vector<int> next (totalSum/2 + 1, 0);

        // Base Case
        curr[0] = 1;
        next[0] = 1;

        for(int index = n - 1; index >= 0; index--) {
            for(int target = 0; target <= totalSum / 2; target++) {
                // Include 
                bool include = 0;
                if(target - nums[index] >= 0)
                    include = next[target - nums[index]];

                // Exclude
                bool exclude = next[target - 0];

                curr[target] = include || exclude ; // Logical OR
            }
            next = curr;
        }

        return curr[totalSum/2];
    }

public:
    bool canPartition(vector<int>& nums) {
        // Find a subset of array with sum = total sum of array / 2 using inclusion-exclusion
        int totalSum = 0;
        for(auto i : nums) {
            totalSum += i;
        }
        int target = totalSum / 2;
        if(totalSum % 2 != 0) return false;

        int n = nums.size();


        //Recursion Solulu

        // return solveRec(nums, 0, target, n);


        // DP Solulu

        // vector<vector<int>> dp (n + 1, vector<int> (target + 1, -1));
        // return solveDP(nums, 0, target, n, dp);

        
        // Tabulation Solulu

        // return solveTab(nums, n, totalSum);


        // Space Optimized Solulu

        return solveSO(nums, n, totalSum);
    }
};