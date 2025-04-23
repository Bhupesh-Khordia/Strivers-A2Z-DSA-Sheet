// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
    private:
        int expand(string s, int left, int right) { // To Expand around a window.
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            left++;
            right--;
            return right - left + 1;
        }
    public:
        string longestPalindrome(string s) {
            int maxi = 1;
            int n = s.length();
            string ans = s.substr(0,1);
            for(int midIndex = 0; midIndex < n; midIndex++) {
                int i = midIndex, j = midIndex + 1;
                
                int x1 = expand(s, i, i); // Expand taking midIndex as center
                int x2 = expand(s, i, j); // Expand taking [midIndex, midIndex + 1] as center
    
                int maxAmongThem = max(x1, x2);
    
                if(maxAmongThem > maxi) {
                    maxi = maxAmongThem;
                    int start = i - (maxAmongThem - 1) / 2;
                    int end = i + maxAmongThem / 2;
                    ans = s.substr(start, end - start + 1);
                }
            }
    
            return ans;
        }
    };