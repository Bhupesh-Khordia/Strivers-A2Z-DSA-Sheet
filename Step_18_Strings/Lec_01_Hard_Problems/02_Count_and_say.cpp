# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-and-say/description/

class Solution {
private:
    string RLE(string s) {
        if(s.size() == 1) return "1" + s;

        string ans = "";
        
        char prev = s[0];
        int cnt = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != prev) {
                ans += to_string(cnt) + prev;
                prev = s[i];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        ans += to_string(cnt) + prev;

        return ans;
    }
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        return RLE(countAndSay(n - 1));
    }
};