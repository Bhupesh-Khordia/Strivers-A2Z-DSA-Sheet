# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-palindrome/description/

class Solution {
private:
    // O(n)
    vector<int> findLPS(string& patt){
        int n=patt.size();
        vector<int> lps(n);
        
        int i=1;
        int j=0;
        while(i<n){
            if(patt[i]==patt[j]){
                lps[i]=j+1;
                i++;
                j++;
            }else if(j>0){
                j=lps[j-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
        return lps;
    }
public:
    string shortestPalindrome(string s) {
        // We need to find longest prefix of s which is palindrome, then just add reverse of remaining string at the begining

        // Add reverse of s to it and find longest prefix suffix array (same as KMP algo)
        // Just add a special character in between to avoid false overlaps 

        if(s == "") return "";

        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s + '#' + rev;

        vector<int> lps = findLPS(str);

        int len = lps[str.length() - 1];

        string toAdd = "";
        if(len < s.length()) {
            toAdd = s.substr(len);
            reverse(toAdd.begin(), toAdd.end());
        }

        return toAdd + s;
    }
};