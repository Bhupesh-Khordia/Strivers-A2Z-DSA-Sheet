#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Reverse Graph and use topological sort

        int v = graph.size();
        vector<vector<int>> adjList(v);
        vector<int> indegree(v, 0);
        queue<int> q;

        for(int i = 0; i < v; i++) {
            for(auto nbr : graph[i]) {
                adjList[nbr].push_back(i);
                indegree[i]++;
            }

            if(indegree[i] == 0) q.push(i);
        }

        vector<int> safeNodes;
        while(!q.empty()) {
            int front = q.front(); q.pop();

            safeNodes.push_back(front);

            for(int nbr : adjList[front]) {
                indegree[nbr]--;

                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};