// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

using namespace std;
#include <bits/stdc++.h>

class KthLargest {
    private:
        int k;
        priority_queue<int, vector<int>, greater<int>> pq; // K Greatest elements
    public:
        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for(int num : nums) {
                pq.push(num);
                if(pq.size() > k) pq.pop(); // maintain size k
            }
        }
        
        int add(int val) {
            pq.push(val);
            if(pq.size() > k) pq.pop();
            return pq.top();
        }
    };
    
    /**
     * Your KthLargest object will be instantiated and called as such:
     * KthLargest* obj = new KthLargest(k, nums);
     * int param_1 = obj->add(val);
     */