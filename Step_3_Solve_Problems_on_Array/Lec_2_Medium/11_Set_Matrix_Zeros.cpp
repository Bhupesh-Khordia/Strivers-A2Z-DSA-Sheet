// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Bad Approach
        /*
        unordered_set<int> row;
        unordered_set<int> col;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(row.find(i) != row.end() || col.find(j) != col.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
        */


        // Better approach

        int m = matrix.size();
        int n = matrix[0].size();

        bool col0 = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = true;
                    }
                }
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j <n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Now handle the first row and col
        if(matrix[0][0] == 0){
            // Every row 0
            for(int j = 1 ; j<n ;j++){
                matrix[0][j] = 0;
            }
        }
        if(col0){
            // Every column 0
            for(int i = 0 ;i<m;i++){
                matrix[i][0] = 0;
            }
        }
    }
};
