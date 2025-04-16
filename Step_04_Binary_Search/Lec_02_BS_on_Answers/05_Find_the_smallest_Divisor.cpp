// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution {
    private:
        bool isPossible(vector<int> &nums, int threshold, int mid) {
            long long thres = 0;
            for(int i = 0; i < nums.size(); i++) {
                thres += ceil((double)nums[i] / mid);
            }
            return thres <= threshold;
        }
    public:
        int smallestDivisor(vector<int>& nums, int threshold) {
            int s = 1, e = *max_element(nums.begin(), nums.end());
            int ans = -1;
            while(s <= e) {
                int mid = s + (e - s) / 2;
                if(isPossible(nums, threshold, mid)) {
                    ans = mid;
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            return ans;
        }
    };