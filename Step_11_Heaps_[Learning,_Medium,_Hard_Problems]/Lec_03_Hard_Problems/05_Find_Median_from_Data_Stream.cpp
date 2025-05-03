using namespace std;
#include <bits/stdc++.h>

// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
    private:
        double median;
        priority_queue<double> maxHeap;
        priority_queue<double, vector<double>, greater<double>> minHeap;
    
        int signum (int a, int b) {
            if (a  == b ) return 0;
            else if (a  > b ) return 1;
            else return -1;
        }
    public:
        MedianFinder() {
            median = -1;
        }
        
        void addNum(int num) {
            int element = num;
            switch(signum(maxHeap.size(), minHeap.size())) {
                case 0 :
                    if(element > median) {
                        minHeap.push(element);
                        median = minHeap.top();
                    }
                    else {
                        maxHeap.push(element);
                        median = maxHeap.top();
                    }
                    break;
                
                case 1:
                    if(element > median) {
                        minHeap.push(element);
                        median = (minHeap.top() + maxHeap.top()) / 2;
                    }
                    else {
                        minHeap.push(maxHeap.top());
                        maxHeap.pop();
                        maxHeap.push(element);
                        median = (minHeap.top() + maxHeap.top()) / 2;
                    }
                    break;
    
                case -1:
                    if(element > median) {
                        maxHeap.push(minHeap.top());
                        minHeap.pop();
                        minHeap.push(element);
                        median = (minHeap.top() + maxHeap.top()) / 2;
                    }
                    else {
                        maxHeap.push(element);
                        median = (minHeap.top() + maxHeap.top()) / 2;
                    }
                    break;
            }
        }
        
        double findMedian() {
            return median;
        }
    };
    
    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */