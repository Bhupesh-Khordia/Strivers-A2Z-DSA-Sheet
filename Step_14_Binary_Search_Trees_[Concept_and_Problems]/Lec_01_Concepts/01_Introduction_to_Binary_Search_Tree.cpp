#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/binary-search-trees/1


class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] <= arr[i - 1]) return false;
        }
        return true;
    }
};