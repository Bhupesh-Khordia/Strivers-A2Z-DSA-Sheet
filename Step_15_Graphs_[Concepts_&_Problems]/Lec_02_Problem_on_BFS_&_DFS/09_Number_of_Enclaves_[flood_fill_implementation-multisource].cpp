# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-enclaves/description/



// Similar Question already done using DFS, so i will do this using BFS.
// https://leetcode.com/problems/surrounded-regions/description/ (Striver - Step 15 -> Lec 2 -> Q 8)

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }

            if(grid[i][n - 1] == 1) {
                q.push({i, n - 1});
                grid[i][n - 1] = 0;
            }
        }

        for(int i = 0; i < n; i++) {
            if(grid[0][i] == 1) {
                q.push({0, i});
                grid[0][i] = 0;
            }

            if(grid[m - 1][0] == 1) {
                q.push({m - 1, 0});
                grid[m - 1][0] = 0;
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++) {
                int newx = x + directions[i].first;
                int newy = y + directions[i].second;

                if(newx < m && newx >= 0 && newy < n && newy >=0 && grid[newx][newy] == 1) {
                    q.push({newx, newy});
                    grid[newx][newy] = 0;
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) cnt++;
            }
        }

        return cnt;
    }
};