# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.length() == 0) return 0;

        stack <char> st;

        for(char c : s) {
            if(c == '(') st.push(c);

            else {
            if (!st.empty() && st.top() == '(') st.pop();
            else st.push(c);
            }
        }

        return st.size();
        
    }
};