#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/path-with-minimum-effort/description/

//APPROACH1 - DFS (TLE)

// class Solution {
//     int rows, cols, minEffort = INT_MAX;
//     vector<vector<bool>> visited;

//     void dfs(vector<vector<int>>& h, int x, int y, int currentMax) {
//         if (x == rows - 1 && y == cols - 1) {
//             minEffort = min(minEffort, currentMax);
//             return;
//         }

//         visited[x][y] = true;
//         vector<int> dx{0, 0, 1, -1}, dy{-1, 1, 0, 0};
//         for (int i = 0; i < 4; ++i) {
//             int nx = x + dx[i], ny = y + dy[i];
//             if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && !visited[nx][ny]) {
//                 int diff = abs(h[x][y] - h[nx][ny]);
//                 dfs(h, nx, ny, max(currentMax, diff));
//             }
//         }
//         visited[x][y] = false;
//     }

// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         rows = heights.size();
//         cols = heights[0].size();
//         visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
//         dfs(heights, 0, 0, 0);
//         return minEffort;
//     }
// };

//APPROACH 2 - BFS + Binary Search
// class Solution {
//     int rows, cols;

//     bool canReach(vector<vector<int>>& h, int mid) {
//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));
//         queue<pair<int,int>> q;
//         q.push({0,0});
//         visited[0][0] = true;

//         vector<int> dx{0, 0, 1, -1}, dy{-1, 1, 0, 0};
//         while (!q.empty()) {
//             auto [x, y] = q.front(); q.pop();
//             if (x == rows - 1 && y == cols - 1) return true;

//             for (int i = 0; i < 4; ++i) {
//                 int nx = x + dx[i], ny = y + dy[i];
//                 if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
//                     !visited[nx][ny] &&
//                     abs(h[x][y] - h[nx][ny]) <= mid) {
//                     visited[nx][ny] = true;
//                     q.push({nx, ny});
//                 }
//             }
//         }
//         return false;
//     }

// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         rows = heights.size();
//         cols = heights[0].size();

//         int low = 0, high = 1e6, ans = 0;
//         while (low <= high) {
//             int mid = (low + high) / 2;
//             if (canReach(heights, mid)) {
//                 ans = mid;
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         return ans;
//     }
// };

//APPROACH 3 - DIJKSTRA with slight modifications
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>>distance(rows, vector<int>(cols,1e9));

        //min absolute diff, coordinates 
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        distance[0][0] = 0;

        vector<int>dirx{0,0,1,-1};
        vector<int>diry{-1,1,0,0};

        while(!pq.empty()){
            int dis = pq.top().first;
            int xcor = pq.top().second.first;
            int ycor = pq.top().second.second;
            pq.pop();

            for(int i=0; i<4; i++){
                int newx = xcor + dirx[i];
                int newy = ycor + diry[i];

                if(newx<0 || newx>=rows || newy<0 || newy>=cols)continue;
                int diff = max(abs(heights[xcor][ycor]-heights[newx][newy]),dis);
                if(diff < distance[newx][newy]){
                    distance[newx][newy] = diff;
                    pq.push({distance[newx][newy],{newx,newy}});
                }
            }
        }

        
        return distance[rows-1][cols-1]!=1e9?distance[rows-1][cols-1]:0;

    }
};

