#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    private:
    void solve(vector<string>& ans, vector<vector<int>>& m, int n, int x, int y, string output, vector<vector<int>> visited) {
        if(x == n - 1 && y == n - 1) {
            ans.push_back(output);
            return;
        }
        
        visited[x][y] = 1;
        
        int newx, newy;
        
        //Down
        newx = x + 1;
        newy = y;
        if(newx >=0 && newx < n && newy >=0 && newy < n && visited[newx][newy] == 0 && m[newx][newy] == 1) {
            output.push_back('D');
            solve(ans, m, n, newx, newy, output, visited);
            output.pop_back();
        }
        
        //Left
        newx = x;
        newy = y - 1;
        if(newx >=0 && newx < n && newy >=0 && newy < n && visited[newx][newy] == 0 && m[newx][newy] == 1) {
            output.push_back('L');
            solve(ans, m, n, newx, newy, output, visited);
            output.pop_back();
        }
        
        //Right
        newx = x;
        newy = y + 1;
        if(newx >=0 && newx < n && newy >=0 && newy < n && visited[newx][newy] == 0 && m[newx][newy] == 1) {
            output.push_back('R');
            solve(ans, m, n, newx, newy, output, visited);
            output.pop_back();
        }
        
        //Up
        newx = x - 1;
        newy = y;
        if(newx >=0 && newx < n && newy >=0 && newy < n && visited[newx][newy] == 0 && m[newx][newy] == 1) {
            output.push_back('U');
            solve(ans, m, n, newx, newy, output, visited);
            output.pop_back();
        }
        
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[n-1][n-1] == 0 || m[0][0] == 0) {
            return ans;
        }
        
        vector<vector<int>> visited = m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }
        
        int x = 0, y = 0;
        string output = "";
        
        solve(ans, m, n, x, y, output, visited);
        
        return ans;
        
    }
};

    