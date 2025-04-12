class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIndex = 0, negIndex = 1;
        vector<int> ans(nums.size());

        for(auto i : nums) {
            if(i > 0) {
                ans[posIndex] = i;
                posIndex += 2;
            } else {
                ans[negIndex] = i;
                negIndex += 2;
            }
        }
        return ans;



        // Brute Force (MLE)


        // vector<int> positiveIndex;
        // vector<int> negativeIndex;
        // for(int i = 0; i < nums.size(); i++) {
        //     if(nums[i] < 0) negativeIndex.push_back(i);
        //     else positiveIndex.push_back(i);
        // }
        // int i = 0, j = 0;
        // int n1 = positiveIndex.size();
        // int n2 = negativeIndex.size();
        // bool positive = true;
        // vector<int> ans;
        // while(i < n1 && j < n2) {
        //     if(positive) {
        //         ans.push_back(nums[positiveIndex[i]]);
        //     } else {
        //         ans.push_back(nums[negativeIndex[j]]);
        //     }
        // }
        // return ans;
    }
};
