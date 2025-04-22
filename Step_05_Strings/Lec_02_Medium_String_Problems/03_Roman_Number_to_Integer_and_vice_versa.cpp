// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
    public:
        int romanToInt(string s) {
            int ans = 0;
            int n = s.length();
    
            for(int i = 0; i < n; i++) {
                if(s[i] == 'I') {
                    if(i < n - 1) {
                        if(s[i + 1] == 'V') {
                            ans += 4;
                            i++;
                        } else if (s[i + 1] == 'X') {
                            ans += 9;
                            i++;
                        } else {
                            ans += 1;
                        }
                    } else {
                        ans += 1;
                    }
                } else if (s[i] == 'V') {
                    ans += 5;
                } else if (s[i] == 'X') {
                    if(i < n - 1) {
                        if(s[i + 1] == 'L') {
                            ans += 40;
                            i++;
                        } else if (s[i + 1] == 'C') {
                            ans += 90;
                            i++;
                        } else {
                            ans += 10;
                        }
                    } else {
                        ans += 10;
                    }
                } else if (s[i] == 'L') ans += 50;
                else if (s[i] == 'C') {
                    if(i < n - 1) {
                        if(s[i + 1] == 'D') {
                            ans += 400;
                            i++;
                        } else if (s[i + 1] == 'M') {
                            ans += 900;
                            i++;
                        } else {
                            ans += 100;
                        }
                    } else {
                        ans += 100;
                    }
                } else if (s[i] == 'D') ans += 500;
                else if (s[i] == 'M') ans += 1000;
            }
            return ans;
        }
    };
    
    
    /*
    class Solution {
    public:
        int romanToInt(string s) {
            int res = 0;
            unordered_map<char, int> roman = {
                {'I', 1},
                {'V', 5},
                {'X', 10}, 
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
            };
    
            for (int i = 0; i < s.size() - 1; i++) {
                if (roman[s[i]] < roman[s[i + 1]]) {
                    res -= roman[s[i]];
                } else {
                    res += roman[s[i]];
                }
            }
    
            return res + roman[s[s.size() - 1]];        
        }
    };
    */