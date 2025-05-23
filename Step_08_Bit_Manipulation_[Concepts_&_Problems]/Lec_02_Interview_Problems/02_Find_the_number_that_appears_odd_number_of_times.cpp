// https://leetcode.com/problems/single-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR of 2 same numbers is 0
        int x = 0;
        for(auto i : nums) {
            x = x ^ i;
        }
        return x;
    }
};