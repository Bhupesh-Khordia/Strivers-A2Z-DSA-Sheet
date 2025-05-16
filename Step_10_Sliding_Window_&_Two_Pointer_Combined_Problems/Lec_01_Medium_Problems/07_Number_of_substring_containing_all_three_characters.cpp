// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, n = s.length(), ans = 0;

        unordered_map<char, int> cnt;

        while(r < n) { 
            cnt[s[r]]++;

            while(cnt['a'] > 0 && cnt['b'] > 0 && cnt['c'] > 0) {
                ans += n - r; // All substring starting from l, including [l - r]
                cnt[s[l]]--;
                l++;
            }

            r++;
        }

        return ans;
    }
};