# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
private:
    int solveGreedy(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int sell1 = 0, sell2 = 0;

        for (int price : prices) {
            buy1 = min(buy1, price);
            sell1 = max(sell1, price - buy1);
            buy2 = min(buy2, price - sell1);
            sell2 = max(sell2, price - buy2);
        }

        return sell2;
    }

    int solveRec(int index, int buy, vector<int>& prices, int limit) {
        if (index == prices.size()) 
            return 0;
        if(limit == 0) return 0;

        int profit = 0;
        if (buy) {
            int buyKaro = -prices[index] + solveRec(index + 1, 0, prices, limit);
            int skipKaro = 0 + solveRec(index + 1, 1, prices, limit);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[index] + solveRec(index + 1, 1, prices, limit - 1);
            int skipKaro = 0 + solveRec(index + 1, 0, prices, limit);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }

    int solveDP(int index, int buy, vector<int>& prices, int limit, vector<vector<vector<int>>> &dp) {
        if (index == prices.size()) 
            return 0;
        if(limit == 0) return 0;

        if (dp[index][buy][limit] != -1) return dp[index][buy][limit];

        int profit = 0;
        if (buy) {
            int buyKaro = -prices[index] + solveDP(index + 1, 0, prices, limit, dp);
            int skipKaro = 0 + solveDP(index + 1, 1, prices, limit, dp);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[index] + solveDP(index + 1, 1, prices, limit - 1, dp);
            int skipKaro = 0 + solveDP(index + 1, 0, prices, limit, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[index][buy][limit] = profit;
    }

    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int> (3, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for(int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy) {
                        int buyKaro = -prices[index] + dp[index + 1][0][limit];
                        int skipKaro = 0 + dp[index + 1][1][limit];
                        profit = max(buyKaro, skipKaro);
                    } else {
                        int sellKaro = prices[index] + dp[index + 1][1][limit - 1];
                        int skipKaro = 0 + dp[index + 1][0][limit];
                        profit = max(sellKaro, skipKaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int solveSO(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for(int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy) {
                        int buyKaro = -prices[index] + next[0][limit];
                        int skipKaro = 0 + next[1][limit];
                        profit = max(buyKaro, skipKaro);
                    } else {
                        int sellKaro = prices[index] + next[1][limit - 1];
                        int skipKaro = 0 + next[0][limit];
                        profit = max(sellKaro, skipKaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
public:
    int maxProfit(vector<int>& prices) {
        // Greedy Approach
        
        return solveGreedy(prices);

        // Recursion Solulu

        // return solveRec(0, 1, prices, 2);


        // DP Solulu
        /*
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (3, -1)));
        return solveDP(0, 1, prices, 2, dp);
        */

        
        // Tabulation Solulu

        // return solveTab(prices);


        // Space Optimized Solulu

        // return solveSO(prices);
    }
};