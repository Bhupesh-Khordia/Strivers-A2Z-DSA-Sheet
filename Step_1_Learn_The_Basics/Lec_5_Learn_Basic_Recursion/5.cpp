class Solution {
  public:
    int sumOfSeries(int n) {
        if(n == 0) return 0;
        
        return sumOfSeries(n - 1) + pow(n, 3);
    }
};
