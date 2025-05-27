#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sudoku-solver/description/

class Solution {
private:
    bool isSafe(vector<vector<char>>& sudoku, int row, int col, char val) {
        for(int i = 0; i < 9; i++) {

            // Row check
            if(sudoku[row][i] == val) return false;

            // Col Check
            if(sudoku[i][col] == val) return false;

            // 3x3 Matrix check
            if(sudoku[3*(row/3) + i / 3][3 * (col / 3) + i % 3] == val) return false;

        }
        return true;
    }

    bool solve(vector<vector<char>>& sudoku) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(sudoku[row][col] == '.') {
                    for(char i = '1'; i <= '9'; i++) {
                        if(isSafe(sudoku, row, col, i)) {
                            sudoku[row][col] = i;
                            if(solve(sudoku)) {
                                return true;
                            }
                            else {
                                sudoku[row][col] = '.';   // Backtracking
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};