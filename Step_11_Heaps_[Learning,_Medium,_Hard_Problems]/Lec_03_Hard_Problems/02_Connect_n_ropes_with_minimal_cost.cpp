using namespace std;
#include <bits/stdc++.h>


// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

// Not a question of heap, but a question of DP

/*

// User function Template for C++

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

*/


// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// This one is a question of heap

class Solution {
    public:
      int minCost(vector<int>& arr) {
          priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end()); // Min heap
  
          int totalCost = 0;
  
          while (pq.size() > 1) {
              int first = pq.top(); pq.pop();
              int second = pq.top(); pq.pop();
  
              int cost = first + second;
              totalCost += cost;
  
              pq.push(cost);
          }
  
          return totalCost;
      }
  };