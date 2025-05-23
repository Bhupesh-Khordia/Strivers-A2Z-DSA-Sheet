#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int cnt = 1;
        while(head -> next != NULL) {
            cnt++;
            head = head -> next;
        }
        return cnt;
    }
};