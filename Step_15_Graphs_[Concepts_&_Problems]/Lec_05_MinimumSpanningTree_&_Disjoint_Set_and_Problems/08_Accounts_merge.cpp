#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/accounts-merge/description/

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mapMailNode;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if(mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    // Merge them
                    ds.unionByRank(i, mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> mailsOfNode(n);

        for(auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.parentFind(it.second); // Correct node will be the ultimate parent

            mailsOfNode[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            if(mailsOfNode[i].size()) {
                // Non empty
                sort(mailsOfNode[i].begin(), mailsOfNode[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]); // Name
                for(auto it : mailsOfNode[i]) {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};