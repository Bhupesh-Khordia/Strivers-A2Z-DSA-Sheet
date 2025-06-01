#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------------------------------------------------------------
// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
// --------------------------------------------------------------------------------------------------------------------------------


class Solution {
    private:
    void dfs(int i, int j, int basex, int basey, vector<vector<int>> &grid, vector<vector<bool>> &visited, 
        vector<pair<int, int>> &output, int m, int n) {
            visited[i][j] = true;
            
            output.push_back({i - basex, j - basey});
            
            vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            
            for(int x = 0; x < 4; x++) {
                int newx = i + directions[x].first;
                int newy = j + directions[x].second;
                
                if(newx >= 0 && newx < m && newy >= 0 && newy < n 
                    && !visited[newx][newy] && grid[newx][newy] == 1) {
                        dfs(newx, newy, basex, basey, grid, visited, output, m, n);
                    }
                }
            }
            public:
            int countDistinctIslands(vector<vector<int>>& grid) {
                set<vector<pair<int, int>>> set;
                
                int m = grid.size();
                int n = grid[0].size();
                vector<vector<bool>> visited(m, vector<bool> (n, false));
                
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        if(!visited[i][j] && grid[i][j] == 1)  {
                            vector<pair<int, int>> output;
                            dfs(i, j, i, j, grid, visited, output, m, n);
                            set.insert(output);
                        }
                    }
                }
                
                return set.size();
            }
        };
        



// --------------------------------------------------------------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/distinct-islands_630460?leftPanelTabValue=PROBLEM
// --------------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

void dfs(int i, int j, int basex, int basey, int** arr,
         vector<vector<bool>> &visited, vector<pair<int, int>> &shape,
         int n, int m) {
    
    visited[i][j] = true;
    shape.push_back({i - basex, j - basey});

    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    for (int d = 0; d < 4; d++) {
        int newx = i + directions[d].first;
        int newy = j + directions[d].second;
        
        if (newx >= 0 && newx < n && newy >= 0 && newy < m &&
            !visited[newx][newy] && arr[newx][newy] == 1) {
            dfs(newx, newy, basex, basey, arr, visited, shape, n, m);
        }
    }
}

int distinctIslands(int** arr, int n, int m)
{
    set<vector<pair<int, int>>> uniqueIslands;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && arr[i][j] == 1) {
                vector<pair<int, int>> shape;
                dfs(i, j, i, j, arr, visited, shape, n, m);
                uniqueIslands.insert(shape);
            }
        }
    }

    return uniqueIslands.size();
}
