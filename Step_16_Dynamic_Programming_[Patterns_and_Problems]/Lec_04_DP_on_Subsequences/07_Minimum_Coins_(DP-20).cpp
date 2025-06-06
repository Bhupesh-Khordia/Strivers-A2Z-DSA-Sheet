# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/coin-change/description/

class Solution {
private:

    int solver (vector<int> &num, int x) {
        
        if(x == 0) return 0;

        int ans = INT_MAX;

        if(x < 0) return ans;

        for(auto i : num) {
            int mini = min(ans, solver(num, x-i));
            if(mini != INT_MAX)
                ans = min(1 + mini, ans);
        }

        return ans;
    }

    int solverDP (vector<int> &num, int x, vector<int> &dp) {
        
        if(x == 0) return 0;

        if(dp[x] != -1) {
            return dp[x];
        }

        int ans = INT_MAX;

        if(x < 0) return ans;

        for(auto i : num) {
            int mini = min(ans, solverDP(num, x-i, dp));
            if(mini != INT_MAX)
                ans = min(1 + mini, ans);
        }

        return dp[x] = ans;
    }


    // Tabulation Approach

    int solverTab (vector<int>& num, int x) {
        vector<int> dp(x + 1, INT_MAX);
        
        // Base Case
        dp[0] = 0;

        for(int i = 0; i <= x; i++) {
            for(auto j : num) {
                if(i-j >=0 && dp[i - j] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i-j]);
            }
        }

        return dp[x];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // Recursive Approah.

        // int ans = solver(coins, amount);
        // return ans == INT_MAX ? -1 : ans;


        // DP Approach.

        // vector<int> dp (amount + 1, -1);
        // int ans = solverDP(coins, amount, dp);
        // return ans == INT_MAX ? -1 : ans;


        // Tabulation Approach.

        int ans = solverTab(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};