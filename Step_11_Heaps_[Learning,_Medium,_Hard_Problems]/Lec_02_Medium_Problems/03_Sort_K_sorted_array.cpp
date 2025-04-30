// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

using namespace std;
#include <bits/stdc++.h>


// User function Template for C++

class Node {
    public:
      int data;
      int row;
      int col;
      
      Node(int x, int i, int j) {
          data = x;
          row = i;
          col = j;
      }
  };
  
  struct compare {
      bool operator()(Node* a, Node* b) {
          return a->data > b->data;
      }
  };
  
  class Solution {
    public:
      // Function to merge k sorted arrays.
      vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
          priority_queue<Node*, vector<Node*>, compare> minHeap;
          
          for(int i = 0; i < K; i++) {
              Node* temp = new Node(arr[i][0], i, 0);
              minHeap.push(temp);
          }
          
          vector<int> ans;
          
          while(!minHeap.empty()) {
              Node* temp = minHeap.top(); minHeap.pop();
              
              ans.push_back(temp -> data);
              
              if(temp -> col + 1 < arr[temp -> row].size()) {
                  Node* newNode = new Node (arr[temp -> row][temp -> col + 1], temp -> row, temp -> col + 1);
                  minHeap.push(newNode);
              }
          }
          
          return ans;
      }
  };