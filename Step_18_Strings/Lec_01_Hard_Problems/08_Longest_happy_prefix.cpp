# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-happy-prefix/description/

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
    string longestPrefix(string s) {
        vector<int> lps = findLPS(s); // Same as KMP's Algorithm
        int len = lps[s.length() - 1]; // Length of longest common prefix-suffix
        return s.substr(0, len);
    }
};