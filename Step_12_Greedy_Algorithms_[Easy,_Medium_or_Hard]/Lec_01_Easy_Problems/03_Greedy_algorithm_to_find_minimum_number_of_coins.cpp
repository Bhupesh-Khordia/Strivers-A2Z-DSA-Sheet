// https://www.geeksforgeeks.org/problems/number-of-coins1824/1

using namespace std;
#include <bits/stdc++.h>


class Solution {
    private:
      int solveRec(vector<int> &coins, int sum, int index, vector<vector<int>> &dp) {
          if (sum == 0) return 0;
          if (index == coins.size()) return INT_MAX - 1; // prevent overflow in +1
          if (dp[index][sum] != -1) return dp[index][sum];
  
          int exclude = solveRec(coins, sum, index + 1, dp);
  
          int include = INT_MAX - 1;
          if (coins[index] <= sum) {
              include = 1 + solveRec(coins, sum - coins[index], index, dp);
          }
  
          return dp[index][sum] = min(include, exclude);
      }
    public:
      int minCoins(vector<int> &coins, int sum) {
          // Wrong Approach
          /*
          sort(coins.rbegin(), coins.rend());
          int total = 0;
          int ans = 0;
          for(int i = 0; i < coins.size(); i++) {
              while(total + coins[i] <= sum) {total+=coins[i]; ans++;}
          }
          
          if(total != sum) return -1;
          return ans;
          */
          
          // DP
          
          int n = coins.size();
          vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
          int result = solveRec(coins, sum, 0, dp);
          return (result == INT_MAX - 1) ? -1 : result;
      }
  };