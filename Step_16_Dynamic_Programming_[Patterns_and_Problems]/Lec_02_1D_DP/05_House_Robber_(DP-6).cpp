#include <bits/stdc++.h>
using namespace std;

/// https://leetcode.com/problems/house-robber-ii/description/

class Solution {

private:

    // This function is copied from - Maximum sum of non-adjacent elements


    // Space Optimized - O(1)
    int solve(vector<int> &nums, int start, int end) {
        int prev1 = 0, prev2 = 0;

        for(int i = start; i <= end; i++) {
            int ans = max(prev1 + nums[i - 1], prev2);
            prev1 = prev2;
            prev2 = ans;

        }
        return prev2;

    }

public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    
    if(n == 1) return nums[0];
    else return max(solve(nums, 1, n - 1), solve(nums, 2, n));
    }
};