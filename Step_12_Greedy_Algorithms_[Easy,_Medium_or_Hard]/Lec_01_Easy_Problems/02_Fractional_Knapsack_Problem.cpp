// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

using namespace std;
#include <bits/stdc++.h>


// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class Item {
    public :
      int value;
      int weight;
      
      Item (int val, int wei) {
          value = val;
          weight = wei;
      }
  };
  
  class Solution {
    public:
      // Function to get the maximum total value in the knapsack.
      
      static bool cmp (pair<double, Item> a, pair<double, Item> b) {
          return a.first > b.first;
      }
      
      double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          vector<pair<double, Item>> data;
  
          for (int i = 0 ; i < val.size(); i++) {
              double ratio = (1.0 * val[i]) / wt[i];
              data.push_back({ratio, Item(val[i], wt[i])});
          }
  
          sort(data.begin(), data.end(), cmp);
  
          double cap = capacity;
          double ans = 0;
  
          for (auto& it : data) {
              Item item = it.second;
              if (item.weight <= cap) {
                  ans += item.value;
                  cap -= item.weight;
              } else {
                  ans += ((1.0 * cap) / item.weight) * item.value;
                  break;
              }
          }
  
          return ans;
      }
  };
  