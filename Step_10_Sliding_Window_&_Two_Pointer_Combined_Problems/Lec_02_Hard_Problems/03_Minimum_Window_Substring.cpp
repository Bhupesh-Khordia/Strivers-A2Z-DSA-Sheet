// https://leetcode.com/problems/minimum-window-substring/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cnt;

        for(auto ch : t) {
            cnt[ch]++;
        }
        int n = s.length();
        int m = t.length();
        int l = 0, r = 0;
        int ansLen = INT_MAX;
        int ansStart = -1;
        int counter = 0; // How many elements from t are in substring

        while(r < n) {
            if(cnt[s[r]] > 0) {
                counter++;
            }
            cnt[s[r]]--;

            while(counter == m) {
                if(ansLen > r-l+1) {
                    ansLen = min(ansLen, r - l + 1);
                    ansStart = l;
                }
                cnt[s[l]]++;
                if(cnt[s[l]] > 0) counter--;
                l++;
            }

            r++;

        }

        if(ansLen == INT_MAX) return "";
        
        return s.substr(ansStart, ansLen);
    }
};