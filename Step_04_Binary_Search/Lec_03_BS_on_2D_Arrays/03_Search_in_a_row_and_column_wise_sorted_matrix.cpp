// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            int col = matrix[0].size();
            int rowIndex = row - 1;
            int colIndex = 0;
            while (rowIndex >= 0 && colIndex < col) {
                int element = matrix[rowIndex][colIndex];
                if(element == target) {
                    return true;
                }
                if(element > target) {
                    rowIndex--;
                }
                else{
                    colIndex++;
                }
            }
            return false;
        }
    };