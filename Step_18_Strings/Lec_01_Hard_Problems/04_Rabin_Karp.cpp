# include <bits/stdc++.h>
using namespace std;


// Refer this question to understand the Rabin-Karp algorithm:
// --------------------------------------------------------------------------------------------------------------------------------
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
// --------------------------------------------------------------------------------------------------------------------------------


// Refer https://www.youtube.com/watch?v=BQ9E-2umSWc for detailed explanation of Rabin-Karp algorithm.
// Refer https://www.youtube.com/watch?v=ziteu2FpYsA for detailed explanation of KMP algorithm.

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





// --------------------------------------------------------------------------------------------------------------------------------
// https://leetcode.com/problems/repeated-string-match/description/
// --------------------------------------------------------------------------------------------------------------------------------



// Refer https://www.youtube.com/watch?v=BQ9E-2umSWc for detailed explanation of Rabin-Karp algorithm.

class Solution {
private:
    int BASE = 1000000;
public:
    int repeatedStringMatch(string A, string B) {
        // A - abcd
        // Cases -
        // 1. B can be prefix -> prefix + n*a + suffix ==> cd(abcd)ab   --> ans = n + 2
        // 2. B can be prefix -> prefix + n*a ==> cd(abcd)              --> ans = n + 1
        // 3. B can be prefix -> n*a + suffix ==> (abcd)ab              --> ans = n + 1
        // 4. B can be prefix -> n*a  ==> (abcd)                        --> ans = n
        if(A == B) return 1;
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        if(source == B) return count;   // 4. Case of ans = n
        // 2,3. Case of ans = n + 1
        if(Rabin_Karp(source,B) != -1) return count;  // Acts as source.find(B)
        // 1. Case of ans = n + 2
        if(Rabin_Karp(source+A,B) != -1) return count+1;
        return -1;
    }
    int Rabin_Karp(string source, string target){
        if(source == "" or target == "") return -1;
        int m = target.size();
        int power = 1; // 31 ^ m
        for(int i = 0;i<m;i++){
            power = (power*31)%BASE;
        }
        int targetCode = 0; // hash of target
        for(int i = 0;i<m;i++){
            targetCode = (targetCode*31+target[i])%BASE;
        }
        int hashCode = 0;
        for(int i = 0;i<source.size();i++){
            hashCode = (hashCode*31 + source[i])%BASE;
            if(i<m-1) continue;
            if(i>=m){
                hashCode = (hashCode-source[i-m]*power)%BASE;
            }
            if(hashCode<0)
                hashCode+=BASE;
            if(hashCode == targetCode){
                if(source.substr(i-m+1,m) == target)
                    return i-m+1;
            }
        }
        return -1;
    }
};