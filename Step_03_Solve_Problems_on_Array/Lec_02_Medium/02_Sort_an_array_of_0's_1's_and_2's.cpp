// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cntZero = 0;
        int cntOne = 0;
        int cntTwo = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            switch (nums[i]) {
                case 0 :
                    cntZero++;
                    break;
                case 1 :
                    cntOne++;
                    break;
                case 2 :
                    cntTwo++;
                    break;
            }
        }
        for(int i = 0; i < n; i++) {
            if(cntZero != 0) {
                nums[i] = 0;
                cntZero--;
            } else if (cntOne != 0) {
                nums[i] = 1;
                cntOne --;
            } else {
                nums[i] = 2;
                cntTwo--;
            }
        }
    }
};
