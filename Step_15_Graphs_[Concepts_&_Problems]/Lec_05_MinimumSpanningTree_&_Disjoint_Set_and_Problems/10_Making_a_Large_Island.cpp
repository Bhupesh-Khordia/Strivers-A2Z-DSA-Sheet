#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/making-a-large-island/description/

class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank = vector<int>(n + 1, 0);
        size = vector<int>(n + 1, 1);
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

    void unionBySize(int u, int v) {
        int pu = parentFind(u);
        int pv = parentFind(v);
        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    
    int getSize(int u) {
        return size[u];
    }
};

class Solution {
private:
    int convert(int x, int y, int n) { return y + x * n; }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n * n);

        vector<pair<int, int>> dx = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Get all islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                
                int id = convert(i, j, n);

                for (int k = 0; k < 4; k++) {
                    int newX = i + dx[k].first;
                    int newY = j + dx[k].second;

                    if (newX < 0 || newX >= n || newY < 0 || newY >= n ||
                        grid[newX][newY] == 0)
                        continue;

                    int nbrId = convert(newX, newY, n);
                    ds.unionBySize(id, nbrId);
                }
            }
        }
        
        int maxArea = 0;
        // Use parent as unique ID for each component
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    // Try changing this 0 to 1
                    
                    unordered_set<int> parents;
                    
                    for (int k = 0; k < 4; k++) {
                        int newX = i + dx[k].first;
                        int newY = j + dx[k].second;
                        
                        if (newX < 0 || newX >= n || newY < 0 || newY >= n ||
                            grid[newX][newY] == 0)
                            continue;
                            
                        parents.insert(ds.parentFind(convert(newX, newY, n)));
                    }
                    
                    int area = 0;
                    for(auto it : parents) {
                        area += ds.getSize(ds.parentFind(it));
                    }
                    
                    maxArea = max(maxArea, area + 1);
                }
            }
        }
        
        // If no 0s are flipped, still find the largest existing island
        for (int i = 0; i < n * n; i++) {
            if (ds.parentFind(i) == i)
                maxArea = max(maxArea, ds.getSize(i));
        }
        
        return maxArea;
    }
};