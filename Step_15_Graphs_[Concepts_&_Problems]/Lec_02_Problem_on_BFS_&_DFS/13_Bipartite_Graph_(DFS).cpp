#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
private:
    bool dfs(int i, vector<vector<int>> &graph, vector<int> &color, int c) {
        color[i] = c;

        for(int nbr : graph[i]) {
            if(color[nbr] == -1) {
                if(!dfs(nbr, graph, color, 1 - c)) return false;
            } else if(color[nbr] == color[i]) {
                return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // DFS
        /*
        int v = graph.size();
        vector<int> color (v, -1); // -1 = uncoloured, 0 & 1 are two colors

        for(int i = 0; i < v; i++) {
            if(color [i] == -1) {
                if(!dfs(i, graph, color, 0)) return false;
            }
        }

        return true;
        */

        // BFS

        int v = graph.size();
        vector<int> color(v, -1); // -1 = uncolored

        for(int i = 0; i < v; ++i) {
            if(color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(int nbr : graph[node]) {
                        if(color[nbr] == -1) {
                            color[nbr] = 1 - color[node];
                            q.push(nbr);
                        } else if(color[nbr] == color[node]) {
                            return false; // Same color conflict
                        }
                    }
                }
            }
        }

        return true;
    }
};