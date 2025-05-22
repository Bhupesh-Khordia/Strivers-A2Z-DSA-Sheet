// https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

// https://www.youtube.com/watch?v=WqGb7159h7Q

#include <bits/stdc++.h>
using namespace std;


class Solution {
  private:
    int xorUpto (int n) {
        if(n % 4 == 0) return n;
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n + 1;
        if(n % 4 == 3) return 0;
    }
  public:
    int findXOR(int l, int r) {
        if(l == 1) return xorUpto (r);
        return xorUpto(l - 1) ^ xorUpto(r);
    }
};