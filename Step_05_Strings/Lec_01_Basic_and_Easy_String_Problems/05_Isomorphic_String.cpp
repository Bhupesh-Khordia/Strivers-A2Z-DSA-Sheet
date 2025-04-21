// https://leetcode.com/problems/isomorphic-strings/description/


class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            unordered_map<char, char> map;
            unordered_map <char , bool> used; // Have already been mapped to by some character
    
            for(int i = 0; i < s.length(); i++) {
                if(map.find(s[i]) == map.end()) {
                    if(used[t[i]])
                        return false;
                    used[t[i]] = true;
                    map[s[i]] = t[i];
                } else {
                    if(map[s[i]] != t[i]) return false;
                }
            }
    
            return true;
        }
    };