// https://leetcode.com/problems/longest-repeating-character-replacement/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.length(), ans = 0;
        unordered_map<char, int> cnt;
        int maxi = 0;

        while(r < n) {
            cnt[s[r]]++;
            maxi = max(maxi, cnt[s[r]]);

            while(r - l + 1 - maxi > k) {
                cnt[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
};