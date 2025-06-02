#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra's Algo

        unordered_map<int, vector<pair<int, int>>> adjList;

        for(int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adjList[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int distance = it.first;
            int node = it.second;

            for(auto nbr : adjList[node]) {
                int neighbor = nbr.first;
                int edgeWt = nbr.second;

                if(distance + edgeWt < dist[neighbor]) {
                    dist[neighbor] = distance + edgeWt;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        int minDist = INT_MIN;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            minDist = max(dist[i], minDist);
        }

        return minDist;
    }
};