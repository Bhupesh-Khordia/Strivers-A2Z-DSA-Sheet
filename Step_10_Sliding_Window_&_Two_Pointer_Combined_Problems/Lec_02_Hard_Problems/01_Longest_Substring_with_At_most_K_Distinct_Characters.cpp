#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/

// Poor :(

// https://www.naukri.com/code360/problems/distinct-characters_2221410?leftPanelTabValue=PROBLEM

/*

#include <bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
    int l = 0, r = 0, n = str.length(), ans = -1;
    unordered_map<char, int> cnt;
    
    
    while(r < n) {
        cnt[str[r]]++;
        while(cnt.size() > k) {
            cnt[str[l]]--;
            if(cnt[str[l]] == 0) cnt.erase(str[l]);
            l++;
        }
        ans = max(ans, (r - l + 1));
        r++;
    }
    return ans;
}

*/

// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1


// /*

// User function template for C++

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int l = 0, r = 0, n = s.length(), ans = -1;
        unordered_map<char, int> cnt;

        while (r < n) {
            cnt[s[r]]++;

            while (cnt.size() > k) {
                cnt[s[l]]--;
                if (cnt[s[l]] == 0) cnt.erase(s[l]);
                l++;
            }

            if (cnt.size() == k) {
                ans = max(ans, r - l + 1);
            }

            r++;
        }

        return ans;
    }
};

// */