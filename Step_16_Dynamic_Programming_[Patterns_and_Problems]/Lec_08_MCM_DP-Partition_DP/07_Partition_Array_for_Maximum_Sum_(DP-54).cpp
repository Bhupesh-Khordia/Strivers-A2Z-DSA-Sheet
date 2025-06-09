# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-array-for-maximum-sum/description/

class Solution {
private:
    int solve(int i, int n, vector<int> &arr, int k, vector<int> &dp) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int cnt = 0;
        int maxi = arr[i];
        int toReturn = INT_MIN;
        for(int partition = i; partition < min(n, i + k); partition++) {
            cnt++;

            maxi = max(maxi, arr[partition]);
            toReturn = max(toReturn, cnt * maxi + solve(partition + 1, n, arr, k, dp));
        }

        return dp[i] = toReturn;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return solve(0, n, arr, k, dp);
    }
};