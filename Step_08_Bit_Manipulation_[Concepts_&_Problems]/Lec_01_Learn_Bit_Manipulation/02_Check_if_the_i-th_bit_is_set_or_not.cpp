// https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        for(int x = 0; x < k; x++) {
            n = n >> 1;
        }
        return n & 1;
    }
};