// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

class Solution {
    public:
      int nthRoot(int n, int m) {
          int s = 0, e = m;
          int ans = -1;
          while(s <= e) {
              int mid = s + (e - s)/2;
              if(pow(mid, n) == m) {
                  ans = mid;
                  break;
              } else if( pow(mid, n) > m) {
                  e = mid - 1;
              } else {
                  s = mid + 1;
              }
          }
          return ans;
      }
  };
  