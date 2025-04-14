// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows == 1) return ans;
        ans.push_back({1, 1});

        for(int i = 2; i < numRows; i++) {
            vector<int> temp;
            temp.push_back(1);

            int n = ans.size() - 1;
            for(int i = 0; i < ans[n].size() - 1; i++) {
                temp.push_back(ans[n][i] + ans[n][i + 1]);
            }
            temp.push_back(1);
            
            ans.push_back(temp);
        }
        return ans;
    }
};
