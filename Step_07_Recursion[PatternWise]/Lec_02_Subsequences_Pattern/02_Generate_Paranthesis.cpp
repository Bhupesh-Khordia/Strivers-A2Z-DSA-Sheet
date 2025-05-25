#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
private:
    void solve(int n, vector<string> &ans, string s, int index, int openCount) {
        if(index == 2*n) {
            if(openCount == 0)
                ans.push_back(s);
            return;
        }

        if(openCount < n) {
            s += '(';
            solve(n, ans, s, index+1, openCount+1);
            s = s.substr(0, s.length() - 1);
        } 

        if(openCount > 0) {
            s += ')';
            solve(n, ans, s, index+1, openCount-1);
            s = s.substr(0, s.length() - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, ans, "", 0, 0);
        return ans;
    }
};