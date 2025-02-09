// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

class Solution {
    public:
      bool armstrongNumber(int n) {
          int sum = 0;
          int number = n;
          while(n) {
              int digit = n % 10;
              sum += (pow(digit, 3));
              n = n / 10;
          }
          return sum == number ;
      }
  };