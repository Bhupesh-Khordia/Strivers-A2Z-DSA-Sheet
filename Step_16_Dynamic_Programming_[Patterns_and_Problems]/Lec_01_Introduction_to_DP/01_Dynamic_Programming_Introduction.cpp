# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/introduction-to-dp/1


class Solution {
  private:
    const int MOD = 1e9 + 7;
    
    
  public:
    long long int memo(int n, vector<int> &dp) {
        if(n <= 2) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (memo(n - 1, dp) + memo(n - 2, dp)) % MOD;
    }
  
    long long int topDown(int n) {
        vector<int> dp (n + 1, -1);
        return memo(n, dp);
    }

    long long int bottomUp(int n) {
        /*
        vector<int> dp(n + 1, 1);
        
        for(int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) %  MOD;
        }
        
        return dp[n];
        */
        
        // In O(1) Space Complexity
        
        if (n <= 2) return 1;
    
        int prev = 1; // f(n-2)
        int curr = 1; // f(n-1)
    
        for (int i = 3; i <= n; i++) {
            int next = (prev + curr) % MOD;
            prev = curr;
            curr = next;
        }
    
        return curr;
        
    }
};