# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/index-of-the-first-occurrence-of-pattern-in-a-text/1



// Refer https://www.youtube.com/watch?v=ziteu2FpYsA for detailed explanation

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
    int findMatching(string text, string pat) {
        // Brute Force Approach
        // Time Complexity: O(n * m) where n is the length of text and m is the length of pattern
        
        /*
        int i = 0;
        bool flag = false;
        
        for (int j = 0; j < text.length(); j++) {
            if (text[j] == pat[i]) {
                i++;
            } else {
                j -= i;
                i = 0;
            }
            
            if (i == pat.length()) {
                return j - i + 1; 
            }
        }
        return -1;
        */
        
        // KMP Algorithm
        // Time Complexity: O(n + m)
        
        // Longest Prefix Suffix
        // Ex - string = abcabx, lps = 0,0,0,1,2,0
        vector<int> lps = findLPS(pat);
        return KMP(text,pat,lps);
    }
};