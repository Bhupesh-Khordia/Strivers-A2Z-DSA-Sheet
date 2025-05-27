#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution {
  private:
    bool solve(int v, vector<vector<int>> &adjList, int m, int index, vector<int> &colors) {
        if(index == v) return true;
        
        vector<int> neighbors = adjList[index];
        
        unordered_set<int> neighborColors;
        
        for(auto i : neighbors) {
            if(colors[i] != -1) neighborColors.insert(colors[i]);
        }
        
        if(neighborColors.size() > m - 1) return false;
        
        for(int i = 1; i <= m; i++) {
            if(neighborColors.find(i) == neighborColors.end()) {
                colors[index] = i;
                if (solve(v, adjList, m, index + 1, colors)) return true;
                colors[index] = -1;
            }
        }
        
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adjList(v);
        vector<int> colors (v, -1);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        return solve(v, adjList, m, 0, colors);
    }
};