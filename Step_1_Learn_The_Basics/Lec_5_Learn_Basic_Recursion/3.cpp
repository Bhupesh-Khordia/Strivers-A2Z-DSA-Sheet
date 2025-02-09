class Solution {
  public:
    // Complete this function
    void printNos(int n) {
        if(n == 0) return;
        printNos(n-1);
        cout << n << " ";
    }
};
