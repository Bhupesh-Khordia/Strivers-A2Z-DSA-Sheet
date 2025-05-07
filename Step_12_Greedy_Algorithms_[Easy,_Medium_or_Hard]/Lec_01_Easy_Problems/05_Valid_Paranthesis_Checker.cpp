// https://leetcode.com/problems/valid-parenthesis-string/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
    public:
        bool checkValidString(string s) {
            int low = 0; // minimum number of unmatched open parentheses possible
            int high = 0; // maximum number of unmatched open parentheses possible
            for(char c : s) {
                if (c == '(') {
                    low++;
                    high++;
                } else if (c == ')') {
                    if (low > 0) low--;
                    high--;
                    if (high < 0) return false;
                } else { // c == '*'
                    if (low > 0) low--;
                    high++;
                }
    
            }
            return low == 0;
            
            // wrong
    
            /*
            int openCnt = 0;
            int starCnt = 0;
            int openOrEmpty = 0;
    
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '(') openCnt++;
                else if (s[i] == '*') openCnt > 0 ? starCnt++ : openOrEmpty++;
                else {
                    if(openCnt > 0) openCnt--;
                    else if(openOrEmpty > 0) openOrEmpty--;
                    else if(starCnt > 0 ) starCnt--;
                    else return false;
                }
            }
    
            if(openCnt > 0) {
                return openCnt <= starCnt;
            }
            return true;
            */
        }
    };