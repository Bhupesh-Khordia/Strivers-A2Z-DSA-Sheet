#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-list/description/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next) return head;
        int length = 0;
        ListNode* curr = head;
        while(curr) {
            length++;
            curr = curr -> next;
        }

        k = k % length;
        if(!k) return head;

        curr = head;
        ListNode* next = curr -> next;
        for(int i = 0; i < (length - k - 1); i++) {
            curr = curr -> next;
            next = curr -> next;
        }
        curr -> next = nullptr;
        
        ListNode* nextCpy = next;
        while(nextCpy -> next) {
            nextCpy = nextCpy -> next;
        }
        nextCpy -> next = head;

        return next;
    }
};