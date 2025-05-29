#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1

// User function Template for C++

class Solution {
  public:
    bool isPossible(int a, int b) {
        if(a == 2 || b == 2) {
            if(a != 2 || b != 2) {
                return true;
            }
        }
        return false;
    }
};