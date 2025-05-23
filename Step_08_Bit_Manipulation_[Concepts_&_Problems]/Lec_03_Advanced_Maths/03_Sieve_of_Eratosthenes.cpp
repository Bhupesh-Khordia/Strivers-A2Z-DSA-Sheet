#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-primes/description/

class Solution {
public:
    int countPrimes(int n) {
        // Normal Code TLE....

        // int count = 0;
        // if(n <= 2) {
        //     return 0;
        // }
        // count++;
        // for(int i = 3; i < n; i++) {
        //     bool isPrime = true;
        //     for(int j = 2; j < sqrt(i); j++) {
        //         if(i % j == 0) {
        //             isPrime = false;
        //         }
        //     }
        //     if(isPrime) {
        //         count++;
        //     }
        // }
        // return count;


        // Sieve of Erasthosthenes...
        if (n <= 2) return 0;

        int count = 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i < n; ++i) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        for (int i = 2; i < n; ++i) {
            if (prime[i]) ++count;
        }

        return count;
    }
};