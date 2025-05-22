// https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

/*

References -

Brute Force - https://www.youtube.com/watch?v=nttpF8kwgd4

Optimal - https://www.youtube.com/watch?v=PW2aK1QBBoc

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int largestPowerOfTwo (int n) {
        int x = 0;
        while((1 << x) <= n) x++;
        return x - 1;
    }
  public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n) {
        if(n == 0) return 0;
        
        int x = largestPowerOfTwo(n);
        int y = x * (1 << (x - 1)); // x * (2 ^ (x - 1))
        int z = n - (1 << x);
        
        return y + z + 1 + countSetBits(z);
    }
};
