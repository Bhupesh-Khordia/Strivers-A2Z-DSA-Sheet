// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

// User function template for C++

class Solution {
    private:
      int countStr(string&s, int k) {  // Less than or equal to k
          int l = 0, cnt = 0;
          int r = 0, n = s.length();
          
          unordered_map<char, int> freq;
          
          while(r < n) {
              freq[s[r]]++;
              
              while(freq.size() > k) {
                  freq[s[l]]--;
                  if(freq[s[l]] == 0) {
                      freq.erase(s[l]);
                  }
                  l++;
              }
              
              cnt += r - l + 1; // All substr ending with r;
              r++;
          }
          
          return cnt;
      }
    public:
      int countSubstr(string& s, int k) {
          return countStr(s, k) - countStr(s, k - 1);
      }
  };