#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
private:
    void solve(vector<string>& ans, string output, int index, string* mapping, string digits) {
        if(index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int element = digits[index] - '0';
        string str = mapping[element];

        for(int i = 0; i < str.length(); i++) {
            output.push_back(str[i]);
            solve(ans, output, index + 1, mapping, digits);
            output.pop_back();
        }

        

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) 
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(ans, output, index, mapping, digits);

        return ans;
    }
};