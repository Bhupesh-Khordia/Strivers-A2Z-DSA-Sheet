// https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBit(int n) {
        
        // To unset
        
        // return n & n-1;
        
        // To set
        
        return n | n + 1;
    }
};