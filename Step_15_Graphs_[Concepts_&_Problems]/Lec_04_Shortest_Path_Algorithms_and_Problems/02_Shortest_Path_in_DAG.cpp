#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

// User function Template for C++
class Solution {
  private:
    void dfs(int node, vector<bool> &visited, stack<int> &topo, unordered_map<int, vector<pair<int, int>>> &adjList) {
        visited[node] = true;
        
        for(auto nbr : adjList[node]) {
            if(!visited[nbr.first]) {
                dfs(nbr.first, visited,  topo, adjList);
            }
        }
        
        topo.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adjList;  // A, {b, C}  Edges = A -- B with weight C
        
        for(int i = 0; i < E; i++) {
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        // Get Topological Sort
        
        stack<int> topo;
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, visited, topo, adjList);
            }
        }
        
        
        // Get distances
        
        vector<int> dist (V, INT_MAX);
        dist[0] = 0;
        
        while(!topo.empty()) {
            int node = topo.top(); topo.pop();
            
            if(dist[node] != INT_MAX) {
                for(auto nbr : adjList[node]) {
                    int edgeWt = nbr.second;
                    int nbrNode = nbr.first;
                    
                    if(dist[node] + edgeWt < dist[nbrNode]) {
                        dist[nbrNode] = dist[node] + edgeWt;
                    }
                }
            }
        }
        
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
    }
};
