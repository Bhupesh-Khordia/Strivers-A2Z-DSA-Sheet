# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
private:
    int solveDP(int index, int buy, vector<int>& prices, vector<vector<int>> &dp) {
        if (index == prices.size()) 
            return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if (buy == 1) {
            int buyKaro = -prices[index] + solveDP(index + 1, 0, prices, dp);
            int skipKaro = 0 + solveDP(index + 1, 1, prices, dp);
            profit = max(buyKaro, skipKaro);
        } else if (buy == 0) {
            int sellKaro = prices[index] + solveDP(index + 1, 2, prices, dp); // go to colldown 
            int skipKaro = 0 + solveDP(index + 1, 0, prices, dp);
            profit = max(sellKaro, skipKaro);
        } else {
            // cooldown
            profit = 0 + solveDP(index + 1, 1, prices, dp);
        }
        return dp[index][buy] = profit;
    }

    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 2; buy++) {

                int profit = 0;
                if (buy == 1) {
                    int buyKaro = -prices[index] + dp[index + 1][0];
                    int skipKaro = 0 + dp[index + 1][1];
                    profit = max(buyKaro, skipKaro);
                } else if (buy == 0) {
                    int sellKaro = prices[index] + dp[index + 1][2];
                    int skipKaro = 0 + dp[index + 1][0];
                    profit = max(sellKaro, skipKaro);
                } else {
                    // cooldown
                    profit = 0 + dp[index + 1][1];
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        // buy = 0 --> we currently hold no stock, can either buy or skip 
        // buy = 1 --> we currently hold a stock, can either sell or skip 
        // buy = 2 --> we currently are on cooldown, can only skip 


        // Recursion Solulu

        /*
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        
        return solveDP(0, 1, prices, dp);

        */

        // Tabulation Solulu

        return solveTab(prices);
    }
};