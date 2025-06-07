# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

class Solution {
  private:
    // Step 1: Compute the LCS length using DP
    vector<vector<int>> computeLCSLength(string &s1, string &s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp;
    }

    // Step 2: Recursively build all LCS strings
    void buildAllLCS(string &s1, string &s2, int i, int j, 
                     vector<vector<int>> &dp, string current, 
                     set<string> &result) {
        int m = s1.length(), n = s2.length();

        if (i == m || j == n) {
            result.insert(current);
            return;
        }

        if (s1[i] == s2[j]) {
            buildAllLCS(s1, s2, i + 1, j + 1, dp, current + s1[i], result);
        } else {
            if (dp[i + 1][j] >= dp[i][j + 1])
                buildAllLCS(s1, s2, i + 1, j, dp, current, result);
            if (dp[i][j + 1] >= dp[i + 1][j])
                buildAllLCS(s1, s2, i, j + 1, dp, current, result);
        }
    }
    
    set<string> LCS(int i, int j, const string &s1, const string &s2, vector<vector<int>> &dp, map<pair<int, int>, set<string>> &memo) {
        if (i == 0 || j == 0)
            return {""};
    
        if (memo.count({i, j}))
            return memo[{i, j}];
    
        if (s1[i - 1] == s2[j - 1]) {
            set<string> prev = LCS(i - 1, j - 1, s1, s2, dp, memo);
            set<string> result;
            for (const string &str : prev)
                result.insert(str + s1[i - 1]);
            return memo[{i, j}] = result;
        }
    
        set<string> result;
        if (dp[i - 1][j] >= dp[i][j - 1])
            result = LCS(i - 1, j, s1, s2, dp, memo);
        if (dp[i][j - 1] >= dp[i - 1][j]) {
            set<string> temp = LCS(i, j - 1, s1, s2, dp, memo);
            result.insert(temp.begin(), temp.end());
        }
    
        return memo[{i, j}] = result;
    }

  public:
    vector<string> allLCS(string &s1, string &s2) {
        // TLE
        /*
        auto dp = computeLCSLength(s1, s2);
        set<string> result;
        buildAllLCS(s1, s2, 0, 0, dp, "", result);

        return vector<string>(result.begin(), result.end());
        */


        // This code prints just one sequence instead of all
        /*
        int n = s1.size();
        int m = s2.size();
        
        vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
        for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
        }
        
        for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
          if (s1[ind1 - 1] == s2[ind2 - 1])
            dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
          else
            dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
        }
        
        int len = dp[n][m];
        int i = n;
        int j = m;
        
        int index = len - 1;
        string str = "";
        for (int k = 1; k <= len; k++) {
        str += "$"; // dummy string
        }
        
        while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
          str[index] = s1[i - 1];
          index--;
          i--;
          j--;
        } else if (s1[i - 1] > s2[j - 1]) {
          i--;
        } else j--;
        }
        
        cout << str;
        */
        
        
        int n = s1.size();
        int m = s2.size();
    
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    
        map<pair<int, int>, set<string>> memo;
        set<string> result = LCS(n, m, s1, s2, dp, memo);
    
        vector<string> ans (result.begin(), result.end());
        
        return ans;
    }
};
