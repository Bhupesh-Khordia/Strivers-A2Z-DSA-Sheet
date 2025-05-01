// https://leetcode.com/problems/task-scheduler/

using namespace std;
#include <bits/stdc++.h>

// /*
class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            int maxi = 0;
            int maxCount = 0;
            vector<int> cnt(26);
            for(int i = 0; i < tasks.size(); i++) {
                cnt[tasks[i] - 'A']++;
                if(cnt[tasks[i] - 'A'] > maxi) {
                    maxi = cnt[tasks[i]-'A'];
                    maxCount = 1;
                } else if (cnt[tasks[i] - 'A'] == maxi) maxCount++;
            }
    
            return max((int)tasks.size(), (maxi - 1) * (n + 1) + maxCount);
        }
    };
    // */
    
    /*
    class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            unordered_map<char, int> freq;
            for (char task : tasks) {
                freq[task]++;
            }
    
            // Max heap for frequencies (use negative to simulate max-heap)
            priority_queue<int> maxHeap;
            for (auto entry : freq) {
                maxHeap.push(entry.second);
            }
    
            int time = 0;
    
            while (!maxHeap.empty()) {
                vector<int> temp;
                int cycle = n + 1;
    
                // Try to run up to n+1 tasks in each cycle
                while (cycle > 0 && !maxHeap.empty()) {
                    int curr = maxHeap.top(); maxHeap.pop();
                    if (curr > 1) {
                        temp.push_back(curr - 1);
                    }
                    time++;
                    cycle--;
                }
    
                // Push remaining back into heap
                for (int remaining : temp) {
                    maxHeap.push(remaining);
                }
    
                // If tasks remain and we used less than n+1 time, we need idle time
                if (!maxHeap.empty()) {
                    time += cycle; // add idle time
                }
            }
    
            return time;
        }
    };
    */