#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/n-queens/description/

class Solution {
private:
    void addSolution(vector<vector<int>> &board, vector<vector<string>> &ans, int n) {
        vector<string> temp;
        for(int i = 0; i < n; i++) {
            string str = "";
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 1) {
                    str += "Q";
                }
                else {
                    str += ".";
                }
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        int x = row;
        int y = col;

        // Check on left side of the row.
        while(y >= 0) {
            if(board[x][y] == 1) return false;
            y--;
        }

        // Check on left ascending diagonal.
        x = row, y = col;
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 1) return false;
            y--;
            x--;
        }

        // Check on left descending diagonal.
        x = row, y = col;
        while(x < n && y >= 0) {
            if(board[x][y] == 1) return false;
            y--;
            x++;
        }

        return true;

    }

    void solve(int col, vector<vector<int>> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            addSolution(board, ans, n);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) {
                // Can place queen on this row and col.

                board[row][col] = 1;
                solve(col + 1, board, ans, n);
                board[row][col] = 0;
            }
        }


    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board (n, vector<int> (n, 0));


        solve(0, board, ans, n);

        return ans;
    }
};