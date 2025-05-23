#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        DLLNode* curr = head;
        while(true) {
            DLLNode* temp = curr -> next;
            curr -> next = curr -> prev;
            curr -> prev = temp;
            if(temp == NULL) return curr;
            curr = temp;
        }
    }
};