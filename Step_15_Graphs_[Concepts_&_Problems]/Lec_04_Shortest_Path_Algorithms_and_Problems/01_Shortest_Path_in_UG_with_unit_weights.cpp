#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        queue<int> q;
        vector<int> dist(adj.size(), -1);  // Use -1 directly for unvisited
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : adj[node]) {
                if (dist[nbr] == -1) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }

        return dist;
    }
};