#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;

        // BFS from (0, 0)

        queue<pair<int, int>> q;
        q.push({0, 0});

        grid[0][0] = 2; // Visited
        int level = 1;

        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},          {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto node = q.front(); q.pop();
                int x = node.first;
                int y = node.second;

                if(x == grid.size() - 1 && y == grid[0].size() - 1) return level;

                for(int i = 0; i < 8; i++) {
                    int newx = x + directions[i].first;
                    int newy = y + directions[i].second;

                    if(newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] == 0) {
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                    }
                } 
            }
            level++;
        }

        return -1;
    }
};