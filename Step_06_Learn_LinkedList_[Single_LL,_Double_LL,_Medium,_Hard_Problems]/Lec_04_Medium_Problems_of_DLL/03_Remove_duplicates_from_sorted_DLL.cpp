#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        if(!head || !head -> next) return head;
        
        Node* prev = head;
        Node* curr = head -> next;
        while(curr) {
            if(prev -> data == curr -> data) {
                prev -> next = curr -> next;
                if(curr -> next) {
                    curr -> next -> prev = prev;
                }
                Node* toDelete = curr;
                curr = curr -> next;
                delete toDelete;
            } else {
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
    }
};