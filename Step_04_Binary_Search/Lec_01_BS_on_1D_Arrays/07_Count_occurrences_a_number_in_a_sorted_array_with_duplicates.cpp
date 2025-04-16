// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

class Solution {
    public:
      int countFreq(vector<int>& arr, int target) {
          int startIndex = -1, endIndex = -1;
          int s = 0, e = arr.size() - 1;
  
          while(s <= e) {
              int mid = s + ((e - s) / 2);
  
              if(arr[mid] == target ) {
                  startIndex = mid;
                  e = mid - 1;
              } else if(arr[mid] < target ) {
                  s = mid + 1;
              } else {
                  e = mid - 1;
              }
          }
          s = 0, e = arr.size() - 1;
          while(s <= e) {
              int mid = s + (e - s) / 2;
  
              if(arr[mid] == target ) {
                  endIndex = mid;
                  s = mid + 1;
              } else if(arr[mid] < target ) {
                  s = mid + 1;
              } else {
                  e = mid - 1;
              }
          }
          
          return startIndex == -1 ? 0 : endIndex - startIndex + 1;
      }
  };