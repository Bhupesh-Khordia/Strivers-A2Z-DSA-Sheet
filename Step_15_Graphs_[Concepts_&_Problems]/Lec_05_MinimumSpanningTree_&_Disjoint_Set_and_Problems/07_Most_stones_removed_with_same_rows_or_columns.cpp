#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank = vector<int>(n + 1, 0);
        parent = vector<int>(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int parentFind(int node) {
        if (parent[node] == node) return node;
        return parent[node] = parentFind(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int pu = parentFind(u);
        int pv = parentFind(v);
        if (pu == pv) return;

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
    int removeStones(vector<vector<int>>& stones) {
        // Make a graph with edges between stones that are in same row or column
        // Ans - stones.size() - no. of connected components in graph

        int maxRow = 0;
        int maxCol = 0;

        for(int i = 0; i < stones.size(); i++) {
            maxRow =  max(maxRow, stones[i][0]);
            maxCol =  max(maxCol, stones[i][1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);

        /*
          0 1 2 3                 4 5 6 7
        0                       0
        1               -->     1
        2                       2
        3                       3
        */

        for(auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;

            ds.unionByRank(nodeRow, nodeCol);
        }

        unordered_set <int> parents;

        for(auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;

            parents.insert(ds.parentFind(nodeRow));
            parents.insert(ds.parentFind(nodeCol));
        }

        return stones.size() - parents.size();
    }
};