// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution {
    public:
      int kthElement(vector<int>& a, vector<int>& b, int k) {
          // Watch video for better explanation
          int n1 = a.size();
          int n2 = b.size();
  
          if(n1 > n2) return kthElement(b, a, k);
          int s = max(0, k - n2), e = min(k, n1);
          // Searching for number of elements from arr1 in left partition
  
          while(s <= e) {
              int mid = s + (e - s) / 2;
  
              int index1 = mid;
              int index2 = k - mid;
  
              int l1 = INT_MIN;  // max element from arr1 in left part
              int l2 = INT_MIN;
              int r1 = INT_MAX; // Min element from arr1 in right part
              int r2 = INT_MAX;
  
              if (index1 < n1)
                  r1 = a[index1];
              if (index2 < n2)
                  r2 = b[index2];
              if (index1 - 1 >= 0)
                  l1 = a[index1 - 1];
              if (index2 - 1 >= 0)
                  l2 = b[index2 - 1];
              
              if(max(l1, l2) <= min(r1, r2)) {
                  // Valid Solution
                  return max(l1, l2);
              } else if (l1 > r2) {
                  e = mid - 1;
              } else {
                  s = mid + 1;
              }
          }
          return 0;
      }
  };