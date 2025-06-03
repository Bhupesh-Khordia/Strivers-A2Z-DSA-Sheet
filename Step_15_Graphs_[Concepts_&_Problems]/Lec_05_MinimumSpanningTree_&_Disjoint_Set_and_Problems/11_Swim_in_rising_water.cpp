#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/swim-in-rising-water/description/

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank = vector<int>(n + 1, 0);
        parent = vector<int>(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int parentFind(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = parentFind(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int pu = parentFind(u);
        int pv = parentFind(v);
        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 1) return grid[0][0];

        DisjointSet ds(n*n);

        vector<pair<int, pair<int, int>>> elevations; // elevation, i, j

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                elevations.push_back({grid[i][j], {i, j}});
            }
        }

        sort(elevations.begin(), elevations.end());

        int time = 0;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < elevations.size(); i++) {
            time = elevations[i].first;
            int x = elevations[i].second.first;
            int y = elevations[i].second.second;

            for(int i = 0; i < 4; i++) {
                int newx = x + directions[i].first;
                int newy = y + directions[i].second;

                if(newx < 0 || newx >= n || newy < 0 || newy >= n || grid[newx][newy] > time) continue;

                // Neighbour has been visited before current node
                ds.unionByRank(time, grid[newx][newy]);

                if(ds.parentFind(grid[0][0]) == ds.parentFind(grid[n - 1][n - 1])) return time;
            }
        }

        return -1; // Willl never reach here
    }
};