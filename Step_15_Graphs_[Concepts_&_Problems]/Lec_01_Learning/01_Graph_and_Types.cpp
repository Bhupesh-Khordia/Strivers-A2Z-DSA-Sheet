#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/graph-and-vertices/1

class Solution {
  public:
    long long count(int n) {
        return pow(2, n* (n - 1) / 2);
    }
};