// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
    public:
        string reverseWords(string s) {
            string ans = "";
            string tempWord = "";
    
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == ' ') {
                    if(tempWord != "") {
                        if(ans != "") {
                            ans = tempWord + ' ' + ans;
                        } else {
                            ans = tempWord;
                        }
                        tempWord = "";
                    }
                } else {
                    tempWord += s[i];
                }
            }
    
            if(tempWord != "") {
                if(ans != "") {
                    ans = tempWord + ' ' + ans;
                } else {
                    ans = tempWord;
                }
            }
            return ans;
        }
    };