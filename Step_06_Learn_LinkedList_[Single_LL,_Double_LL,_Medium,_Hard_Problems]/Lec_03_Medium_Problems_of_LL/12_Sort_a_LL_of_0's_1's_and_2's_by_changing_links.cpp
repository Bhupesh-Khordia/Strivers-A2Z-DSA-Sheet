#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        if(!head || !head -> next) return head;
        Node* dummyZero = new Node(-1);
        Node* temp1 = dummyZero;
        Node* dummyOne = new Node(-1);
        Node* temp2 = dummyOne;
        Node* dummyTwo = new Node(-1);
        Node* temp3 = dummyTwo;
        
        Node* curr = head;
        while(curr) {
            if(curr -> data == 0) {
                temp1 -> next = curr;
                temp1 = temp1 -> next;
            } else if (curr -> data == 1) {
                temp2 -> next = curr;
                temp2 = temp2 -> next;
            } else {
                temp3 -> next = curr;
                temp3 = temp3 -> next;
            }
            curr = curr -> next;
        }
        temp1 -> next = (dummyOne -> next) ? dummyOne -> next : dummyTwo -> next;
        temp2 -> next = dummyTwo -> next;
        temp3 -> next = NULL;
        Node* newHead = dummyZero -> next;
        delete dummyZero;
        delete dummyOne;
        delete dummyTwo;
        return newHead;
    }
};