#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int i = 0; i < n; i++) dist[i][i] = 0;

        // Floyd Warshal Algorithm

        for(int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) {
                        dist[i][j] = min (dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        // Given that no negative cycle

        vector<int> noOfCities(n, 0);

        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold) {
                    noOfCities[i]++;
                }
            }
        }

        int mini = *min_element(noOfCities.begin(), noOfCities.end());

        for(int i = noOfCities.size() - 1; i>= 0; i--) {
            if(noOfCities[i] == mini) return i;
        }

        return -1; // Will never reach here.
    }
};