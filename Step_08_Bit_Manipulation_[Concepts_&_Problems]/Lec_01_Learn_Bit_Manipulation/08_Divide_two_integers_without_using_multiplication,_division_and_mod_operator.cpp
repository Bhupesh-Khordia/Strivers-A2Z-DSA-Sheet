// https://leetcode.com/problems/divide-two-integers/description/

// https://www.youtube.com/watch?v=pBD4B1tzgVc

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == 0) return 0;

        int sign = (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0) ? 1 : -1;

        long long dividendCpy = abs((long long)dividend);
        long long divisorCpy = abs((long long)divisor);

        long long result = 0;

        while (dividendCpy >= divisorCpy) {
            long long temp = divisorCpy;
            long long multiple = 1;

            while ((temp << 1) <= dividendCpy) {
                temp <<= 1;
                multiple <<= 1;
            }

            dividendCpy -= temp;
            result += multiple;
        }

        result = sign * result;
        if(result > INT_MAX) return INT_MAX;
        if(result < INT_MIN) return INT_MIN;
        return result;
    }
};