# include <bits/stdc++.h>
using namespace std;


// Z Function returns array which will store max length starting from a index which is a prefix in the string.

// Refer this video for detailed explanation - https://www.youtube.com/watch?v=6mzNnEGimPA

// --------------------------------------------------------------------------------------------------------------------------------
// Refer this question - https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-ii/description/
// --------------------------------------------------------------------------------------------------------------------------------

class Solution {
private:
    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

public:
    int minimumTimeToInitialState(string word, int k) {
        // Brute Force
        /*
        int time = 1;
        int n = word.length();
        for(int i = k; i < n; i+=k) {
            string sub = word.substr(i);
            if(sub == word.substr(0, n - i)) return time; // n - i can also be replaced with sub.length()
            time++;
        }

        return time;
        */

        // Optimized O(n)
        auto z = z_function(word);
        for (int i = k, n = word.size(); i < n; i += k)
            if (z[i] == n - i)
                return i / k;
        return (word.size() + k - 1) / k;  // Ceil value of (word.size() / k)
        // i.e. remove entire string ans start new string again
    }
};



// --------------------------------------------------------------------------------------------------------------------------------
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
// --------------------------------------------------------------------------------------------------------------------------------

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


    int searchRabinKarp(string pat, string txt, int mod) 
    { 
        if (txt.size() < pat.size()) return -1;

        // hash of CAB = 3 * d^2 + 1 * d^1 + 2 * d^0
        int d = 27;

        int M = pat.size(); 
        int N = txt.size(); 
        int i, j; 
        int p = 0; // hash value for pattern 
        int t = 0; // hash value for txt 
        int h = 1; 

        // The value of h would be "pow(d, M-1)%q" 
        for (i = 0; i < M - 1; i++) 
            h = (h * d) % mod; 

        // Calculate the hash value of pattern and first 
        // window of text 
        for (i = 0; i < M; i++) 
        { 
            p = (d * p + (pat[i] - 'a')) % mod;  // Multiplying by d does a left shift.
            t = (d * t + (txt[i] - 'a')) % mod;  // Eg - if d is 10. then 21 * 10 = 210 then add the last digit
        } 

        // Slide the pattern over text one by one 
        for (i = 0; i <= N - M; i++) 
        { 

            // Check the hash values of current window of text 
            // and pattern. If the hash values match then only 
            // check for characters on by one 
            if ( p == t ) 
            { 
                /* Check for characters one by one */
                for (j = 0; j < M; j++) 
                { 
                    if (txt[i+j] != pat[j]) 
                        break; 
                } 

                // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
                if (j == M) 
                    // cout<<"Pattern found at index "<< i<<endl; 
                    return i;
            } 

            // Calculate hash value for next window of text: Remove 
            // leading digit, add trailing digit 
            if ( i < N-M ) 
            { 
                t = (d * (t - (txt[i] - 'a') * h) + (txt[i + M] - 'a')) % mod;

                // We might get negative value of t, converting it 
                // to positive 
                if (t < 0) 
                t = (t + mod); 
            } 
        } 

        return -1;
    } 
public:
    int strStr(string haystack, string needle) {
        // KMP Algorithm
        /*
        // Longest Prefix Suffix
        // Ex - string = abcabx, lps = 0,0,0,1,2,0
        vector<int> lps = findLPS(needle);
        return KMP(haystack,needle,lps);
        */


        // Rabin Karp Algorithm (Will be integer overflow in this question, but good for understanding)

        // /*
        if(needle == "")  return 0;
        int mod = 1e9 + 7; // Can be any prime number (large value preferred)
        return searchRabinKarp(needle, haystack, mod); 
        // */
    }
};