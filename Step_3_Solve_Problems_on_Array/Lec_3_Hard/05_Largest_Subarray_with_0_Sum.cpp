// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> map;
        int sum = 0;
        int ans = 0;
        int k = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            if(sum == k) {
                ans = i + 1;
            }
            
            int remaining = sum - k;
            if(map.find(remaining) != map.end()) {
                ans = max(ans, i - map[remaining]);   // If previously there was a subarray with same sum then all subarray part after that has sum 0.
            } else {
                map[sum] = i; // Upto index i sum = "sum"
            }
            
        }
        return ans;
    }
};
