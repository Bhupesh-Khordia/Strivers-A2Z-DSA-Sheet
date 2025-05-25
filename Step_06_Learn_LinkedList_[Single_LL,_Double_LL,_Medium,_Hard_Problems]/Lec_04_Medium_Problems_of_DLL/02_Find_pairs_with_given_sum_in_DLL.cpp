#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  private:
    Node* tail(Node* head) {
        if(!head || !head -> next) return head;
        Node* prev = head;
        while(head) {
            prev = head;
            head = head -> next;
        }
        return prev;
    }
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        if(!head || !head -> next) return {};
        vector<pair<int, int>> ans;
        Node* first = head;
        Node* second = tail(head);
        
        while(first -> data < second -> data) {
            int sum = first -> data + second -> data;
            if(sum == target) {
                ans.push_back({first -> data, second -> data});
                first = first -> next;
                second = second -> prev;
            } else if (sum < target) {
                first = first -> next;
            } else {
                second = second -> prev;
            }
        }
        
        return ans;
    }
};