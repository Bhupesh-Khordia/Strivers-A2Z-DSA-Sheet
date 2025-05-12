// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

using namespace std;
#include <bits/stdc++.h>

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> cnt;
        
        int left = 0, right = 0;
        int n = arr.size();
        int ans = 0;
        while(right < n) {
            cnt[arr[right]]++;
            while(cnt.size() > 2) {
                cnt[arr[left]]--;
                if(cnt[arr[left]] == 0) cnt.erase(arr[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};