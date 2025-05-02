// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

using namespace std;
#include <bits/stdc++.h>

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int left = 0;
            unordered_map<char, int> freq;
            int ans = 0;
    
            int n = s.length();
            int right = 0;
            while(right < n) {
                freq[s[right]]++;
                while(freq[s[right]] > 1) {
                    freq[s[left]]--;
                    left++;
                }
                ans = max (ans, right - left + 1);
                right++;
            }
    
            return ans;
        }
    };