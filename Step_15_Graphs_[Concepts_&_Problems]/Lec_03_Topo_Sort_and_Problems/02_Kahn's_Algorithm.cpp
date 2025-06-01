#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  private:
    // visited states: 0 = unvisited, 1 = visiting, 2 = visited
    bool dfs(int node, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &ans) {
        visited[node] = 1;

        for(auto nbr : adjList[node]) {
            if(visited[nbr] == 0) {
                if(dfs(nbr, adjList, visited, ans)) return true;
            } else if (visited[nbr] == 1) {
                // dfs function has been called for this node and it is visited
                // Cycle
                return true;
            }
        }
        ans.push_back(node);
        visited[node] = 2; // Fully Visited
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Two methods - BFS(Kahn's Algo) & DFS\
        
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        
        // 1. DFS 
        /*
        vector<int> visited(V, false);
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(visited[i] == 0) {
                if(dfs(i, adjList, visited, ans)) return true;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return false;
        */
        
        // 2. BFS(Kahn's Algorithm)
        // /*
        vector<int> indegree(V, 0);
        for(auto i : edges) {
            indegree[i[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()) {
            int front = q.front(); q.pop();
            
            ans.push_back(front);
            
            for(auto nbr : adjList[front]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        
        if(ans.size() == V) return false;
        return true; // Cycle present
        // */
    }
};