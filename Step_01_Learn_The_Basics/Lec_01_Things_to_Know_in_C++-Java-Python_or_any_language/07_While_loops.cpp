#  include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/while-loop-printtable-java/1

class Solution {
  public:
    void calculateMultiples(int n) {
        int i = 11;
        while (--i) {
            cout << (n * i) << " ";
        }
    }
};