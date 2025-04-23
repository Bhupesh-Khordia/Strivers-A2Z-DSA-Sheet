// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

class Solution {
    public:
        int beautySum(string s) {
            int n = s.length();
            int ans = 0;
            for(int i = 0; i < n; i++) {
                vector<int> cnt(26, 0);
                for(int j = i; j < n; j++) {
                    cnt[s[j] - 'a']++;
                    int maxFreq = *max_element(cnt.begin(), cnt.end());
                    int minFreq = INT_MAX;
                    for(int k = 0; k < 26; k++) {
                        if(cnt[k] > 0) minFreq = min(minFreq, cnt[k]);
                    }
    
                    if(maxFreq - minFreq > 0) {
                        ans += maxFreq - minFreq;
                    }
                }
            }
            return ans;
        }
    };