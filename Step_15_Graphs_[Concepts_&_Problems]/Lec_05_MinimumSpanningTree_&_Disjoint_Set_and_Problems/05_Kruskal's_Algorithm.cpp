#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Utility class for Kruskal's Algorithm
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



class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Two algorithms - Prim and Kruskal
        
        
        
        //1. Prim's Algorithm
        /*
        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq; // Weight, node, parent
        
        vector<bool> visited(V, false);
        
        int sum = 0; // Sum of weights of edges in MST
        
        // This will not be used in this question though.
        vector<pair<int, int>> MST; // To store edges in MST
        
        
        pq.push({0, {0, -1}});
        
        while(!pq.empty())  {
            auto it = pq.top();
            
            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            
            pq.pop();
            
            if(visited[node]) continue;
            visited[node] = true;
            
            // Add to MST
            sum += wt;
            if(parent != -1) MST.push_back({node, parent});
            
            // Push neighbor nodes in PQ
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edW = it[1];

                if (!visited[adjNode]) {
                    pq.push({edW, {adjNode, node}});
                }
            }
        }
        
        // for(int i = 0; i < MST.size(); i++) cout << MST[i].first << " " << MST[i].second << endl;
        
        return sum;
        */
        
        
        
        //2. Kruskal's Algorithm
        vector<pair<int, pair<int, int>>> edges; // Weight, node u, node v
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        
        vector<pair<int, int>> MST; // Will not be needed in this question though.
        int sum = 0; // Sum of edges weight in MST
        
        for(int i = 0; i < edges.size(); i++) {
            int wt = edges[i].first;
            int node = edges[i].second.first;
            int adjNode = edges[i].second.second;
            
            if(ds.parentFind(node)  != ds.parentFind(adjNode)) {
                // Add in MST
                sum += wt;
                MST.push_back({node, adjNode});
                
                // Union
                ds.unionByRank(node, adjNode);
            }
        }
        
        // for(int i = 0; i < MST.size(); i++) cout << MST[i].first << " " << MST[i].second << endl;

        return sum;
    }
};

