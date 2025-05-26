#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/better-string/1


// Brute Force - O (2 ^ n)
/*
class Solution {
  private:
    void subseq(string s1, unordered_set<string> &set1, int index, string s) {
        if(index == s1.length()) {
            set1.insert(s);
            return;
        }
        
        // Include
        subseq(s1, set1, index + 1, s + s1[index]);
        //Exclude
        subseq(s1, set1, index + 1, s);
    }
  public:
    string betterString(string &s1, string &s2) {
        unordered_set<string> set1;
        unordered_set<string> set2;
        
        subseq(s1, set1, 0, "");
        subseq(s2, set2, 0, "");
        
        return set1.size() >= set2.size() ? s1 : s2;
    }
};
*/

// DP - O (n)
class Solution {
private:
    unordered_map<char, int> lastPos;       // Last seen position of each character
    unordered_map<int, int> memo;

    int count(int i, const string &s) {
        if (i < 0) return 1;                 // Base case: empty string has 1 subsequence ("")

        if (memo.count(i)) return memo[i];

        int ans = 2 * count(i - 1, s);       // All subsequences with and without s[i]

        char ch = s[i];
        if (lastPos.count(ch)) {
            ans -= count(lastPos[ch] - 1, s); // Remove duplicates
        }

        lastPos[ch] = i;

        return memo[i] = ans;
    }

public:
    string betterString(string &s1, string &s2) {
        memo.clear(); lastPos.clear();
        int count1 = count(s1.size() - 1, s1);

        memo.clear(); lastPos.clear();
        int count2 = count(s2.size() - 1, s2);

        return count1 >= count2 ? s1 : s2;
    }
};