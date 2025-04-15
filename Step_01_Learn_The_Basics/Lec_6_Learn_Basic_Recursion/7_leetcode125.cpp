class Solution {
private:
    void preprocess(string &s, int n) {
        string temp = "";
        for(int i = 0; i < n; i++) {
            if(s[i] >= 65 && s[i] <= 90) {
                s[i] += 32;
            }
            if((s[i] >= 97 && s[i] <= 121) || (s[i] >= 47 && s[i] <= 57)) {
                temp += s[i];
            }
        }
        s = temp;
    }
public:
    bool isPalindrome(string s) {
        int n = s.length();
        preprocess(s, n);
        int start = 0;
        int end = s.length()-1;
        while(end > start) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};
