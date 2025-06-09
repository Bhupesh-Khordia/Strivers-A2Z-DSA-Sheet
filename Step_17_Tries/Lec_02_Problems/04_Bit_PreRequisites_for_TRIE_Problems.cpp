# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/bits-basic-operations/1

class Solution {
  public:
    int XOR(int n, int m) {
        return n ^ m;
    }

    int check(int a, int b) {
        int mask = 1 << (a - 1); // 1 based indexing
        return (mask &  b) >> (a - 1);
    }

        
    int setBit(int c, int d) {
        int mask = 1 << (c); //  0 based indexing
        return mask | d;
    }
};