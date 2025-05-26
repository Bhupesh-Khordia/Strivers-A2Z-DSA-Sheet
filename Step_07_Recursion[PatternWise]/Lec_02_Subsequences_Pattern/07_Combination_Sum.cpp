#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum/description/

class Solution {
private:
    void solve(vector<int> &candidates, int target, int index, int sum,vector<int> &output, vector<vector<int>> &ans) {
        if(sum == target) {
            ans.push_back(output);
            return;
        }

        if(sum > target || index == candidates.size()) return;

        // include and stay there
        output.push_back(candidates[index]);
        solve(candidates, target, index, sum + candidates[index], output, ans);
        output.pop_back();

        // Exclude and go next
        solve(candidates, target, index + 1, sum, output, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, target, 0, 0, output, ans);
        return ans;
    }
};