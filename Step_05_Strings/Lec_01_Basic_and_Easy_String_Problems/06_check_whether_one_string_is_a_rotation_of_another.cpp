// https://leetcode.com/problems/rotate-string/description/

class Solution {
    public:
        bool rotateString(string s, string goal) {
            // /*
            if(s.length() != goal.length()) return false;
    
            return (s + s).find(goal) != string::npos; // find returns string::npos if the searched substring or character is not found.
            // */
    
            /*
            int n = s.length();
            if(n != goal.length()) return false;
    
            for(int i = 0; i < n; i++) {
                if(goal[i] == s[0]) {
                    if(goal.substr(i) == s.substr(0, n - i) && goal.substr(0, i) == s.substr(n - i)) {
                        return true;
                    }
                }
            }
    
            return false;
            */
        }
    };