#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/find-length-of-loop/1

/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Floyd's cycle detection algorithm
        Node* fast = head;
        Node* slow = head;
        bool cycle = false;

        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast == slow) {
                cycle = true;
                break;
            }
        }
        if(!cycle) return 0;
        
        int cnt = 1;
        while(slow -> next != fast) {
            slow = slow -> next;
            cnt++;
        }
        return cnt;
    }
};