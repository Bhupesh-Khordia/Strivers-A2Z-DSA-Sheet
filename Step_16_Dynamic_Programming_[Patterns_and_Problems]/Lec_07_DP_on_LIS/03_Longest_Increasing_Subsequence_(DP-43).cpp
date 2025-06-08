# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution {
  private:
    // Recursion Solulu
    int  solveRec(vector<int> &arr, int n, int currIndex, int prevIndex) {
        if(currIndex == n)  return  0;
        
        // Include
        int include = 0;
        if(prevIndex == -1 || arr[currIndex] > arr[prevIndex])  {
            include = 1 + solveRec (arr, n, currIndex + 1, currIndex);
        }
        
        // Exclude 
        int exclude = 0 + solveRec (arr, n, currIndex + 1, prevIndex);
        
        return max(include, exclude);
    }
    
    // DP Solulu
    int  solveDP(vector<int> &arr, int n, int currIndex, int prevIndex, vector<vector<int>> &dp) {
        if(currIndex == n)  return  0;
        
        // prevIndex + 1 is done for the case when prevIndex = -1
        if(dp[currIndex][prevIndex + 1]  != -1)  return dp[currIndex][prevIndex + 1];
        
        // Include
        int include = 0;
        if(prevIndex == -1 || arr[currIndex] > arr[prevIndex])  {
            include = 1 + solveDP (arr, n, currIndex + 1, currIndex, dp);
        }
        
        // Exclude 
        int exclude = 0 + solveDP (arr, n, currIndex + 1, prevIndex, dp);
        
        return dp[currIndex][prevIndex + 1] = max(include, exclude);
    }
    
    // Tabulation Solulu
    int solveTab(vector<int> &arr, int n) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        
        for(int currIndex = n - 1; currIndex >= 0; currIndex--) {
            for(int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                // Include
                int include = 0;
                if(prevIndex == -1 || arr[currIndex] > arr[prevIndex])  {
                    include = 1 + dp[currIndex + 1][currIndex + 1]; // Prev Index is used by increment of 1 so, currIndex + 1 will be used as prev.
                }
                
                // Exclude 
                int exclude = 0 + dp[currIndex + 1][prevIndex + 1];  // prevIndex + 1 to ensure case of -1
                
                dp[currIndex][prevIndex + 1] = max(include, exclude);
            }
        }
        
        return dp[0][0];
    }
    
    
    // Space Optimized Solulu
    int solveSO(vector<int> &arr, int n) {
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        for(int currIndex = n - 1; currIndex >= 0; currIndex--) {
            for(int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                // Include
                int include = 0;
                if(prevIndex == -1 || arr[currIndex] > arr[prevIndex])  {
                    include = 1 + next[currIndex + 1]; // Prev Index is used by increment of 1 so, currIndex + 1 will be used as prev.
                }
                
                // Exclude 
                int exclude = 0 + next[prevIndex + 1];  // prevIndex + 1 to ensure case of -1
                
                curr[prevIndex + 1] = max(include, exclude);
            }
            next = curr;
        }
        
        return next[0];
    }

    // T.C - O(n ^ 2) --> This method (with little modification) is used when we want to print the LIS    
    int solveSingle(vector<int> &arr, int n) {
        vector<int> dp(n, 1); // Will store length of LIS ending at each index

        int maxi = 1;
        for(int i = 0; i < n; i++) {
            for(int prevIndex = 0; prevIndex < i; prevIndex++) {
                if(arr[prevIndex] < arr[i]) {
                    // We can append arr[i] after arr[prevIndex]
                    dp[i] = max(dp[i], 1 + dp[prevIndex]);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }

    // DP With Binary Search Solulu (Best) (TC - O(N * log N), SC -O(N))
    int solveDPWithBS(vector<int> &arr, int n) {
        vector<int> ans;
        ans.push_back(arr[0]);
        
        for(int i = 1; i < n; i++ ) {
            if(arr[i] > ans.back()) {
                ans.push_back(arr[i]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        
        return ans.size();
    }
    
  public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        
        // Recursive Solulu
        
        // return solveRec(arr, n, 0,  -1);
        
        
        // DP Solulu
        
        // vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        // return solveDP(arr, n, 0, -1, dp);
        
        
        // Tabulation Solulu
        
        // return solveTab(arr, n);
        
        
        
        // Space Optimized Solulu
        
        // return solveSO(arr,  n);


        // Single array solution (O(n^2)) (Useful if we want to print longest LIS)
        // https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1

        // return solveSingle(arr, n);
        
        
        
        // DP With Binary Search Solulu (Best) (TC - O(N * log N), SC -O(N))
        
        return solveDPWithBS (arr, n);
    }
};