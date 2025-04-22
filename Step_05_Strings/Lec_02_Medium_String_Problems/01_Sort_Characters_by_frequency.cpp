// https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
    private:
        static bool cmp (pair<char, int>a, pair<char, int>b) {
            return a.second > b.second;
        }
    public:
        string frequencySort(string s) {
            map<char, int> cnt;
    
            for(char ch : s) {
                cnt[ch]++;
            }
    
            vector<pair<char, int>> vec(cnt.begin(), cnt.end());
    
            sort(vec.begin(), vec.end(), cmp);
    
            int idx = 0;
            for(auto pair : vec) {
                for(int i = 0; i < pair.second; i++) {
                    s[idx++] = pair.first;
                }
            }
            return s;
        }
    };