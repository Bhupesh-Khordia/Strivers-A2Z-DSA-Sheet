#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
private:
    int recur(string s, int i, int sign, long long res){
        if(i >= s.size() || !isdigit(s[i])) return res*sign;

        res = res*10 + s[i] - '0';

        if(res*sign <= INT_MIN) return INT_MIN;
        if(res*sign >= INT_MAX) return INT_MAX;

        return recur(s, i+1, sign, res);
    }
public:
    int myAtoi(string s) {
        // Iterative Solution
        /*
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
        */


        // Recursive Solution
        // /*
        size_t start = s.find_first_not_of(" ");
        if(start == string::npos) return 0;

        s = s.substr(start);
        if(s.empty()) return 0;

        int sign = 1, index = 0;
        if(s[0] == '-') sign = -1, index = 1;
        else if(s[0] == '+') index = 1; 

        return recur(s, index, sign, 0);
        // */
    }
};