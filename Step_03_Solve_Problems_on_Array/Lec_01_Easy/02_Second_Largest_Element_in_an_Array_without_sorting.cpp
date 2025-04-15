// https://www.geeksforgeeks.org/problems/second-largest3735/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int maxi = INT_MIN;
        int secondMaxi = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != maxi && arr[i] > secondMaxi) secondMaxi = arr[i];
        }
        
        return secondMaxi == INT_MIN ? -1 : secondMaxi;
    }
};
