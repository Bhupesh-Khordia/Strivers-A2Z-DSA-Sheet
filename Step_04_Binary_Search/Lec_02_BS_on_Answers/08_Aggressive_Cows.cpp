// https://www.spoj.com/problems/AGGRCOW/

/*

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSol(vector<int> &stalls, int k, int mid) {
    int cowCount = 1;
    int lastCow = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastCow >= mid) {
            cowCount++;
            lastCow = stalls[i];
            if (cowCount == k) {
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int end = stalls.back() - stalls.front();
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossibleSol(stalls, k, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        for (int i = 0; i < n; ++i) {
            cin >> stalls[i];
        }
        cout << aggressiveCows(stalls, c) << endl;
    }
    return 0;
}
*/



// https://www.naukri.com/code360/problems/aggressive-cows_1082559?leftPanelTabValue=PROBLEM

/*
bool isPossibleSol(vector<int> &stalls, int k, int mid) {
    int cowCount = 1;
    int lastCow = stalls[0];
    for(int i = 0; i < stalls.size(); i++) {
        if(stalls[i] - lastCow >= mid) {
            cowCount++;
            if(cowCount == k) {
                return true;
            }
            lastCow = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int maxi = -1;
    for(int i = 0; i < stalls.size(); i++) {
        maxi = max(maxi, stalls[i]);
    }
    int end = maxi;

    int mid = start + ((end - start) / 2);
    int ans = -1;

    while(start <= end) {
        if(isPossibleSol(stalls, k, mid)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}
*/



// https://www.geeksforgeeks.org/problems/aggressive-cows/0

class Solution {
    private:
       bool isPossibleSol(vector<int> &stalls, int k, int mid) {
          int cowCount = 1;
          int lastCow = stalls[0];
          for(int i = 0; i < stalls.size(); i++) {
              if(stalls[i] - lastCow >= mid) {
                  cowCount++;
                  if(cowCount == k) {
                      return true;
                  }
                  lastCow = stalls[i];
              }
          }
          return false;
      }
    public:
  
      int aggressiveCows(vector<int> &stalls, int k) {
          sort(stalls.begin(), stalls.end());
          int start = 0;
          int maxi = -1;
          for(int i = 0; i < stalls.size(); i++) {
              maxi = max(maxi, stalls[i]);
          }
          int end = maxi;
      
          int mid = start + ((end - start) / 2);
          int ans = -1;
      
          while(start <= end) {
              if(isPossibleSol(stalls, k, mid)) {
                  ans = mid;
                  start = mid + 1;
              }
              else {
                  end = mid - 1;
              }
              mid = start + ((end - start) / 2);
          }
          return ans;
      }
  };