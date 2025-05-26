#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
private:
    void solve(vector<int> &candidates, int target, int index, vector<int> &output, vector<vector<int>> &ans) {
        if(target == 0)  {
            ans.push_back(output);
            return;
        }

        if(index == candidates.size() || target < 0) return;

        // Include
        output.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index + 1, output, ans);
        output.pop_back();

        // Exclude

        // Before exclude ignore duplicates
        int next = index + 1;
        while(next < candidates.size() && candidates[next] == candidates[next - 1]) {
            next++;
        }

        solve(candidates, target, next, output, ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> output;
        vector<vector<int>> ans;
        solve(candidates, target, 0, output, ans);
        return ans;
    }
};