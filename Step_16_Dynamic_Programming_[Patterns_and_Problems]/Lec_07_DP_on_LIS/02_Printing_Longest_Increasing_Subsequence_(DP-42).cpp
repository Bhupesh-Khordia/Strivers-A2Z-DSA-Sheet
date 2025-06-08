# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1

class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> dp(n, 1); // Will store length of LIS ending at each index
        vector<int> prev(n);  // Prev index in LIS (similar to parent array in trees)
        for(int i = 0; i < n; i++) prev[i] = i;

        int maxi = 1;
        int index = 0; // index where Longest LIS end
        for(int i = 0; i < n; i++) {
            for(int prevIndex = 0; prevIndex < i; prevIndex++) {
                if(arr[prevIndex] < arr[i]) {
                    // We can append arr[i] after arr[prevIndex]
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
            ans.push_back(arr[index]);
            index = prev[index];
        }
        ans.push_back(arr[index]);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};