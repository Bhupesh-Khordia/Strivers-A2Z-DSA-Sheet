// https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        long long numcpy = num;
        for(long long x = 1; x < i; x++) {
            numcpy = numcpy >> 1;
        }
        long long bit = numcpy & 1;
        long long diff = pow(2, i - 1);
        cout << bit << " ";
        
        if(bit == 1) {
            cout << num << " " << (long long)num - diff;
        } else {
            cout << (long long)num + diff << " " << num;
        }
    }
};