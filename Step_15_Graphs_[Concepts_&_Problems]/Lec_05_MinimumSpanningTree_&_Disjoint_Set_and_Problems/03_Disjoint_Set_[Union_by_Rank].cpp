#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------------------------------------------------------------
// https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1
// --------------------------------------------------------------------------------------------------------------------------------

// This is a very bad question.
int find(int par[], int x) {
    if(par[x] == x)
    return x;
    
    return par[x] = find(par, par[x]);
}

void unionSet(int par[], int x, int z) {
    int a = find(par, x);
    int b = find(par, z);
    
    par[a] = b;
}



// --------------------------------------------------------------------------------------------------------------------------------
// Complete code of Union Find in Disjoint set
// --------------------------------------------------------------------------------------------------------------------------------

/*
class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank = vector<int>(n + 1, 0);
        size = vector<int>(n + 1, 1);
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

    void unionBySize(int u, int v) {
        int pu = parentFind(u);
        int pv = parentFind(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
*/