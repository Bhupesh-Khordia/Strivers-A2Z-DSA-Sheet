#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
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
    }
};