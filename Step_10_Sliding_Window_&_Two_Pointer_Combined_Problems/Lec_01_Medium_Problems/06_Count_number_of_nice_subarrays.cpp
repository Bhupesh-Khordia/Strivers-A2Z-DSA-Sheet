// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int numberOfSubarraysWithLTEKOdds (vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), ans = 0;
        int noOfOdds = 0;
        while(r < n) {
            if(nums[r] & 1) noOfOdds++;

            while(noOfOdds > k) {
                if(nums[l] & 1) noOfOdds--;
                l++;
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysWithLTEKOdds(nums, k) - numberOfSubarraysWithLTEKOdds(nums, k - 1);
    }
};