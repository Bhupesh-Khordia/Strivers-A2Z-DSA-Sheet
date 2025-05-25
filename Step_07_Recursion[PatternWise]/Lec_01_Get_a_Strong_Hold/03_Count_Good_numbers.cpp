#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-good-numbers/description/

class Solution {
private:
    const int mod = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;
        return (int)((power(5, even_positions) * power(4, odd_positions)) % mod);
    }
};