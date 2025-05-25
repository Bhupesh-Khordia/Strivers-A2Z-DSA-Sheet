#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !(head -> next)) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast -> next && fast -> next -> next && fast -> next -> next-> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* delNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete delNode;
        return head;
    }
};