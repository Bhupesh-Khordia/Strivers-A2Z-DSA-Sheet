#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1


class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int i = 0; i < V - 1; i++) {
            for(int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // To detect -ve cycle.
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) { 
                // Negative Cycle  (weight is still decreasing)
                return {-1};
            }
        }
        
        return dist;
    }
};
