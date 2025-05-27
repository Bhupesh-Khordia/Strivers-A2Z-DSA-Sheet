#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-search/description/

class Solution {
private:
    bool solve(vector<vector<char>> &board, string word, int index, int i, int j, vector<vector<bool>> &visited) {
        if(index == word.length()) return true;

        // See left
        if(j > 0 && visited[i][j - 1] == false && board[i][j - 1] == word[index]) {
            visited[i][j - 1] = true;
            if (solve(board, word, index + 1, i, j - 1, visited)) return true;
            visited[i][j - 1] = false;
        }

        // See bottom
        if(i < board.size() - 1 && visited[i + 1][j] == false && board[i  + 1][j] == word[index]) {
            visited[i + 1][j] = true;
            if (solve(board, word, index + 1, i + 1, j, visited)) return true;
            visited[i + 1][j] = false;
        }

        // See right
        if(j < board[0].size() && visited[i][j + 1] == false && board[i][j + 1] == word[index]) {
            visited[i][j + 1] = true;
            if (solve(board, word, index + 1, i, j + 1, visited)) return true;
            visited[i][j + 1] = false;
        }

        // See top
        if(i > 0 && visited[i - 1][j] == false && board[i - 1][j] == word[index]) {
            visited[i - 1][j] = true;
            if (solve(board, word, index + 1, i - 1, j, visited)) return true;
            visited[i - 1][j] = false;
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Follow Up - Search Pruning
        unordered_map<char, int> count;
        for (char c : word) {
            count[c]++;
        }

        if (count[word[0]] > count[word.back()]) {
            reverse(word.begin(), word.end());
        }

        // Solution
        vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if(solve(board, word, 1, i, j, visited)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};