# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/coin-change-ii/description/

class Solution {
private:
    int solve (vector<int> &coins, int amount, int i, vector<vector<int>> &dp) {
        if (i == coins.size()) return amount == 0 ? 1 : 0;
        if (dp[i][amount] != -1) return dp[i][amount];

        // exclude current coin
        int notTake = solve(coins, amount, i + 1, dp);

        // include current coin
        int take = 0;
        if (coins[i] <= amount)
            take = solve(coins, amount - coins[i], i, dp);

        return dp[i][amount] = take + notTake;
    }

    int solveTab(vector<int> &coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amt + 1, 0));
        dp[n][0] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int amount = 0; amount <= amt; amount++) {
                dp[i][amount] =  dp[i + 1][amount];
                if(amount - coins[i] >= 0)
                    dp[i][amount] += dp[i][amount-coins[i]];
            }
        }

        return dp[0][amt];
    }
public:
    int change(int amount, vector<int>& coins) {
        // Recursive Solution
        
        // vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, -1));
        // return solve(coins, amount, 0, dp);
    
        
        
        // Tabulation Solution (runtime error on leetcode)

        return solveTab(coins, amount);
    }
};