// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

using namespace std;
#include <bits/stdc++.h>

class Solution {
    public:
      // Function to find the maximum number of meetings that can
      // be performed in a meeting room.
      
      static bool cmp (pair<int, int> a, pair<int, int> b) {
          return (a.second < b.second);
      }
      
      int maxMeetings(vector<int>& start, vector<int>& end) {
          vector<pair<int, int>> meet;
          for(int i = 0; i < start.size(); i++) {
              meet.push_back(make_pair(start[i], end[i]));
          }
          
          sort(meet.begin(), meet.end(), cmp);
          
          int cnt = 1;
          int ansEnd = meet[0].second;
          for(int i = 1; i < meet.size(); i++) {
              if(meet[i].first > ansEnd) {
                  cnt ++;
                  ansEnd = meet[i].second;
              }
          }
          
          return cnt;
      }
  };