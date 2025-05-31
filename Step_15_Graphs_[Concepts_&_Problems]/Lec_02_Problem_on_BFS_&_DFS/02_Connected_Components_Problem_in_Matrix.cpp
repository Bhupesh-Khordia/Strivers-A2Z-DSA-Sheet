#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/number-of-provinces/1


class Solution {
  private:
    void dfs(int i, vector<bool> &visited, vector<vector<int>> &adj) {
        visited[i] = true;

        for(int nbr = 0; nbr < adj.size(); nbr++) {
            if(!visited[nbr] && adj[i][nbr] && nbr != i) {
                dfs(nbr, visited, adj);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V, false);
        int cnt = 0;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                cnt++;
                dfs(i, visited, adj);
            }
        }
        return cnt;
    }
};