// https://leetcode.com/problems/merge-k-sorted-lists/description/

using namespace std;
#include <bits/stdc++.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 class compare {
    public:
      bool operator()(ListNode *a, ListNode *b) { return a -> val > b -> val; }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();

        for(int i = 0; i < k; i++) {
            if(lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();

            if(top -> next) {
                minHeap.push(top -> next);
            }

            if(head == NULL) // First Node
            {
                head = tail = top;
            }
            else             // Insert at tail
            {
                tail -> next = top;
                tail = tail -> next;   // tail = top;
            }
        }

        return head;
    }
};