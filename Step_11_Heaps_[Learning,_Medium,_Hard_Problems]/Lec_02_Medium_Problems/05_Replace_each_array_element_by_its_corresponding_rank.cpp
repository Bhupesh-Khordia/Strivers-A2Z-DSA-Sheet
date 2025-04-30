// https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

using namespace std;
#include <bits/stdc++.h>


// User function Template for C++

class Solution {
    public:
  
      vector<int> replaceWithRank(vector<int> &arr, int N) {
          priority_queue<int, vector<int>, greater<int>> minHeap;
          
          for(int i : arr) {
              minHeap.push(i);
          }
          
          int cnt = 1;
          unordered_map<int, int> map;
          
          while(!minHeap.empty()) {
              int temp = minHeap.top(); minHeap.pop();
              
              if(map.find(temp) == map.end()) {
                  map[temp] = cnt++;
              }
          }
          
          for(int i = 0; i < arr.size(); i++) {
              arr[i] = map[arr[i]];
          }
          
          return arr;
      }
  };