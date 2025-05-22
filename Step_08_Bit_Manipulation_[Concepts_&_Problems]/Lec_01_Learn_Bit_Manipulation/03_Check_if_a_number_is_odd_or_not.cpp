// https://www.geeksforgeeks.org/problems/odd-or-even3618/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isEven(int n) {
        return !(n & 1);
    }
};