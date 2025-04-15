// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1

class Solution {
    public:
      vector<int> getFloorAndCeil(int x, vector<int> &arr) {
          // TC - O (n logn)
          /*
          sort(arr.begin(), arr.end());
          int s = 0, e = arr.size() - 1;
          int floorVal = -1;
          int ceilVal = -1;
          while(s <= e) {
              int mid = s + ((e - s) / 2);
              
              if(arr[mid] == x) {
                  floorVal = arr[mid];
                  ceilVal = arr[mid];
                  break;
              } else if(arr[mid] > x) {
                  ceilVal = arr[mid];
                  e = mid - 1;
              } else {
                  floorVal = arr[mid];
                  s = mid + 1;
              }
          }
          return {floorVal, ceilVal};
          */
          
          // TC - O(n)
          int floorVal = -1, ceilVal = -1;
          for(int i : arr) {
              if(i == x) {
                  floorVal = i;
                  ceilVal = i;
                  break;
              } else if (i < x) {
                  floorVal = max(floorVal, i);
              } else {
                  if(ceilVal != -1) ceilVal = min(ceilVal, i);
                  else ceilVal = i;
              }
          }
          return {floorVal, ceilVal};
      }
  };