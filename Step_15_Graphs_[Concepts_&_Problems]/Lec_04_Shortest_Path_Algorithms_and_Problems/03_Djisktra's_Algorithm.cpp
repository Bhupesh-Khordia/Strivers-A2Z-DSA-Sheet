#include <bits/stdc++.h>
using namespace std;


// -------------------------------------------------------------------------------------------------------------------------------
// Dijkstra Algorithm - 
// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// -------------------------------------------------------------------------------------------------------------------------------

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Two Possible Implementations - 1. Using Priority Queue   2. Using Set
        
        
        // 1. Using Priority Queue
        
        /*
        unordered_map<int, vector<pair<int, int>>> adjList;  // A, {b, C}  Edges = A -- B with weight C
        
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance from source, node}
        pq.push({0, src});
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            
            for(auto it : adjList[node]) {
                int nbr = it.first;
                int edgeWt = it.second;
                
                if(distance + edgeWt < dist[nbr]) {
                    dist[nbr] = distance + edgeWt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        
        return dist;
        */
        
        
        
        // 2. Using Set
        
        unordered_map<int, vector<pair<int, int>>> adjList;  // A, {b, C}  Edges = A -- B with weight C
        
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        set<pair<int, int>> s; // {distance from source, node}
        s.insert({0, src});
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        while(!s.empty()) {
            auto it = * (s.begin());
            
            int node = it.second;
            int distance = it.first;
            s.erase(it);
            
            for(auto itr : adjList[node]) {
                int nbr = itr.first;
                int edgeWt = itr.second;
                
                if(distance + edgeWt < dist[nbr]) {
                    if(dist[nbr] != INT_MAX) {
                        // Larger distance to nbr exists in set. ERASE IT !!!
                        s.erase({dist[nbr], nbr});
                    }
                    
                    dist[nbr] = distance + edgeWt;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        
        return dist;
        
    }
};


// -------------------------------------------------------------------------------------------------------------------------------
// Shortest Path in Weighted undirected graph (Print the shortest path) - 
// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// -------------------------------------------------------------------------------------------------------------------------------


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adjList;

        // Build adjacency list (convert to 0-indexed)
        for (int i = 0; i < m; i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            int wt = edges[i][2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        int src = 0;
        int dest = n - 1;

        vector<int> dist(n, INT_MAX);
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        set<pair<int, int>> s; // {distance, node}
        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty()) {
            pair<int, int> top = *s.begin();
            s.erase(s.begin());

            int node = top.second;
            int distance = top.first;

            for (int i = 0; i < adjList[node].size(); i++) {
                int nbr = adjList[node][i].first;
                int wt = adjList[node][i].second;

                if (distance + wt < dist[nbr]) {
                    if (dist[nbr] != INT_MAX) {
                        s.erase({dist[nbr], nbr});
                    }
                    dist[nbr] = distance + wt;
                    parent[nbr] = node;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        // No path found
        if (dist[dest] == INT_MAX) return {-1};

        vector<int> path;
        while (parent[dest] != dest) {
            path.push_back(dest + 1);  // convert back to 1-indexed
            dest = parent[dest];
        }
        path.push_back(src + 1);
        
        path.push_back(dist[n - 1]);
        reverse(path.begin(), path.end());
        return path;
    }
};
