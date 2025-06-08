# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1); // Will store length of LIS ending at each index
        vector<int> cnt(n, 1);

        int maxi = 1;
        for(int i = 0; i < n; i++) {
            for(int prevIndex = 0; prevIndex < i; prevIndex++) {
                if(nums[prevIndex] < nums[i]) {
                    // We can append nums[i] after nums[prevIndex]
                    if(1 + dp[prevIndex] > dp[i]) {
                        cnt[i] = cnt[prevIndex];
                        dp[i] = 1 + dp[prevIndex];
                    } else if (1 + dp[prevIndex] == dp[i]) {
                        cnt[i] += cnt[prevIndex];
                    }
                }
            }

            maxi = max(maxi, dp[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi) ans += cnt[i];
        }

        return ans;
    }
};