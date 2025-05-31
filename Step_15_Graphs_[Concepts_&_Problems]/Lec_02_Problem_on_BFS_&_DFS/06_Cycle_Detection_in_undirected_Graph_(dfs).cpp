#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  private:
    void dfs(int i, vector<vector<int>> &adjList, int parent, vector<bool> &visited, bool &cycle) {
        visited[i] = true;
        
        for (int nbr : adjList[i]) {
            if(!visited[nbr]) {
                dfs(nbr, adjList, i, visited, cycle);
            } else {
                if(nbr != parent) cycle = true;
            }
        }
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        // BFS
        
        /*
        vector<bool> visited(V, false);
        queue<int> q;
        vector<int> parent(V, -1);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
                
                while(!q.empty()) {
                    int frontNode = q.front(); q.pop();
                    
                    for(auto nbr : adjList[frontNode]) {
                        if(!visited[nbr]) {
                            visited[nbr] = true;
                            q.push(nbr);
                            parent[nbr] = frontNode;
                        } else {
                            if(nbr != parent[frontNode]) return true;
                        }
                    }
                }
            }
        }
        
        return false;
        */
        

        
        // DFS
        
        // /*
        vector<bool> visited(V, false);
        bool cycle = false;
        
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, adjList, -1, visited, cycle);
            }
        }
        
        return cycle;
        // */
    }
};