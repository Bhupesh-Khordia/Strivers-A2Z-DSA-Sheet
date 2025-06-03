#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/articulation-point-1/1

//User function Template for C++

class Solution {
  private:
     void dfs(int node, int parent, vector<bool> &visited, vector<int> &tin, 
                vector<int> &low, int &timer, vector<bool> &mark, 
                vector<int> adjacencyList[]) {
        
        visited[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        
        int child = 0;
        
        for(auto adj : adjacencyList[node]) {
            if(adj == parent) continue;

            if(!visited[adj]) {
                // Call for dfs.
                dfs(adj, node, visited, tin, low, timer, mark, adjacencyList);

                // Update Low.
                low[node] = min(low[node], low[adj]);

                // Check is this point is an articulation point.
                if(low[adj] >= tin[node] && parent != -1) {
                    // Accumulation point detected.
                    mark[node] = true;
                }
                
                child++;
            }
            else {
                // No need to call DFS, as it is already visited.

                // Update low.
                low[node] = min(low[node], tin[adj]);

                // No need to check for bridge as if adj is alrady visited then this edge can not be bridge.
            }
        }
        
        if(parent == -1 && child > 1) {
            mark[node] = true;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Tarjan's Algorithm

        vector<int> tin(V, -1);
        vector<int> low(V, -1);
        int timer = 0;
        vector<bool> visited(V, false);

        vector<bool> mark(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, -1, visited, tin, low, timer, mark, adj);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(mark[i]) {
                ans.push_back(i);
            }
        }
        return ans.size() == 0 ? vector<int>{-1} : ans;
    }
};