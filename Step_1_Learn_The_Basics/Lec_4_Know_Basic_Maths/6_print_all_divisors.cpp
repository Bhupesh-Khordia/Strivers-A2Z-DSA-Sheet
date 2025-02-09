class Solution {
  private:
    int fi(int n, int number) {
        if(n == 0) return 0;
        return number % n == 0 ? n + fi(n-1, number) : fi(n-1, number);
    }
  public:
    int sumOfDivisors(int n) {
        int ans = 0;
        while(n) {
            ans += fi(n, n);
            n--;
        }
        return ans;
        
    }
};
