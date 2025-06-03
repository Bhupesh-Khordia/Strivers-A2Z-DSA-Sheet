#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        // Answer = number of connected components - 1 (for n components, n - 1 edges will be needed to connect them all)
        DisjointSet ds (n);

        int nc = 0;
        for(int i=0;i<connections.size();i++){
            ds.unionByRank(connections[i][0],connections[i][1]);
        }
        for(int i=0;i<n;i++){
            if(ds.parentFind(i)==i){
                nc++;
            }
        }
        return nc - 1;
    }
};