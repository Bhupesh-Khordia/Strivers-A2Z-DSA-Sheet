// https://leetcode.com/problems/largest-odd-number-in-string/description/

class Solution {
    public:
        string largestOddNumber(string num) {
            int maxIndex = -1;
            for(int i = 0; i < num.length(); i++) {
                if((static_cast<int>(num[i]) -  48) & 1) {
                    maxIndex = i;
                }
            }
            return maxIndex == -1 ? "" : num.substr(0, maxIndex + 1);
        }
    };