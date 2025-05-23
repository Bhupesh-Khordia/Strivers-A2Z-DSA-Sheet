#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        Node * curr = head;
        for(int i = 1; i < x; i++) {
            curr = curr -> next;
        }
        
        if(curr -> prev != NULL) {
            curr -> prev -> next = curr -> next;
        } else {
            head = curr -> next;
        }
        if(curr -> next != NULL) {
            curr -> next -> prev = curr -> prev;
        }
        delete curr;
        return head;
    }
};