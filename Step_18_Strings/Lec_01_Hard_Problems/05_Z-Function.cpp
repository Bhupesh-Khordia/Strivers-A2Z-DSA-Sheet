# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/



// Refer https://www.youtube.com/watch?v=ziteu2FpYsA for detailed explanation
// Z Function is same as LPS in KMP algorithm

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

    // O(n + m)
    int KMP(string& text,string& patt,vector<int>& lps){ // returns first index of occurence
        int m=text.size();
        int n=patt.size();

        int i=0,j=0;
        while(i<m){
            if(text[i]==patt[j]){
                i++;
                j++;
            }
            if(j==n)
                return i - n;
            if(i<m and text[i]!=patt[j]){
                if(j>0)
                    j=lps[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        // Longest Prefix Suffix
        // Ex - string = abcabx, lps = 0,0,0,1,2,0
        vector<int> lps = findLPS(needle);
        return KMP(haystack,needle,lps);
    }
};