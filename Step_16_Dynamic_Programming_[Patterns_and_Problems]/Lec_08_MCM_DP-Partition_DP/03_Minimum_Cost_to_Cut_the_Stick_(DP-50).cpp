# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

class Solution {
private:
    // Bad approach
    /*
    int solve(int i , int j, vector<int> &cuts, vector<vector<int>> &dp) {

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int k = 0; k < cuts.size(); k++) {
            int cut = cuts[k];

            if(cut > i && cut < j) {
                int cost = j - i;
                int part1 = solve(i, cut, cuts, dp);
                int part2 = solve(cut, j, cuts, dp);
                mini = min(mini, cost + part1 + part2);
            }
        } 

        return dp[i][j] = mini == INT_MAX ? 0 : mini;
    }

    int solveTab(int n, vector<int> &cuts) {
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));

        for(int i = n; i >= 0; i--) {
            for(int j = i + 2; j <= n; j++) {
                int mini = INT_MAX;
                for(int k = 0; k < cuts.size(); k++) {
                    int cut = cuts[k];

                    if(cut > i && cut < j) {
                        int cost = j - i;
                        int part1 = dp[i][cut];
                        int part2 = dp[cut][j];
                        mini = min(mini, cost + part1 + part2);
                    }
                } 
                dp[i][j] = (mini == INT_MAX) ? 0 : mini;
            }
        }

        return dp[0][n];
    }
    */

    // Good Approach
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int ind = i; ind <= j; ind++) {
            // Which cut to perform
            int cost = cuts[j + 1] - cuts[i - 1];
            mini = min(mini, cost + solve(i, ind - 1, cuts, dp) + solve(ind + 1, j, cuts, dp));
        }

        return dp[i][j] = mini;
    }

    int solveTab(int n, vector<int> &cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), 0));

        for(int i = cuts.size() - 2; i >= 1; i--) {
            for(int j = i; j <= cuts.size() - 2; j++) {
                int mini = INT_MAX;
                for(int ind = i; ind <= j; ind++) {
                    // Which cut to perform
                    int cost = cuts[j + 1] - cuts[i - 1];
                    mini = min(mini, cost + dp[i][ind - 1] + dp[ind + 1][j]);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][cuts.size() - 2];
    }
public:
    int minCost(int n, vector<int>& cuts) {
        // Bad Approach
        // Top Down (MLE)
        /*
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, -1));
        return solve(0, n, cuts, dp);
        */

        // Bottom Up 
        
        // return solveTab(n, cuts);


        // Good approach

        // Recursive Solulu
        /*
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), -1));
        return solve(1, cuts.size() - 2, cuts, dp);
        */


        // Tabulation Solulu


        return solveTab(n, cuts);
    }
};