// https://leetcode.com/problems/powx-n/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // Use long long to handle INT_MIN safely
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {
                result *= x;
                N = N - 1;
            } else {
                // x ^ y = (x ^ 2) ^ (y / 2)
                x *= x;
                N /= 2;
            }
        }
        return result;
    }
};
