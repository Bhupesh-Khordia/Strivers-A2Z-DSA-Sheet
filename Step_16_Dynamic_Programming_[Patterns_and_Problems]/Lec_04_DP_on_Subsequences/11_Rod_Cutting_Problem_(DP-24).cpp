# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/rod-cutting0840/1



class Solution {
  private:
    int solve(vector<int> &prices, int size, vector<int> &dp) {
        if(size <= 0) return 0;
            
        if(dp[size] != -1) return dp[size];
        
        int ans = INT_MIN;
        
        for(int i = 1; i <= size; i++) { // Current cut size
            ans = max(ans, prices[i - 1] + solve(prices, size - i, dp));
        }
        return dp[size] = ans;
    }
  public:
    int cutRod(vector<int> &price) {
        vector<int> dp(price.size()  + 1, -1);
        return solve(price, price.size(), dp);
    }
};