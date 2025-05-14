// https://leetcode.com/problems/binary-subarrays-with-sum/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
private:
    int numSubarraysWithLTESum(vector<int> &nums, int goal) {
        int l = 0, r = 0, n = nums.size(), ans = 0;
        int sum = 0;
        while(r < n) {
            sum += nums[r];

            while(sum > goal && l <= r) {
                sum -= nums[l];
                l++;
            }

            ans += r - l + 1;  // Every smaller subarray will also have sum less than equal to goal.
            r++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithLTESum(nums, goal) - numSubarraysWithLTESum(nums, goal - 1);
    }
};