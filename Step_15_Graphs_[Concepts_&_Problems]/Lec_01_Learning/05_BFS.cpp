# include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<bool> visited(adj.size(), false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        vector<int> bfsTraversal;
        
        while(!q.empty()) {
            int top = q.front(); q.pop();
            bfsTraversal.push_back(top);
            
            for(auto nbr : adj[top]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        
        return bfsTraversal;
    }
};