#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/

// No Leetcode premium. Poor guy :(

// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1


class Solution {
  private:
    void dfs(int i, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &component) {
        visited[i] = true;
        component.push_back(i);
        
        for(auto nbr : adjList[i]) {
            if(!visited[nbr]) dfs(nbr, adjList, visited, component);
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(V, false);
        vector<vector<int>> dfsTraversal;
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                vector<int> component;
                dfs(i, adjList, visited, component);
                dfsTraversal.push_back(component);
            }
        }
        
        return dfsTraversal;
    }
};
