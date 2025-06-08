# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-divisible-subset/description/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Kind of similar to print LIS (https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1)

        sort(nums.begin(), nums.end());

        int n = nums.size();
        
        vector<int> dp(n, 1); // Will store length of largest subset ending at each index
        vector<int> prev(n);  // Prev index in largest subset (similar to parent array in trees)
        for(int i = 0; i < n; i++) prev[i] = i;

        int maxi = 1;
        int index = 0; // index where largest subset end
        for(int i = 0; i < n; i++) {
            for(int prevIndex = 0; prevIndex < i; prevIndex++) {
                if(nums[i] % nums[prevIndex] == 0) {
                    // We can append nums[i] after nums[prevIndex]
                    if(1 + dp[prevIndex] > dp[i]) {
                        dp[i] = 1 + dp[prevIndex];
                        prev[i] = prevIndex;
                    }
                }
            }

            if(dp[i] > maxi) {
                maxi = dp[i];
                index = i;
            }
        }

        vector<int> ans;
        
        while(prev[index] != index) {
            ans.push_back(nums[index]);
            index = prev[index];
        }
        ans.push_back(nums[index]);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};