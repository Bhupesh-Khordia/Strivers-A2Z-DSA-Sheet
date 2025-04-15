// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // We can use two pointer approach (both starting from same end of array) if only positive elements in array.
        /*
        int i = 0, j = 0;
        int sum = arr[0], ans = 0;
        while(i < arr.size() && j < arr.size()) {
            if(sum == k) {
                ans = max(ans, j - i + 1);
                j++;
                if(j != arr.size()) sum += arr[j];
            } else if (sum < k) {
                j++;
                if(j != arr.size()) sum += arr[j];
            } else {
                i++;
                sum -= arr[i - 1];
            }
        }
        return ans;
        */
        
        
        // When positives & negatives both in array.
        // /*
        unordered_map<int, int> map;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum == k) {
                ans = max(ans, i + 1);
            }
            int remaining = sum - k;
            if(map.find(remaining) != map.end()) {
                int length = map[remaining];
                ans = max(ans, i + 1 - length);
            }
            if(map.find(sum) == map.end()) {
                map[sum] = i + 1;
            }
        }
        return ans;
        // */
    }
};
