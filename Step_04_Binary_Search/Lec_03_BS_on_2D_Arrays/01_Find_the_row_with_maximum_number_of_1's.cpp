// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

// User function template for C++
class Solution {
    public:
      int rowWithMax1s(vector<vector<int>> &arr) {
          int m = arr.size();
          int n = arr[0].size();
          int maxOne = 0;
          int ansRow = -1;
          
          for(int i = 0; i < m; i++) {
              int s = 0, e = n - 1;
              int cnt = 0;
              while(s <= e) {
                  int mid = s + (e - s) / 2;
                  if(arr[i][mid]) {
                      cnt = n - mid;
                      e = mid - 1;
                  } else {
                      s = mid + 1;
                  }
              }
              if(cnt > maxOne) {
                  maxOne = cnt;
                  ansRow = i;
              }
          }
          return ansRow;
      }
  };