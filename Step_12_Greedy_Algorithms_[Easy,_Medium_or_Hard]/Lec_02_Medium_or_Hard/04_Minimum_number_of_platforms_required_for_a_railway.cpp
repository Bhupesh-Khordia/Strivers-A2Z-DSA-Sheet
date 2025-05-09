// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

using namespace std;
#include <bits/stdc++.h>


class Solution {
    public:
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          // Your code here
          int res = 1;
          sort(arr.begin(), arr.end());
          sort(dep.begin(), dep.end());
          int temp = 0;
          int n1 = arr.size();
          int n2 = dep.size();
          
          int i = 0, j = 0;
          while( i < n1 && j < n2)
          {
              if(arr[i] <= dep[j])
              {
                  i++, temp++;
                  res = max(res, temp);
              }
              else
              {
                  temp--, j++;
              }
          }
          return res;
      }
  };