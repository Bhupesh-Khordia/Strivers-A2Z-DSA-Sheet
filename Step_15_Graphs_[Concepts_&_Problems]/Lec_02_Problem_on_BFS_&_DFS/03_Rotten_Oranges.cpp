#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        int cnt = 0;

        while(!q.empty()) {
            int size = q.size();

            bool added = false;

            for(int x = 0; x < size; x++) {
                pair<int, int> top = q.front(); q.pop();

                int i = top.first;
                int j = top.second;

                if(i - 1 >= 0 && grid[i - 1][j] == 1) {
                    added = true;
                    q.push({i - 1, j});
                    grid[i - 1][j] = 2;
                }

                if(i + 1 < m && grid[i + 1][j] == 1) {
                    added = true;
                    q.push({i + 1, j});
                    grid[i + 1][j] = 2;
                }

                if(j - 1 >= 0 && grid[i][j - 1] == 1) {
                    added = true;
                    q.push({i, j - 1});
                    grid[i][j - 1] = 2;
                }

                if(j + 1 < n && grid[i][j + 1] == 1) {
                    added = true;
                    q.push({i, j + 1});
                    grid[i][j + 1] = 2;
                }

            }
            if(added) cnt++;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return cnt;
    }
};