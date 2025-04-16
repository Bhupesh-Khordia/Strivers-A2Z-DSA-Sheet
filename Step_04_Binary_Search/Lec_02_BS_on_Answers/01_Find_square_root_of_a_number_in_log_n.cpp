// https://www.geeksforgeeks.org/problems/square-root/1



// Function to find square root
// x: element to find square root
class Solution {
    public:
      int floorSqrt(int n) {
          int s = 0, e = n;
          int ans;
          while(s <= e) {
              int mid = s + (e - s)/2;
              if(mid * mid == n) {
                  ans = mid;
                  break;
              } else if( mid * mid > n) {
                  e = mid - 1;
              } else {
                  ans = mid;
                  s = mid + 1;
              }
          }
          return ans;
      }
  };