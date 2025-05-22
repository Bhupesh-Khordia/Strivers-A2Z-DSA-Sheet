// https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    pair<int, int> get(int a, int b) {
        a = a ^ b;
        b = a ^ b; // = (a ^ b) ^ b = a
        a = a ^ b; // = (a ^ b) ^ a = b
        
        return make_pair(a, b);
    }
};