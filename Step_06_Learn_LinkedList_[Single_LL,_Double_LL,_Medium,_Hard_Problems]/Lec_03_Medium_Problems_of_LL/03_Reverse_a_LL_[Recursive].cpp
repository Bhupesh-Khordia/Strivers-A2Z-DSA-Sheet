#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-linked-list/description/

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
private:
    ListNode* rev(ListNode* prev, ListNode* curr) {
        if(curr == NULL) return prev;

        ListNode* forward = curr -> next;
        curr -> next = prev;
        return rev(curr, forward);
    }
public:
    ListNode* reverseList(ListNode* head) {
        // Iterative

        /*
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;

        ListNode* prev = head;
        ListNode* curr = head -> next;
        prev -> next = NULL;

        while(curr != NULL) {
            ListNode* temp  = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
        */

        // Recursive

        /*
        if(head == NULL || head -> next == NULL) return head;

        ListNode* chotaHead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return chotaHead;
        */


        // Another Recursive

        if(head == NULL) return head;
        ListNode* curr = head -> next;
        head -> next = NULL;
        return rev(head, curr);
    }
};