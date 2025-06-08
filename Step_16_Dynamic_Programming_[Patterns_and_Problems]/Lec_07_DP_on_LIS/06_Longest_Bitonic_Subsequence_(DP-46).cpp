# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1


class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // Similar to LIS - https://leetcode.com/problems/longest-increasing-subsequence/description/

        
        vector<int> dpI(n, 1); // Will store length of LIS ending at each index

        for(int i = 0; i < n; i++) {
            for(int prevIndex = 0; prevIndex < i; prevIndex++) {
                if(nums[prevIndex] < nums[i]) {
                    // We can append nums[i] after nums[prevIndex]
                    dpI[i] = max(dpI[i], 1 + dpI[prevIndex]);
                }
            }

        }

        
        vector<int> dpD(n, 1); // Will store length of LDS starting at each index

        for(int i = n - 1; i >= 0; i--) {
            for(int nextIndex = n - 1; nextIndex > i; nextIndex--) {
                if(nums[nextIndex] < nums[i]) {
                    // We can append nums[nextIndex] after nums[i]
                    dpD[i] = max(dpD[i], 1 + dpD[nextIndex]);
                }
            }
        }

        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(dpI[i] != 1 && dpD[i] != 1) { // Otherwise it will not be bitonic (according to note in question)
                ans = max(ans, dpI[i] + dpD[i] - 1);  // -1 to avoid double counting of ith element
            }
        }
        
        return ans;
    }
};
