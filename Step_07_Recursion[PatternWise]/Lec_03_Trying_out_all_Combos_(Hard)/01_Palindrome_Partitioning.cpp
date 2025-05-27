#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
private:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while( i < j ) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s, vector<string> &output, vector<vector<string>> &ans) {
        if(s.size() == 0) {
            ans.push_back(output);
            return;
        }

        for(int i = 1; i <= s.length(); i++) {
            // Partition
            if(isPalindrome (s.substr(0, i))) {
                output.push_back(s.substr(0, i));
                solve(s.substr(i), output, ans);
                output.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> output;
        vector<vector<string>> ans;
        solve(s, output, ans);
        return ans;
    }
};