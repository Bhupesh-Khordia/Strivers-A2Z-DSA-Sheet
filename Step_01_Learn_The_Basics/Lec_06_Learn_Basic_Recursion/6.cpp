class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        vector<long long> ans;
        long long i = 1;
        while(i <= n) {
            ans.push_back(i);
            i *= ans.size() + 1;
        }
        return ans;
    }
};
