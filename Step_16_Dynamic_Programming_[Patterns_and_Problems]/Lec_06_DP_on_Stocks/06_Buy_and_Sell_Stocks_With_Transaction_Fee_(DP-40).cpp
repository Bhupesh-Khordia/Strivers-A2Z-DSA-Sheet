# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
private:
    int solveRec(int index, int buy, vector<int>& prices, int fee) {
        if (index == prices.size()) 
            return 0;

        int profit = 0;
        if (buy) {
            int buyKaro = -prices[index] + solveRec(index + 1, 0, prices, fee);
            int skipKaro = 0 + solveRec(index + 1, 1, prices, fee);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[index] + solveRec(index + 1, 1, prices, fee) - fee;
            int skipKaro = 0 + solveRec(index + 1, 0, prices, fee);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }

    int solveDP(int index, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee) {
        if (index == prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if (buy) {
            int buyKaro = -prices[index] + solveDP(index + 1, 0, prices, dp, fee);
            int skipKaro = 0 + solveDP(index + 1, 1, prices, dp, fee);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[index] + solveDP(index + 1, 1, prices, dp, fee) - fee;
            int skipKaro = 0 + solveDP(index + 1, 0, prices, dp, fee);
            profit = max(sellKaro, skipKaro);
        }
        return dp[index][buy] = profit;
    }

    int solveTab(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {

                int profit = 0;
                if (buy) {
                    int buyKaro = -prices[index] + dp[index + 1][0];
                    int skipKaro = 0 + dp[index + 1][1];
                    profit = max(buyKaro, skipKaro);
                } else {
                    int sellKaro = prices[index] + dp[index + 1][1] - fee;
                    int skipKaro = 0 + dp[index + 1][0];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveSO(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {

                int profit = 0;
                if (buy) {
                    int buyKaro = -prices[index] + dp[index + 1][0];
                    int skipKaro = 0 + dp[index + 1][1];
                    profit = max(buyKaro, skipKaro);
                } else {
                    int sellKaro = prices[index] + dp[index + 1][1] - fee;
                    int skipKaro = 0 + dp[index + 1][0];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        // Recursion Solulu

        // return solveRec(0, 1, prices, fee);


        // DP Solulu
        /*
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solveDP(0, 1, prices, dp, fee);
        */

        
        // Tabulation Solulu

        // return solveTab(prices, fee);


        // Space Optimized Solulu

        return solveSO(prices, fee);
    }
};