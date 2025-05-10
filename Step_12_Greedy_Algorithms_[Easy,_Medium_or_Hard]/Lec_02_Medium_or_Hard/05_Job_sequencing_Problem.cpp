// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

using namespace std;
#include <bits/stdc++.h>

class Solution {
    public:
    
      
      // Ye code TLE de rha hai (love babbar)
      
      // bool static comp(pair<int, int>&a, pair<int, int>&b){
      //     return a.first>b.first;
      // }
    
      // vector<int> jobSequencing(vector<int> &deadline, 
      // vector<int> &profit) {
      //     // code here
      //     int maxDeadline = *max_element(deadline.begin(), deadline.end());
          
      //     int n=profit.size();
      //     vector<pair<int, int>>v;
          
      //     for(int i=0; i<n; i++){
      //         v.push_back({profit[i], deadline[i]});
      //     }
          
      //     sort(v.begin(), v.end(), comp);
          
      //     vector<bool> schedule(maxDeadline + 1, false); // 1-based index
          
      //     int ans=0, cnt=0;
          
      //     for(int i=0; i<n; i++){
      //         int currProfit = v[i].first;
      //         int currDead = v[i].second;
              
      //         for(int k = currDead; k > 0; k--) {
      //             if(!schedule[k]) {
      //                 // Kaam kar skte hai
      //                 schedule[k] = true;
      //                 ans += currProfit;
      //                 cnt++;
      //                 break;
      //             }
      //         }
      //     }
      //     return {cnt, ans};
      // }
      
      
      
      bool static comp(pair<int, int>&a, pair<int, int>&b){
          return a.first>b.first;
      }
    
      vector<int> jobSequencing(vector<int> &deadline, 
      vector<int> &profit) {
          // code here
          int n=profit.size();
          vector<pair<int, int>>v;
          
          for(int i=0; i<n; i++){
              v.push_back({profit[i], deadline[i]});
          }
          
          sort(v.begin(), v.end(), comp);
          
          vector<int>tmp(n+1, -1);
          
          int ans=0, cnt=0;
          
          for(int i=0; i<n; i++){
              int ind=v[i].second;
              while(ind>=1 && tmp[ind]>=0){
                  ind--;
              }
              if(ind>=1 && tmp[ind]<0){
                  cnt++;
                  ans+=v[i].first;
                  tmp[ind]=v[i].second;
              }
          }
          return {cnt, ans};
      }
  };
  