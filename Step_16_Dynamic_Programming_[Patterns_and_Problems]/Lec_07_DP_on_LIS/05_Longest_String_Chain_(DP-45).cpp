# include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/longest-string-chain/description/

// Similar to LIS - https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
    static bool cmp (string &s1, string &s2) {
        return s1.length() < s2.length();
    }

    bool check(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        if (m != n - 1) return false;

        int i = 0, j = 0;
        bool unmatchedFound = false;
        while(i < m && j < n) {
            if(s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                if(unmatchedFound) return false;
                unmatchedFound = true;
                j++;
            }
        }

        return true;
    }

    int solveSingle(vector<string> &arr, int n) {
        vector<int> dp(n, 1); // Will store length of longest word chain ending at each index

        int maxi = 1;
        for(int i = 0; i < n; i++) {
            for(int prevIndex = 0; prevIndex < i; prevIndex++) {
                if(check(arr[prevIndex], arr[i])) {
                    // We can append arr[i] after arr[prevIndex]
                    dp[i] = max(dp[i], 1 + dp[prevIndex]);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        return solveSingle(words, words.size());
    }
};