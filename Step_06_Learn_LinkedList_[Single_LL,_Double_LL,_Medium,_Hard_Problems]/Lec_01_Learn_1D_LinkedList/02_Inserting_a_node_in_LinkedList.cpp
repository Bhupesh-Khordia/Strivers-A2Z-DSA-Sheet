#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1

/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        if(head == NULL) return new Node(x);
        Node* curr = head;
        while(curr -> next != NULL) {
            curr = curr -> next;
        }
        curr -> next = new Node(x);
        return head;
    }
};