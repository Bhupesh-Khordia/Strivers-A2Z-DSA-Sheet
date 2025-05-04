using namespace std;
#include <bits/stdc++.h>

// https://leetcode.com/problems/assign-cookies/


/*
class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
    
            int i = 0, j = 0, ans = 0;
            while(i < g.size() && j < s.size()) {
                if(g[i] <= s[j]) {
                    ans++;
                    i++;
                    j++;
                } else {
                    j++;
                }
            }
            return ans;
        }
    };

*/


//https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/

class Solution {
    public:
        int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
            sort(players.begin(), players.end());
            sort(trainers.begin(), trainers.end());
    
            int i = 0, j = 0, ans = 0;
            while(i < players.size() && j < trainers.size()) {
                if(players[i] <= trainers[j]) {
                    ans++;
                    i++;
                    j++;
                } else {
                    j++;
                }
            }
            return ans;
        }
    };