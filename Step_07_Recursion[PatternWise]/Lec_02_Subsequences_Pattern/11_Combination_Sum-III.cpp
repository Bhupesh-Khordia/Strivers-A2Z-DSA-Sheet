#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
private:
    void solve(int size, int sum, int index, vector<int> &numbers, vector<vector<int>> &ans, vector<int> &output) {
        if(size == 0 && sum == 0) {
            ans.push_back(output);
            return;
        }
        if(size <= 0 || sum <= 0 || index >= 9) {
            return;
        }

        // Include 
        output.push_back(numbers[index]);
        solve(size - 1, sum - numbers[index], index + 1, numbers, ans, output);
        output.pop_back();

        // Exclude 
        solve(size, sum, index + 1, numbers, ans, output);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> numbers = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> output;
        solve(k, n, 0, numbers, ans, output);
        return ans;
    }
};