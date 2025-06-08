# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
private:
    // Taken from 123. Buy and Sell Stock III 
    int solveSOIII(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for(int limit = 1; limit <= k; limit++) {
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
        return next[1][k];
    }

    int solveDP(int index, int operationNo, int k, vector<int> &prices, vector<vector<int>> &dp) {
        if(index == prices.size()) return 0;

        if(operationNo == 2*k) return 0;

        if(dp[index][operationNo] != -1) return dp[index][operationNo];

        int profit = 0;
        if(!(operationNo & 1)) {  // Operation No is even
            // Buy is allowed
            int buyKaro = -prices[index] + solveDP(index + 1, operationNo + 1, k, prices, dp);
            int skipKaro = 0 + solveDP(index + 1, operationNo, k, prices, dp);
            profit = max(buyKaro, skipKaro);
        } else {
            // Sell is allowed
            int sellKaro = prices[index] + solveDP(index + 1, operationNo + 1, k, prices, dp);
            int skipKaro = 0 + solveDP(index + 1, operationNo, k, prices, dp);
            profit = max(sellKaro, skipKaro);
        }

        return dp[index][operationNo] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        // Taken from 123. Buy and Sell Stock III

        // return solveSOIII(prices, k);

        // Another Solution

        // DP Solulu

        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> ((2*k) + 1, -1));
        return solveDP(0, 0, k, prices, dp);
    }
};