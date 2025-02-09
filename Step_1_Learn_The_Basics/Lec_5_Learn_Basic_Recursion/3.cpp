class Solution {
  public:
    void printNos(int N) {
        if(n == 0) return;
        cout << n << " ";
        printNos(n-1);
    }
};
