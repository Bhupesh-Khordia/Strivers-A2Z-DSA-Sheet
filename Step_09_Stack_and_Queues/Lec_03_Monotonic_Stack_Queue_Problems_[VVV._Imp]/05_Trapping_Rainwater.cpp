//  https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
    private:
        vector<int> nextGr(vector<int> &nums) {
            int n = nums.size();
            vector<int> ans(n, -1);
            stack<int> st;
            for(int i = n - 1; i >= 0; i--) {
                while(!st.empty() && nums[i] > st.top()) {
                    st.pop();
                }
                if(!st.empty()) ans[i] = st.top();
                st.push(nums[i]);
            }
            return ans;
        }
    
        vector<int> rightMax(vector<int> &nums) {
            int n = nums.size();
            vector<int> ans(n, -1);
            int maxi = 0;
            for(int i = n - 1; i >= 0; i--) {
                ans[i] = maxi;
                maxi = max(maxi, nums[i]);
            }
            return ans;
        }
    public:
        int trap(vector<int>& height) {
            /*
            int prev = 0;
            int ans = 0;
            vector<int> nextGreater = nextGr(height); // Next Greater than or equal to
            vector<int> rightMaxi = rightMax(height); // Maximum element right side of an element.
            
            for(int i = 0; i < height.size(); i++) {
                if(prev != 0) {
                    if(nextGreater[i] == -1) {
                        prev = rightMaxi[i];
                    } else {
                        if(height[i] == prev) {
                            continue;
                        } else if(height[i] < prev) {
                            ans += (prev - height[i]);
                        } else {
                            prev = height[i];
                        }
                    }
                } else {
                    if(nextGreater[i] == -1) {
                        prev = rightMaxi[i];
                    } else {
                        prev = height[i];
                    }
                }
            }
            return ans;
            */
    
    
            // Another Approach without stack
            // /*
            int left = 0;
            int right = height.size() - 1;
    
            int leftMax = height[left];
            int rightMax = height[right];
            int ans = 0;
    
            while(left < right) {
                if(leftMax < rightMax) {
                    left++;
                    leftMax = max(leftMax, height[left]);
                    ans += leftMax - height[left];
                } else {
                    right--;
                    rightMax = max(rightMax, height[right]);
                    ans += rightMax - height[right];
                }
            }
    
            return ans;
            // */
        }
    };