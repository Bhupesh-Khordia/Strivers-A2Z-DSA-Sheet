#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        Node* curr = head;
        for(int i = 0; i < pos; i++) {
            curr = curr -> next;
        }
        Node* temp = curr -> next;
        curr -> next = new Node(data);
        curr -> next -> next = temp;
        curr -> next -> prev = curr;
        if(temp != NULL)
            temp -> prev = curr -> next;
        return head;
    }
};