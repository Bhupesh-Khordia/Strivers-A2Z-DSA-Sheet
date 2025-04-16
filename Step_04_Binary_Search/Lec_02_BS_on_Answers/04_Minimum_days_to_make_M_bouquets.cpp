// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution {
    private:
        bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {
            int cnt = 0; // count to store k consecutive flowers
            int tempCnt = 0;
            for(int i = 0; i < bloomDay.size(); i++) {
                if(bloomDay[i] <= mid) tempCnt++;
                else {
                    tempCnt = 0;
                }
                if(tempCnt == k) {
                    cnt++;
                    tempCnt = 0;
                }
            }
    
    
            return cnt >= m;
        }
    public:
        int minDays(vector<int>& bloomDay, int m, int k) {
            int start = *min_element(bloomDay.begin(), bloomDay.end());
            int end = *max_element(bloomDay.begin(), bloomDay.end());
            int ans = -1;
    
            while(start <= end) {
                int mid = start + (end - start) / 2;
    
                if(isPossible(bloomDay, m, k, mid)) {
                    ans = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
    
            return ans;
        }
    };