// https://leetcode.com/problems/find-a-peak-element-ii/description/

class Solution {
    public:
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int m = mat.size();
            int n = mat[0].size();
            int left = 0, right = n - 1;
    
            while (left <= right) {
                int midCol = left + (right - left) / 2;
                
                // Find the row index of the max element in midCol
                int maxRow = 0;
                for (int i = 0; i < m; ++i) {
                    if (mat[i][midCol] > mat[maxRow][midCol]) {
                        maxRow = i;
                    }
                }
    
                int midVal = mat[maxRow][midCol];
                int leftVal = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
                int rightVal = (midCol < n - 1) ? mat[maxRow][midCol + 1] : -1;
    
                if (midVal >= leftVal && midVal >= rightVal) {
                    return {maxRow, midCol};
                } else if (leftVal > midVal) {
                    right = midCol - 1;
                } else {
                    left = midCol + 1;
                }
            }
    
            return {};
        }
    };
    