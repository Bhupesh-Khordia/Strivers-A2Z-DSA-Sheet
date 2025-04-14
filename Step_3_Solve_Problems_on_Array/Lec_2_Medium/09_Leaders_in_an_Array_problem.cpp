// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

/*
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int maxi = INT_MIN;
        vector<int> ans;
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(arr[i] >= maxi) {
                ans.push_back(arr[i]);
            }
            maxi = max(maxi, arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
*/

// https://www.naukri.com/code360/problems/leaders-in-an-array_873144?leftPanelTabValue=PROBLEM

// /*
#include <bits/stdc++.h> 
vector<int> findLeaders(vector<int> &elements, int n) {
    int maxi = INT_MIN;
    vector<int> ans;
    for(int i = n - 1; i >= 0; i--) {
        if(elements[i] > maxi) {
            ans.push_back(elements[i]);
        }
        maxi = max(maxi, elements[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
// */
