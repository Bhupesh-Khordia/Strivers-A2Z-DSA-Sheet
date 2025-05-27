#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-break/description/

class Solution {
private:
    bool solve(string s, unordered_set<string> &words, unordered_map<string, bool> &dp) {
        if(s.size() == 0) {
            return true;
        }

        if(dp.find(s) != dp.end()) return dp[s];

        for(int i = 1; i <= s.length(); i++) {
            // Partition
            if(words.find (s.substr(0, i)) != words.end()) {
                if(solve(s.substr(i), words, dp)) return true;
            }
        }

        return dp[s] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> dp;
        
        return solve(s, words, dp);
    }
};