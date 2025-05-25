#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < n; i++) {
            fast = fast -> next;
        }
        // if n == lenght of LL
        if(fast == NULL)  {
            slow = slow -> next;
            delete head;
            return slow;
        }
        while(fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode* delNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete delNode;
        return head;
    }
};