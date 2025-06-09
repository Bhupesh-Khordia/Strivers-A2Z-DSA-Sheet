# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/index-of-the-first-occurrence-of-pattern-in-a-text/1


// Brute Force Approach
// Time Complexity: O(n * m) where n is the length of text and m is the length of pattern
class Solution {
  public:
    int findMatching(string text, string pat) {
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
    }
};