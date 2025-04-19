// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int start = 0;
            int row = matrix.size();
            int col = matrix[0].size();
            int end = (row * col) - 1;
            int mid = start + ((end - start) / 2);
    
            while(start <= end) {
                int midValue = matrix[mid / col][mid % col];
                if(midValue == target){
                    return true;
                }
                if(midValue > target) {
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
                mid = start + ((end - start) / 2);
            }
            return false;
        }
    };