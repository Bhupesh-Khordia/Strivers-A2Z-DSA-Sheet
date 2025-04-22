// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
    public:
        int myAtoi(string s) {
            int i = 0, sign = 1;
            long res = 0; // Using long to handle overflow cases
    
            // Trim leading spaces
            while (i < s.size() && s[i] == ' ') i++;
            if (i == s.size()) return 0;
    
            // Check for sign
            if (s[i] == '-') { sign = -1; i++; }
            else if (s[i] == '+') i++;
    
            // Process numerical characters
            while (i < s.size() && isdigit(s[i])) {
                res = res * 10 + (s[i] - '0');
    
                // Handle overflow
                if (sign * res > INT_MAX) return INT_MAX;
                if (sign * res < INT_MIN) return INT_MIN;
    
                i++;
            }
    
            return (int)(sign * res);
        }
    };
    
    
    /*
    class Solution {
    public:
        int myAtoi(string s) {
            bool traversingSpace = true;
            int firstDigitFound = false;
            string str = "";
            for(auto ch : s) {
                if(traversingSpace) {
                    if(ch == ' ') {
                        continue;
                    } else if(ch == '-' || ch == '+') {
                        traversingSpace = false;
                        str += ch;
                    } else if(ch - 48 < 0 || ch - 48 > 9) {
                        break;
                    } else {
                        // Number
                        if(ch - 48 == 0) {
                            // Zero
                            traversingSpace = false;
                            continue;
                        } else {
                            // 1-9
                            traversingSpace = false;
                            firstDigitFound = true;
                            str += ch;
                        }
                    }
                } else {
                    if(firstDigitFound) {
                        if(ch - 48 >= 0 && ch - 48 <= 9) {
                            str += ch;
                        } else {
                            break;
                        }
                    } else {
                        if(ch - 48 == 0) continue;
                        else {
                            firstDigitFound = true;
                            if(ch - 48 >= 0 && ch - 48 <= 9) {
                                str+=ch;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
            if(str == "") return 0;
    
            int sign = 1;
            if(str[0] == '-') {
                sign = -1;
                str = str.substr(1);
            } else if (str[0] == '+') {
                str = str.substr(1);
            }
    
            long long ans = 0;
    
            for(int i = 0; i < str.length(); i++) {
                ans = 10 * ans + (str[i] - 48);
                if(sign == 1 && ans > INT_MAX) return INT_MAX;
                if(sign == -1 && ans > (long long)INT_MAX + 1) return INT_MIN;
            }
            
            return ans * sign;
        }
    };
    */