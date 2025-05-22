// https://www.geeksforgeeks.org/problems/shortest-job-first/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        long long sum = 0;
        long long cumSum = 0;
        sort(bt.begin(), bt.end());
        
        for(int i = 0; i < bt.size() - 1; i++) {
            cumSum += bt[i];
            sum += cumSum;
        }
        
        return sum / bt.size();
    }
};