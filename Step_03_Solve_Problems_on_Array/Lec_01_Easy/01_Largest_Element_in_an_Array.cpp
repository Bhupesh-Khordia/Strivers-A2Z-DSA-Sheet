// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution {
  public:
    int largest(vector<int> &arr) {
        int ans = 0;
        for(auto i : arr) {
            if (i > ans) ans = i;
        }
        return ans;
    }
};
