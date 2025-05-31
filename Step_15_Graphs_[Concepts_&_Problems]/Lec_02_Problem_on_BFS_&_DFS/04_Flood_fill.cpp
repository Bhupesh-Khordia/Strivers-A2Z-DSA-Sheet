#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/flood-fill/description/

class Solution {
private:
    void dfs (int sr, int sc, int color, int originalColor, vector<vector<int>> &image) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != originalColor) return;

        image[sr][sc] = color;

        dfs(sr - 1, sc ,color, originalColor, image);
        dfs(sr + 1, sc ,color, originalColor, image);
        dfs(sr, sc + 1 ,color, originalColor, image);
        dfs(sr, sc - 1 ,color, originalColor, image);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        if(originalColor == color) return image;

        dfs(sr, sc, color, originalColor, image);
        return image;
    }
};