#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/critical-connections-in-a-network/description/

class Solution {
private:
    void dfs(int node, int parent, vector<bool> &visited, vector<int> &tin, 
                vector<int> &low, int &timer, vector<vector<int>> & bridges, 
                unordered_map<int, list<int>> &adjacencyList) {
        
        visited[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        
        for(auto adj : adjacencyList[node]) {
            if(adj == parent) continue;

            if(!visited[adj]) {
                // Call for dfs.
                dfs(adj, node, visited, tin, low, timer, bridges, adjacencyList);

                // Update Low.
                low[node] = min(low[node], low[adj]);

                // Check is this edge is a bridge.
                if(low[adj] > tin[node]) {                 // Can't reach to node from adj if this edge is removed.
                    // Bridge detected.
                    bridges.push_back({adj, node});
                }
            }
            else {
                // No need to call DFS, as it is already visited.

                // Update low.
                low[node] = min(low[node], low[adj]);

                // No need to check for bridge as if adj is alrady visited then this edge can not be bridge.
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Creating Adjacency List.

        unordered_map<int, list<int>> adj;

        for(int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        // Tarjan's Algorithm

        vector<int> tin(n);
        vector<int> low(n);
        int timer = 0;
        vector<bool> visited(n, false);

        vector<vector<int>> bridges;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, -1, visited, tin, low, timer, bridges, adj);
            }
        }

        return bridges;
    }
};