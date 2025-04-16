// https://www.geeksforgeeks.org/problems/rotation4723/1


// User function template for C++
class Solution {
    private:
      int pivot(vector<int> &arr) {
          int start = 0;
          int end = arr.size() - 1;
  
          while (start < end) {
              int mid = start + (end - start) / 2;
              if (arr[mid] > arr[end]) {
                  start = mid + 1;
              } else {
                  end = mid;
              }
          }
          return start;
      }
    public:
      int findKRotation(vector<int> &arr) {
          return pivot(arr);
      }
  };