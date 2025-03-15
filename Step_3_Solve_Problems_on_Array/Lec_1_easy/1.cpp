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
