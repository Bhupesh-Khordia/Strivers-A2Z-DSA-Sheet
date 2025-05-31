#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/surrounded-regions/description/

class Solution {
private:
    void dfs (int i, int j, vector<vector<bool>> &visited, vector<vector<char>>& board, int m, int n) {
        if(i >= m || i < 0 || j >= n || j < 0 || board[i][j] != 'O' || visited[i][j]) return;

        visited[i][j] = true;

        dfs(i + 1, j, visited, board, m, n);
        dfs(i - 1, j, visited, board, m, n);
        dfs(i, j + 1, visited, board, m, n);
        dfs(i, j - 1, visited, board, m, n);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        // Can be done in O(1) space --> Instead of marking in visited, mark border O's in board with a placeholder like '#', then make remaining O's X and revert the placeholder's changes.
        
        for(int i = 0; i < m; i++) {
            if(!visited[i][0]) {
                dfs(i, 0, visited, board, m, n);
            }

            if(!visited[i][n - 1]) {
                dfs(i, n - 1, visited, board, m, n);
            }
        }

        for(int i = 0; i < n; i++) {
            if(!visited[0][i]) {
                dfs(0, i, visited, board, m, n);
            }

            if(!visited[m - 1][i]) {
                dfs(m - 1, i, visited, board, m, n);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};