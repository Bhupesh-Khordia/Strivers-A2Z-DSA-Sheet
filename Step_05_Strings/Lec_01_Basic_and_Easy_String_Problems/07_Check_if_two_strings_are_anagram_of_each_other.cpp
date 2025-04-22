// https://leetcode.com/problems/valid-anagram/description/

class Solution {
    public:
        bool isAnagram(string s, string t) {
            vector<int> cnt (26, 0);
    
            for(char ch : s) {
                cnt[ch - 97]++;  // ascii of 'a'
            }
    
            for(char ch : t) {
                if(cnt[ch - 97] == 0) return false;
                cnt[ch - 97]--;
            }
    
            for(auto i : cnt) {
                if(i != 0) return false;
            }
    
            return true;
        }
    };