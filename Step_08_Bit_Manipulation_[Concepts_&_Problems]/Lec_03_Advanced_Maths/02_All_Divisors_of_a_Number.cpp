#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1

class Solution {
  public:
    void print_divisors(int n) {
        vector<int> ans;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                cout << i << " ";
                if(n / i != i) ans.push_back(n/i);
            }
        }
        for(int i = ans.size() - 1; i >=0; i--) {
            cout << ans[i] << " ";
        }
    }
};