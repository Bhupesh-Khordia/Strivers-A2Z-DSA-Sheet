#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        const int INF = 1e8;
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if (dist[i][via] != INF && dist[via][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
        
        // To detect negative cycle add THIs
        /*
        for(int i = 0; i < n; i++) {
            if(dist[i][i] < 0) return false; // Negative Cycle
        }
        */
    }
};