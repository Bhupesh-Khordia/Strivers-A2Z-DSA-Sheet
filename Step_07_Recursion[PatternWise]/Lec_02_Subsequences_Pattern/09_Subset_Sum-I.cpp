#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/subset-sums2234/1

class Solution {
  private:
    void solve(vector<int> &arr, vector<int> &ans, int index, int sum) {
        if(index == arr.size()) {
            ans.push_back(sum);
            return;
        }
        
        // Include 
        solve(arr, ans, index + 1, sum + arr[index]);
        
        // Exclude 
        solve(arr, ans, index + 1, sum);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        solve(arr, ans, 0, 0);
        return ans;
    }
};