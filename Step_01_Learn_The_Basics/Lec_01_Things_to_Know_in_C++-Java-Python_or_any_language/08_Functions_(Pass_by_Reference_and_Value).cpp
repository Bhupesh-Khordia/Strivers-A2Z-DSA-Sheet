# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/pass-by-reference-and-value/1


class Solution {
  public:
    vector<int> passedBy(int a, int &b) {
        return {a + 1, b + 2};
    }
};