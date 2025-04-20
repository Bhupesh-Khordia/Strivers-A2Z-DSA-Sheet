// https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
    public:
        string removeOuterParentheses(string s) {
            string ans;
            int cntOpen = 0;
            for(auto ch : s) {
                if(ch == '(') {
                    if(cntOpen != 0) ans += ch;
                    cntOpen++;
                }
                else if(ch == ')') {
                    cntOpen--;
                    if(cntOpen != 0) ans += ch;
                }
            }
            return ans;
        }
    };