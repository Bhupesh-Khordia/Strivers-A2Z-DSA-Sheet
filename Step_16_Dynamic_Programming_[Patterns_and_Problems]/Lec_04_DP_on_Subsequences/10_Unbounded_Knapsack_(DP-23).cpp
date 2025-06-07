# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// User function Template for C++

class Solution {
  private:
    // Recursive Solution
    int solveRec(vector<int> weight, vector<int> value, int n, int maxWeight, int index, int currWeight){
        if(index >= n) return 0;
    
        int ans = 0;
    
        // Rob
        if(currWeight + weight[index] <= maxWeight) {
            ans = max(ans, value[index] + solveRec(weight, value, n, maxWeight, index, currWeight + weight[index])) ;
        }
    
        // Not rob
        ans = max(ans, solveRec(weight, value, n, maxWeight, index + 1, currWeight));
    
        return ans;
    }
    
    // Memoization Solution
    int solveDP(vector<int> weight, vector<int> value, int n, int maxWeight, int index, int currWeight, vector<vector<int>> &dp){
        if(index >= n) return 0;
    
        if(dp[index][currWeight] != -1) return dp[index][currWeight];
    
        int ans = 0;
    
        // Rob
        if(currWeight + weight[index] <= maxWeight) {
            ans = max(ans, value[index] + solveDP(weight, value, n, maxWeight, index, currWeight + weight[index], dp)) ;
        }
    
        // Not rob
        ans = max(ans, solveDP(weight, value, n, maxWeight, index + 1, currWeight, dp));
    
        return dp[index][currWeight] = ans;
    }
    
    
    int solveTab(vector<int> weight, vector<int> value, int n, int maxWeight) {
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    
        for(int wt = 0 ; wt <= maxWeight ; wt++){
            if (wt >= weight[0]) {
                dp[0][wt] = (wt / weight[0]) * value[0];
            }
        }
    
        for (int index = 1; index < n; index++) {
            for (int currWeight = 0; currWeight <= maxWeight; currWeight++) {
                int include = 0;
                if (currWeight - weight[index] >= 0) {
                    include = value[index] + dp[index][currWeight - weight[index]];
                }
                int exclude = 0 + dp[index - 1][currWeight];
                dp[index][currWeight] = max(include, exclude);
            }
        }
    
        return dp[n - 1][maxWeight];
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        
        // Recursion solution.
    
        // return solveRec(wt, val, n, capacity, 0, 0);
        
        
        // Memoization solution.
    
        // vector<vector<int>> dp (n + 1, vector<int> (capacity + 1, -1));
        // return solveDP(wt, val, n, capacity, 0, 0, dp);
    
    
        // Tabulation solution.
    
        return solveTab(wt, val, n, capacity);
        
        // Space optimization can be done same as simple 0-1 knapsack (https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)
    }
};