#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  private:
    void dfs(int i, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &dfsTraversal) {
        visited[i] = true;
        dfsTraversal.push_back(i);
        
        for(auto nbr : adjList[i]) {
            if(!visited[nbr]) dfs(nbr, adjList, visited, dfsTraversal);
        }
    }
    
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        /*
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> dfsTraversal;
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited, dfsTraversal);
            }
        }
        
        return dfsTraversal;
        */
        
        // Since the graph is given as connected, no need of for loop.
        
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> dfsTraversal;
        
        dfs(0, adj, visited, dfsTraversal);
        
        return dfsTraversal;
    }
};