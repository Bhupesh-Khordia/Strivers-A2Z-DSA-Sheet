// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int countSetBits (int x) {
        int cnt = 0;
        while(x > 0) {
            x = x & (x - 1);
            cnt ++;
        }
        return cnt;
    }
    public:
    int minBitFlips(int start, int goal) {
        return countSetBits(start ^ goal);
    }
};


// Similar Question: https://leetcode.com/problems/hamming-distance/description/

class Solution {
private:
    int countSetBits (int x) {
        int cnt = 0;
        while(x > 0) {
            x = x & (x - 1);
            cnt ++;
        }
        return cnt;
    }
public:
    int hammingDistance(int x, int y) {
        return countSetBits(x ^ y);
    }
};