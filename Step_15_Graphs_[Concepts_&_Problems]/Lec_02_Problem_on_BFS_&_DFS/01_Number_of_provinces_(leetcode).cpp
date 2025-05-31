#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-provinces/description/

class Solution {
private:
    void dfs(int i, vector<bool> &visited, vector<vector<int>> &isConnected) {
        visited[i] = true;

        for(int nbr = 0; nbr < isConnected.size(); nbr++) {
            if(!visited[nbr] && isConnected[i][nbr] && nbr != i) {
                dfs(nbr, visited, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<bool> visited(v, false);
        int cnt = 0;

        for(int i = 0; i < v; i++) {
            if(!visited[i]) {
                cnt++;
                dfs(i, visited, isConnected);
            }
        }
        return cnt;
    }
};