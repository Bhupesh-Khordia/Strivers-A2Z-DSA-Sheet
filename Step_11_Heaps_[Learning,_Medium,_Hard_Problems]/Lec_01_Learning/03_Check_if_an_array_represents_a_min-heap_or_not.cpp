// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    bool isMaxHeap(int arr[], int n) {
        for(int i = 0; i < n / 2; i++) {
            int leftChild = arr[2*i + 1];
            int rightChild = arr[2*i + 2];
            
            if(arr[i] < leftChild || arr[i] < rightChild) return false;
        }
        return true;
    }
};