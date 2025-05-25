#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1

// User function Template for C++

class Solution {
  private:
    void solve(int num, vector<string> &ans, int index, string s) {
        if(index == num) {
            ans.push_back(s);
            return;
        }
        s += '0';
        solve(num, ans, index+1, s);
        s = s.substr(0, s.length() - 1);
        
        if((s == "") || (s[s.length() - 1] != '1')) {
            s += '1';
            solve(num, ans, index+1, s);
            s = s.substr(0, s.length() - 1);
        }
    }
    
  public:
    vector<string> generateBinaryStrings(int num) {
        vector<string> ans;
        solve(num, ans, 0, "");
        return ans;
    }
};