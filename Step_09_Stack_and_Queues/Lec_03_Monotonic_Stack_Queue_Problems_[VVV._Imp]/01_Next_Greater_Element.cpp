// https://leetcode.com/problems/next-greater-element-i/description/

class Solution {
    private:
        unordered_map<int, int> nextGreater(vector<int> &nums) {
            int n = nums.size();
            unordered_map<int, int> map;
            stack<int> st;
            for(int i = n - 1; i >= 0; i--) {
                while(!st.empty() && nums[i] >= st.top()) {
                    st.pop();
                }
                if(!st.empty()) map[nums[i]] = st.top();
                else map[nums[i]] = -1;
                st.push(nums[i]);
            }
            return map;
        }
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> nextGreat = nextGreater(nums2);
            int m = nums1.size();
            vector<int> ans (m, -1);
    
            for(int i = 0; i < m; i++) {
                ans[i] = nextGreat[nums1[i]];
            }
            return ans;
        }
    };