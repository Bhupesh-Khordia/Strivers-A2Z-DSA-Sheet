// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

class Solution {
    public:
        int maxDepth(string s) {
            int maxi = 0;
            int cnt = 0;
            for(char c : s) {
                if (c == '(') {
                    cnt++;
                    maxi = max(maxi, cnt);
                } else if(c == ')') {
                    cnt--;
                }
            }
            return maxi;
        }
    };